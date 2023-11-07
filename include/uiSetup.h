
#ifndef UISETUP_H
#define UISETUP_H

#include <QMainWindow>

class MainWindow;

class UiSetup
{
public:
    static void setupWindow(MainWindow* mainWindow);
    static void setupSingleTax(MainWindow* mainWindow, bool checked);
    static void setupProgressiveTax(MainWindow* mainWindow, bool checked);
};

#endif // UISETUP_H
