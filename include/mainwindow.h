#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "inputHandling.h"
#include "qlabel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_singleTaxButton_toggled(bool checked);

    void on_progressiveTaxButton_toggled(bool checked);

    void on_calculateButton_clicked();



    void on_bracketAmount_valueChanged(int value);

    void enableTaxBrackets(int userInput);

    void disableRestOfBrackets(int userInput);

    void disableLastBracketLimit(int userInput);

    std::array<int, MAX_BRACKETS> getBracketLimits();
    std::array<int, MAX_BRACKETS> getBracketPercentages();
    void on_calculateProgButton_clicked();

    void on_deductionAmount_valueChanged(int arg1);

public:
    Ui::MainWindow *ui;
    QLabel* errorLabel;
    bool ERROR_SHOWN = false;
};
#endif // MAINWINDOW_H
