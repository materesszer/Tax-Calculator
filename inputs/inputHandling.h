#ifndef INPUTHANDLING_H
#define INPUTHANDLING_H

#include <vector>
#include <functional>

bool validateBools(const std::vector<bool>& bools);

const int MIN_DOLLARS = 1;
const int MIN_TAX = 1;
const int MAX_TAX = 100;
const int MIN_BRACKETS = 2;
const int MAX_BRACKETS = 5;


class SingleTaxInputs
{
    private:
    int income;
    int deductions;
    int taxRate;

    public:
    SingleTaxInputs(int inc, int ded, int txRt)
    {
        income = inc;
        deductions = ded;
        taxRate = txRt;
    }

    bool validateInputs();

};

class SingleTaxInputsImplementation
{
    public:
    bool incomeValidator(int income);
    bool deductionsValidator(int deductions, int income);
    bool taxRateValidator(int taxRate);
};

class ProgressiveTaxInputs
{
    private:
    int income;
    int deductions;
    int bracketPercentages;
    int bracketLimits;

    bool validateInputs();

};
class ProgressiveTaxInputsImplementation
{
    public:
    bool incomeValidator(int income);
    bool deductionsValidator(int deductions, int income);
    bool bracketAmountValidator(int brackets);
};

namespace progressiveTaxBrackets
{
bool bracketAmountValidator(int brackets);
}


#endif // INPUTHANDLING_H
