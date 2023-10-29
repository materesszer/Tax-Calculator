#include "inputHandling.h"
#include <iostream>
#include <vector>
#include <functional>



bool SingleTaxInputs::validateInputs()
{
    SingleTaxInputsImplementation validator;
    bool isIncomeValid = validator.incomeValidator(income);
    bool isDeductionsValid = validator.deductionsValidator(deductions, income);
    bool isTaxRateValid = validator.taxRateValidator(taxRate);

    // Very important, this only allows calculator to proceed if all conditions passed the check
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




bool ProgressiveTaxInputs::validateInputs()
{
    ProgressiveTaxInputsImplementation validator;
    bool isIncomeValid = validator.incomeValidator(income);
    bool isDeductionsValid = validator.deductionsValidator(deductions, income);

    // Very important, this only allows calculator to proceed if all conditions passed the check
    std::vector<bool> bools = {isIncomeValid, isDeductionsValid};
    return validateBools(bools);

}

bool ProgressiveTaxInputsImplementation::incomeValidator(int income)
{
    return income >= MIN_DOLLARS;
}

bool ProgressiveTaxInputsImplementation::deductionsValidator(int deductions, int income)
{
    return deductions >= MIN_DOLLARS && deductions < income;
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

namespace progressiveTaxBrackets
{
bool bracketAmountValidator(int brackets)
{
    return brackets >= MIN_BRACKETS && brackets <= MAX_BRACKETS;
}
}


