#include "inputHandling.h"
#include <iostream>
#include <vector>

const int MIN_DOLLARS = 1;
const int MIN_BRACKETS = 2;
const int MAX_BRACKETS = 10;
const int MIN_TAX = 1;
const int MAX_TAX = 100;

bool SingleTaxInputs::validateInputs()
{
    SingleTaxInputsImplementation validator;
    bool isIncomeValid = validator.incomeValidator(income);
    bool isDeductionsValid = validator.deductionsValidator(deductions);
    bool isTaxRateValid = validator.taxRateValidator(taxRate);

    std::vector<bool> bools = {isIncomeValid, isDeductionsValid, isTaxRateValid};
    bool result = validateBools(bools);
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

