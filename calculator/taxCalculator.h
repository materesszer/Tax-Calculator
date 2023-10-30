#ifndef TAXCALCULATOR_H
#define TAXCALCULATOR_H

#include <array>
#include "../inputs/inputHandling.h"

class ProgressiveTaxCalculator
{
    public:
    double calculateTax(int income, int deductions, std::array<int, MAX_BRACKETS> brackets, std::array<int, MAX_BRACKETS> bracket_limits, int bracket_count);
};
class FlatTaxCalculator
{
    public:
    double calculateTax(int income, int deductions, int rate);

};




#endif //TAXCALCULATOR_H
