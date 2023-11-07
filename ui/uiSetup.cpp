

#include "../include/uiSetup.h"
#include "../include/mainwindow.h" // Include the mainwindow.h file
#include "ui/ui_mainwindow.h"

void UiSetup::setupWindow(MainWindow* mainWindow)
{
    mainWindow->ui->setupUi(mainWindow);
    mainWindow->ui->deductionAmount->setVisible(false);
    mainWindow->ui->singleTaxButton->setChecked(true);
    mainWindow->ui->results_2->setHidden(true);
    mainWindow->ui->results_3->setHidden(true);
}

void UiSetup::setupSingleTax(MainWindow* mainWindow, bool checked)
{
    mainWindow->ui->singleTax_2Page1->setVisible(true);
    mainWindow->ui->singleTax_2Page2->setHidden(true);
    mainWindow->ui->bracketCount_2->setHidden(true);
}

void UiSetup::setupProgressiveTax(MainWindow* mainWindow, bool checked)
{
    mainWindow->ui->singleTax_2Page2->setVisible(true);
    mainWindow->ui->singleTax_2Page1->setHidden(true);
    mainWindow->ui->bracketCount_2->setVisible(true);

    mainWindow->ui->Br3Lim->setEnabled(false);
    mainWindow->ui->Br3Perc->setEnabled(false);

    mainWindow->ui->Br4Lim->setEnabled(false);
    mainWindow->ui->Br4Perc->setEnabled(false);

    mainWindow->ui->Br5Lim->setEnabled(false);
    mainWindow->ui->Br5Perc->setEnabled(false);
}
