#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "inputs/inputHandling.h"
#include "calculator/taxCalculator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->deductionAmount->setVisible(false);

    ui->singleTaxButton->setChecked(true);

    ui->results_2->setHidden(true);

    ui->results_3->setHidden(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_singleTaxButton_toggled(bool checked)
{
    ui->singleTax_2Page1->setVisible(true);
    ui->singleTax_2Page2->setHidden(true);

    ui->bracketCount_2->setHidden(true);
}



void MainWindow::on_progressiveTaxButton_toggled(bool checked)
{
    ui->singleTax_2Page2->setVisible(true);
    ui->singleTax_2Page1->setHidden(true);

    ui->bracketCount_2->setVisible(true);
}



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

