#include "taxCalculator.h"

double ProgressiveTaxCalculator::calculateTax(int income, int deductions, int *brackets, int *bracket_limits, int bracket_count)
{
    double taxable_income = (double)income - deductions;
    double income_after_taxes = (double)income;
    double bracket_tax;
    for (int i = 0, size = bracket_count + 1;i < size; i++)
    {   
        bracket_tax = 0;
        double current_bracket = brackets[i];
        double current_bracket_limit = bracket_limits[i];
        double previous_bracket_limit = bracket_limits[i - 1];
        if (i == 0)
        {
            bracket_tax = (double)(current_bracket_limit * (current_bracket / 100));
        }
        else if (i == size - 1)
        {
            bracket_tax = (double)(taxable_income - previous_bracket_limit) * (current_bracket / 100);
        }
        else
        {
            bracket_tax = (double)(current_bracket_limit - previous_bracket_limit) * (current_bracket / 100);
        }

        income_after_taxes = income_after_taxes - bracket_tax;
    }

    return income_after_taxes;

}

double FlatTaxCalculator::calculateTax(int income, int deductions, int rate)
{
    double taxable_income = income - deductions;

    double income_after_taxes = taxable_income - (taxable_income * ((double)rate / 100)) + deductions;
    return income_after_taxes;
}