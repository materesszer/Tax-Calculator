#include <iostream>

int income(void);
char method(void);

int main()
{
    int your_income = income();
    char tax_method = method();

    std::cout << your_income << std::endl;
    std::cout << tax_method << std::endl;
}

// Asks user for monthly income, stores value in income
int income(void)
{
    std::cout << "What is your monthly income? ";
    int income;
    std::cin >> income;
    return income;
}

// Asks user whether he is taxed progressively or flat
char method(void)
{
    std::cout << "Type p for progressive, f for flat tax method ";
    char method;
    std::cin >> method;
    method = tolower(method);
    return method;
}

