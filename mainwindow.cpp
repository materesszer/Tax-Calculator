#include "ui/ui_mainwindow.h"

#include "include/mainwindow.h"
#include "include/taxCalculator.h"
#include "include/uiSetup.h"
#include "include/userInputWarnings.h"
#include "include/bracketStateHandler.h"
#include "include/bracketInputHandler.h"

#include <QMessageBox>

const int DEFAULTBRACKETSNUMBER = 2;

// SETUP FOR WINDOW
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    UiSetup::setupWindow(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_singleTaxButton_toggled(bool checked)
{
    UiSetup::setupSingleTax(this, checked);
}

void MainWindow::on_progressiveTaxButton_toggled(bool checked)
{
    UiSetup::setupProgressiveTax(this,checked);
}
// END SETUP


// Single tax
void MainWindow::on_calculateButton_clicked()
{
    int income = ui->incomeAmount->text().toInt();
    int deductions = ui->deductionAmount->text().toInt();
    int taxRate = ui->value->text().toInt();

    // Workaround for disabled deductions, pair of this reverts it to 0 after validity check
    if (!ui->deductionIsEnabled->isChecked())
    {
        deductions = 1;
    }

    SingleTaxInputs inputHandler(income, deductions, taxRate);
    bool isValid = inputHandler.validateInputs();

    // Workaround pair
    if (!ui->deductionIsEnabled->isChecked())
    {
        deductions = 0;
    }

    if (isValid)
    {
        ui->results_2->setVisible(true);
        FlatTaxCalculator flatTaxCalc;
        int incomeAfterTaxes = flatTaxCalc.calculateTax(income, deductions, taxRate);

        ui->afterTaxesVal->setText(QString::number(incomeAfterTaxes));
        ui->totalTaxesVal->setText(QString::number(income - incomeAfterTaxes));
        ui->effRateVal->setText(QString::number((income - incomeAfterTaxes) / (double)income * 100) + "%");
    }
    else
    {
        ui->results_2->setHidden(true);
    }


}

// Progressive tax
void MainWindow::on_calculateProgButton_clicked()
{
    int income = ui->incomeAmount->text().toInt();
    int deductions = ui->deductionAmount->text().toInt();
    int bracketAmount = ui->bracketAmount->text().toInt();
    std::array<int, MAX_BRACKETS> bracketLimits = bracketInputHandler::getBracketLimits(this);
    std::array<int, MAX_BRACKETS> bracketPercentages = bracketInputHandler::getBracketPercentages(this);


    // Workaround for disabled deductions, pair of this reverts it to 0 after validity check
    if (!ui->deductionIsEnabled->isChecked())
    {
        deductions = 1;
    }

    ProgressiveTaxInputs inputHandler(income, deductions, bracketPercentages, bracketLimits, bracketAmount);
    bool isValid = inputHandler.validateInputs();

    // Workaround pair
    if (!ui->deductionIsEnabled->isChecked())
    {
        deductions = 0;
    }

    if (isValid)
    {
        ui->results_3->setVisible(true);
        ProgressiveTaxCalculator progTaxCalc;
        int incomeAfterTaxes = progTaxCalc.calculateTax(income, deductions, bracketPercentages, bracketLimits, bracketAmount);

        ui->afterTaxesVal_3->setText(QString::number(incomeAfterTaxes));
        ui->totalTaxesVal_3->setText(QString::number(income - incomeAfterTaxes));
        ui->effRateVal_3->setText(QString::number((income - incomeAfterTaxes) / (double)income * 100) + "%");
    }
    else
    {
        ui->results_3->setHidden(true);
    }
}

// Dynamically enables bracket limits and percentages depending on user input
void MainWindow::on_bracketAmount_valueChanged(int value)
{
    bracketStateHandler::enableTaxBrackets(this, value);
    bracketStateHandler::disableRestOfBrackets(this, value);
    bracketStateHandler::disableLastBracketLimit(this, value);

}

void MainWindow::on_deductionAmount_valueChanged(int value)
{
    userInputWarnings::showDeductionWarning(this, this, value);
}
