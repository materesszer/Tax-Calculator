#ifndef BRACKETSTATEHANDLER_H
#define BRACKETSTATEHANDLER_H

#include <QMainWindow>


class MainWindow;

class bracketStateHandler
{
public:
    static void enableTaxBrackets(MainWindow* mainWindow,int userInput);
    static void disableRestOfBrackets(MainWindow* mainWindow,int userInput);
    static void disableLastBracketLimit(MainWindow* mainWindow, int userInput);
};

#endif // BRACKETSTATEHANDLER_H
