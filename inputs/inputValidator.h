#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>
#include <functional>
#include <iostream>

template <typename T>
T inputValidator(const std::string& message, const std::string& errorMsg, const std::function<bool(T)>& isValid)
{
    T userInput;
    do
    {
        std::cout << message;
        std::cin >> userInput;
        if (!isValid(userInput))
        {
            std::cerr << errorMsg << std::endl;
        }
    }
    while(!isValid(userInput));
    return userInput;
}

#endif