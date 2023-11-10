#include "../include/inputHandling.h"
#include <iostream>
#include <vector>




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
    bool isBracketLimitsValid = validator.bracketLimitsValidator(bracketLimits, bracketAmount);
    bool isBracketPercentagesValid = validator.bracketPercentagesValidator(bracketPercentages, bracketAmount);

    // Very important, this only allows calculator to proceed if all conditions passed the check
    std::vector<bool> bools = {isIncomeValid, isDeductionsValid, isBracketLimitsValid, isBracketPercentagesValid};
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

bool ProgressiveTaxInputsImplementation::bracketLimitsValidator(std::array<int, MAX_BRACKETS> bracketLimits, int bracketAmount)
{
    int previousLimit = 0;
    for (int i = 0; i < bracketAmount - 1; i++)
    {
        if (bracketLimits[i] < previousLimit)
        {
            return false;
        }
        previousLimit = bracketLimits[i];
    }
    return true;

}

bool ProgressiveTaxInputsImplementation::bracketPercentagesValidator(std::array<int, MAX_BRACKETS> bracketPercentages, int bracketAmount)
{
    int previousPerc = 0;
    for (int i = 0; i < bracketAmount; i++)
    {
        if (bracketPercentages[i] < previousPerc || (bracketPercentages[i] < MIN_TAX || bracketPercentages[i] > MAX_TAX))
        {
            return false;
        }
        previousPerc = bracketPercentages[i];
    }
    return true;
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

