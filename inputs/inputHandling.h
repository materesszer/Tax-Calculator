#ifndef INPUTHANDLING_H
#define INPUTHANDLING_H

#include <vector>
#include <functional>

bool validateBools(const std::vector<bool>& bools);


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

#endif // INPUTHANDLING_H
