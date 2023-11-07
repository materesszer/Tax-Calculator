#include "include/mainwindow.h"
#include "ui/ui_mainwindow.h"
#include "include/inputHandling.h"
#include "include/taxCalculator.h"

const int DEFAULTBRACKETSNUMBER = 2;

// SETUP FOR WINDOW
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


    ui->Br3Lim->setEnabled(false);
    ui->Br3Perc->setEnabled(false);

    ui->Br4Lim->setEnabled(false);
    ui->Br4Perc->setEnabled(false);

    ui->Br5Lim->setEnabled(false);
    ui->Br5Perc->setEnabled(false);



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
    std::array<int, MAX_BRACKETS> bracketLimits = MainWindow::getBracketLimits();
    std::array<int, MAX_BRACKETS> bracketPercentages = MainWindow::getBracketPercentages();


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


void MainWindow::on_bracketAmount_valueChanged(int value)
{
    MainWindow::enableTaxBrackets(value);
    MainWindow::disableRestOfBrackets(value);
    MainWindow::disableLastBracketLimit(value);

}



void MainWindow::enableTaxBrackets(int userInput) {
    QGridLayout* gridLayout = findChild<QGridLayout*>("gridLayout");
    if (!gridLayout)
        return;

    for (int i = MIN_BRACKETS; i <= userInput; ++i) {
        QString limName = QString("Br%1Lim").arg(i);
        QString percName = QString("Br%1Perc").arg(i);

        QLineEdit* limLineEdit = findChild<QLineEdit*>(limName);
        QLineEdit* percLineEdit = findChild<QLineEdit*>(percName);

        if (limLineEdit && percLineEdit) {
            limLineEdit->setEnabled(true);
            percLineEdit->setEnabled(true);
        }
    }
}

void MainWindow::disableRestOfBrackets(int userInput)
{
    QGridLayout* gridLayout = findChild<QGridLayout*>("gridLayout");
    if (!gridLayout)
        return;

    for (int i = userInput + 1; i <= MAX_BRACKETS; i++)
    {
        QString limName = QString("Br%1Lim").arg(i);
        QString percName = QString("Br%1Perc").arg(i);

        QLineEdit* limLineEdit = findChild<QLineEdit*>(limName);
        QLineEdit* percLineEdit = findChild<QLineEdit*>(percName);

        if (limLineEdit && percLineEdit) {
            limLineEdit->setEnabled(false);
            percLineEdit->setEnabled(false);
        }
    }
}

void MainWindow::disableLastBracketLimit(int userInput)
{
    QGridLayout* gridLayout = findChild<QGridLayout*>("gridLayout");
    if (!gridLayout)
        return;

    QString limName = QString("Br%1Lim").arg(userInput);

    QLineEdit* limLineEdit = findChild<QLineEdit*>(limName);

    if (limLineEdit)
    {
        limLineEdit->setEnabled(false);
    }

}



std::array<int, MAX_BRACKETS> MainWindow::getBracketLimits()
{
    QGridLayout* gridLayout = MainWindow::findChild<QGridLayout*>("gridLayout");
    std::array<int, MAX_BRACKETS> returnArray;

    for (int i = 1; i <= MAX_BRACKETS; ++i) {
        QString limName = QString("Br%1Lim").arg(i);

        QLineEdit* limLineEdit = MainWindow::findChild<QLineEdit*>(limName);

        if (limLineEdit->isEnabled()) {
            returnArray[i-1] = limLineEdit->text().toInt();
        }
    }
    return returnArray;
}

std::array<int, MAX_BRACKETS> MainWindow::getBracketPercentages()
{
    QGridLayout* gridLayout = MainWindow::findChild<QGridLayout*>("gridLayout");
    std::array<int, MAX_BRACKETS> returnArray;
    for (int i = 1; i <= MAX_BRACKETS; ++i) {
        QString percName = QString("Br%1Perc").arg(i);

        QLineEdit* percLineEdit = MainWindow::findChild<QLineEdit*>(percName);

        if (percLineEdit->isEnabled()) {
            returnArray[i-1] = percLineEdit->text().toInt();
        }
    }
    return returnArray;
}


