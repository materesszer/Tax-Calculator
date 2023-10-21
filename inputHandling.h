#ifndef INPUTHANDLING_H
#define INPUTHANDLING_H

class InputHandler
{
    public:
    int income(void);
    char method(void);
};
class Deductions
{
    public:
    bool hasDeduction();
    int deductions(int income);
};
class Brackets
{
    public:
    int get_brackets(int *array, char taxmethod);
    void populate_brackets(int *array, int brackets);
};
class SingleTax
{
    public:
    int single_tax();
};
class BracketLimits
{
    public:
    void get_bracket_limits(int *array, int brackets, int income);
};

#endif // INPUTHANDLING_H
