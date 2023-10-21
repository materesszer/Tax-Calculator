#include "inputValidator.h"
#include "inputHandling.h"
#include <iostream>

const int MIN_DOLLARS = 1;
const int MIN_BRACKETS = 2;
const int MAX_BRACKETS = 10;
const int MIN_TAX = 1;
const int MAX_TAX = 100;

//class InputHandler

int InputHandler::income() {
return inputValidator<int>(
    "What is your monthly income? $",
    "Income must be at least $1",
    [](int income) { return income >= MIN_DOLLARS; }
);
}

char InputHandler::method() {
    return inputValidator<char>(
        "Type p for progressive, f for flat tax method ",
        "Method must be 'p' for progressive taxation, or 'f' for flat taxation",
        [](char method) { return method == 'f' || method == 'p'; }
    );
}
//class Deductions

    // Asks user whether he has deductions
    bool Deductions::hasDeduction()
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

    int Deductions::deductions(int income)
    {
        bool answer = hasDeduction();
        int user_deductions;
        if (answer)
        {
            user_deductions = inputValidator<int>(
            "What are your total deductions? $",
            "Deductions must be at least $1",
            [](int deductions) { return deductions >= MIN_DOLLARS; });
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

//class Brackets
    int Brackets::get_brackets(int *array,char taxmethod)
    {
    int brackets;
    // No need for brackets with flat tax
    if (taxmethod == 'f')
    {
        return 1;
    }
    // Progressive tax
    else
    {
        // Get amount of brackets, handle errors
        brackets = inputValidator<int>(
        "How many tax brackets are there? (Max 10, Min 2) ",
        "Number of brackets must be between 2 and 10",
        [](int brackets) { return brackets >= MIN_BRACKETS && brackets <= MAX_BRACKETS; }
        ) - 1;
        
        // Populate brackets
        populate_brackets(array, brackets);
        return brackets;
    }

}

void Brackets::populate_brackets(int *array, int brackets)
{
    // Populate brackets
        int bracket;
        int previous_bracket = 0;
        for (int i = 0; i < brackets + 1; i++)
        {
            do
            {
                bracket =inputValidator<int>(
                "Bracket " + std::to_string(i+1) + " percentage:",
                "Bracket must be larger than 1 and lower than 100 %",
                [](int bracket) { return bracket >= MIN_TAX && bracket <=MAX_TAX; }
                );
                if (bracket <= previous_bracket)
                {
                    std::cout << "Bracket must be larger than previous bracket" << std::endl;
                }
            }
            while (bracket <= previous_bracket);
            array[i] = bracket;
            previous_bracket = bracket;
        }
}

int SingleTax::single_tax()
{
    return inputValidator<int>(
        "What is your tax rate? ",
        "Tax rate must be between 1 and 100 percent",
        [](int rate) { return rate >= MIN_TAX && rate <= MAX_TAX; }
    );
}

void BracketLimits::get_bracket_limits(int *array, int brackets, int income)
{
    // Populate brackets
        int bracket;
        int previous_bracket = 0;
        for (int i = 0; i < brackets; i++)
        {
            do
            {
                bracket =inputValidator<int>(
                "Bracket " + std::to_string(i+1) + " limit: $",
                "Bracket must be higher than 0",
                [](int bracket) { return bracket >= 0; }
                );
                if (bracket > income)
                {
                    std::cout << "Bracket must be lower or equal to income" << std::endl;
                }
                if (bracket <= previous_bracket)
                {
                    std::cout << "Bracket must be larger than previous bracket" << std::endl;
                }
            }
            while (bracket <= previous_bracket || bracket > income);
            array[i] = bracket;
            previous_bracket = bracket;
        }
}



