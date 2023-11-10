#include "../include/userInputWarnings.h"
#include "../include/mainwindow.h"
#include "ui/ui_mainwindow.h"
#include <QMessageBox>


void userInputWarnings::showDeductionWarning(MainWindow* mainWindow, QWidget *parent, int value)
{
    int income = mainWindow->ui->incomeAmount->text().toInt();
    if (value > income && !mainWindow->ERROR_SHOWN)
    {
        mainWindow->ui->deductionAmount->setStyleSheet("QSpinBox { border: 2px solid red; }");
        QString errorMessage = QString("Deductions cannot be larger than income! Lower deductions to at least %1 !").arg(income);
        QMessageBox::warning(parent, "Error", errorMessage);

        mainWindow->ERROR_SHOWN = true;

    }
    else if (value < income)
    {
        mainWindow->ui->deductionAmount->setStyleSheet("");
        mainWindow->ERROR_SHOWN = false;
    }
}
