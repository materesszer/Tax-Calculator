#ifndef USERINPUTWARNINGS_H
#define USERINPUTWARNINGS_H

#include <QMainWindow>

class MainWindow;

class userInputWarnings
{
public:
    static void showDeductionWarning(MainWindow* mainWindow, QWidget *parent, int value);
};


#endif // USERINPUTWARNINGS_H
