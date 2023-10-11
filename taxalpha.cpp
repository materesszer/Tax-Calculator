#include <iostream>

int income(void);
char method(void);
bool hasDeduction();
int deductions();
void get_brackets(int &array, char taxmethod);

const int MAX_BRACKETS = 10;

int main()
{
    int your_income = income();
    char tax_method = method();
    int your_deductions = deductions();
    int brackets[MAX_BRACKETS];
    get_brackets(*brackets, tax_method);
}

// Asks user for monthly income, stores value in income
int income(void)
{
    try
    {
        std::cout << "What is your monthly income? ";
        int income;
        std::cin >> income;
        if (income < 1)
        {
            throw std::invalid_argument("Income must be at least $1");
        }
        return income;
    }

    catch (const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return income();
    }
}

// Asks user whether he is taxed progressively or flat
char method(void)
{
    try
    {
        std::cout << "Type p for progressive, f for flat tax method ";
        char method;
        std::cin >> method;
        method = tolower(method);

        if (method != 'f' && method != 'p')
        {
            throw std::invalid_argument("Method must be 'p' for progressive taxation, or 'f' for flat taxation");
        }
        return method;

    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return method();
    }
    
}

// Asks user whether he has deductions
bool hasDeduction()
{
    try
    {
        std::cout << "Do you have deductions? ('y' for yes, 'n' for no)";
        char answer;
        std::cin >> answer;
        answer = tolower(answer);

        if (answer != 'y' && answer != 'n')
        {
            throw std::invalid_argument("Answer must be either 'y' or 'n'");
        }
        if (answer == 'y')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
        return hasDeduction();
    }
    
}

int deductions()
{
    bool answer = hasDeduction();
    int user_deductions;
    if (answer)
    {
        try
        {
            std::cout << "What are your total deductions? ";
            std::cin >> user_deductions;
            if (user_deductions< 1)
            {
                throw std::invalid_argument("Deductions must be at least $1");
            }
            return user_deductions;
        }

        catch (const std::invalid_argument& e)
        {
            std::cerr << e.what() << std::endl;
            return deductions();
        }
        }
    else
    {
        user_deductions = 0;
    }
    return user_deductions;
}

void get_brackets(int &array,char taxmethod)
{
    // No need for brackets with flat tax
    if (taxmethod == 'f')
    {
        return;
    }

    // Get amount of brackets
    else
    {
        try
        {
            std::cout << "How many tax brackets are there? (Max 10, Min 2)";
            int brackets;
            std::cin >> brackets;
            if (brackets < 2 || brackets > 10)
            {
                throw std::invalid_argument("Number of brackets must be between 2 and 10");
            }

        }
        catch(const std::invalid_argument& e)
        {
            std::cerr << e.what() << '\n';
            return get_brackets(array,taxmethod);
        }
        
    }

    // Populate brackets
    
}

