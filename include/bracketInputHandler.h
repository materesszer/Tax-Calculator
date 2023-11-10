#ifndef BRACKETINPUTHANDLER_H
#define BRACKETINPUTHANDLER_H

#include <QMainWindow>
#include "inputHandling.h"


class MainWindow;

class bracketInputHandler
{
public:
    static std::array<int, MAX_BRACKETS> getBracketPercentages(MainWindow* mainWindow);
    static std::array<int, MAX_BRACKETS> getBracketLimits(MainWindow* mainWindow);
};

#endif // BRACKETINPUTHANDLER_H
