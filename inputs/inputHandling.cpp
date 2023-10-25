#include "inputHandling.h"
#include <iostream>
#include <vector>
#include <functional>

const int MIN_DOLLARS = 1;
const int MIN_BRACKETS = 2;
const int MAX_BRACKETS = 10;
const int MIN_TAX = 1;
const int MAX_TAX = 100;

bool SingleTaxInputs::validateInputs()
{
    SingleTaxInputsImplementation validator;
    bool isIncomeValid = validator.incomeValidator(income);
    bool isDeductionsValid = validator.deductionsValidator(deductions, income);
    bool isTaxRateValid = validator.taxRateValidator(taxRate);

    std::vector<bool> bools = {isIncomeValid, isDeductionsValid, isTaxRateValid};
    return validateBools(bools);

}
bool SingleTaxInputsImplementation::incomeValidator(int income)
{
    return income >= MIN_DOLLARS;
}

bool SingleTaxInputsImplementation::deductionsValidator(int deductions, int income)
{
    return deductions >= MIN_DOLLARS && deductions < income;
}

bool SingleTaxInputsImplementation::taxRateValidator(int taxRate)
{
    return taxRate >= MIN_TAX && taxRate <= MAX_TAX;
}




bool validateBools(const std::vector<bool>& bools)
{
    for (bool b : bools)
    {
        if (!b)
        {
            return false;
        }
    }
    return true;

}



