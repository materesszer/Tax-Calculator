#include "inputValidator.h"
#include <iostream>


int income(void);
char method(void);
bool hasDeduction();
int deductions(int income);
void get_brackets(int *array, char taxmethod);
void populate_brackets(int *array, int brackets);

const int MIN_BRACKETS = 2;
const int MAX_BRACKETS = 10;

int main()
{
    int your_income = income();
    char tax_method = method();
    int your_deductions = deductions(your_income);
    int brackets[MAX_BRACKETS];
    get_brackets(brackets, tax_method);
    int *ptr = brackets;
    while (*ptr != 0)
    {
        std::cout << *ptr <<std::endl;
        ptr++;
    }
}

int income() {
    return inputValidator<int>(
        "What is your monthly income? ",
        "Income must be at least $1",
        [](int income) { return income >= 1; }
    );
}

char method() {
    return inputValidator<char>(
        "Type p for progressive, f for flat tax method ",
        "Method must be 'p' for progressive taxation, or 'f' for flat taxation",
        [](char method) { return method == 'f' || method == 'p'; }
    );
}

// Asks user whether he has deductions
bool hasDeduction()
{
    char answer = inputValidator<char>(
    "Do you have deductions? ('y' for yes, 'n' for no) ",
    "Answer must be either 'y' or 'n'",
    [](char answer) { return answer== 'y' || answer == 'n'; }
    );
    if (answer == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int deductions(int income)
{
    bool answer = hasDeduction();
    int user_deductions;
    if (answer)
    {
        user_deductions = inputValidator<int>(
        "What are your total deductions? ",
        "Deductions must be at least $1",
        [](int deductions) { return deductions >= 1; });
        if (user_deductions > income)
        {
            std::cout << "Deductions can not be higher than your monthly income!\n";
            return deductions(income);
        }
        else
        {
            return user_deductions;
        }
    
    }
    else
    {
        return user_deductions = 0;
    }
}

void get_brackets(int *array,char taxmethod)
{
    int brackets;
    // No need for brackets with flat tax
    if (taxmethod == 'f')
    {
        return;
    }
    // Progressive tax
    else
    {
        // Get amount of brackets, handle errors
        brackets = inputValidator<int>(
        "How many tax brackets are there? (Max 10, Min 2) ",
        "Number of brackets must be between 2 and 10",
        [](int brackets) { return brackets >= 2 || brackets <= 10; }
        );
        
        // Populate brackets
        populate_brackets(array, brackets);
    }

}

void populate_brackets(int *array, int brackets)
{
    // Populate brackets
        int bracket;
        int previous_bracket = 0;
        for (int i = 0; i < brackets; i++)
        {
            do
            {
                std::cout << "Bracket " + std::to_string(i+1) + ":";
                std::cin >> bracket;
            }
            while (bracket < previous_bracket);
            array[i] = bracket;
            previous_bracket = bracket;
        }
}

