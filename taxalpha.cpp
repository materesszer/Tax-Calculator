#include "inputHandling.h"
#include "taxCalculator.h"

#include <iostream>
#include <iomanip>

const int MIN_BRACKETS = 2;
const int MAX_BRACKETS = 10;

void printResults(int income, int income_after_taxes);

int main()
{
    // User inputs
    InputHandler user_inputs;
    int your_income = user_inputs.income();
    char tax_method = user_inputs.method();

    // Deductions
    Deductions user_deductions;
    int your_deductions = user_deductions.deductions(your_income);

    double income_after_taxes;
    if (tax_method == 'f')
    {
        // SINGLE TAX METHOD INPUTS
        SingleTax flat;
        int single_rate = flat.single_tax();

        // SINGLE TAX METHOD CALCULATION
        FlatTaxCalculator calculation;
        income_after_taxes = calculation.calculateTax(your_income, your_deductions, single_rate);
    }
    else
    {
        // PROGRESSIVE TAX METHOD INPUTS
        // Brackets for progressive tax
        Brackets user_brackets;
        int brackets[MAX_BRACKETS];
        int brackets_count = user_brackets.get_brackets(brackets, tax_method);

        std::cout <<"NOTE: TOOL ASKS FOR BRAKCET LIMITS LESS THAN OF PREVIOUS INPUT, AS LAST BRACKET HAS NO UPPER BOUND" <<std::endl;

        // Limits for the brackets
        BracketLimits user_bracket_limits;
        int bracket_limits[MAX_BRACKETS];
        user_bracket_limits.get_bracket_limits(bracket_limits, brackets_count, your_income);

        // PROGRESSIVE TAX CALCULATION
        ProgressiveTaxCalculator calculation;
        income_after_taxes = calculation.calculateTax(your_income, your_deductions, brackets, bracket_limits, brackets_count);
    }   
    
    std::cout << "\n";

    printResults(your_income, income_after_taxes);


}

void printResults(int income, int income_after_taxes)
{
    // Print user income before and after taxes, total amount of taxes, rax rate
    std::cout << "Your income before taxes is: $";
    std::cout << income <<std::endl;

    std::cout << "Your income after taxes is: $";
    std::cout << income_after_taxes <<std::endl;

    double taxes_total = income - income_after_taxes;
    std::cout << "Your total amount of taxes is: $";
    std::cout << taxes_total <<std::endl;

    std::cout << "Your effective tax rate is: ";
    double effective_rate = (taxes_total / income) * 100;
    std::cout << std::fixed << std::setprecision(2) << effective_rate;
    std::cout << "%" <<std::endl;
}
