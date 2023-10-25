#ifndef TAXCALCULATOR_H
#define TAXCALCULATOR_H

class ProgressiveTaxCalculator
{
    public:
    double calculateTax(int income, int deductions, int *brackets, int *bracket_limits, int bracket_count);
};
class FlatTaxCalculator
{
    public:
    double calculateTax(int income, int deductions, int rate);

};




#endif //TAXCALCULATOR_H
