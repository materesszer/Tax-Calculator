#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->deductionAmount->setVisible(false);

    ui->singleTaxButton->setChecked(true);

    ui->results_2->setHidden(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_singleTaxButton_toggled(bool checked)
{
    ui->singleTax_2Page1->setVisible(true);
    ui->singleTax_2Page2->setHidden(true);
}



void MainWindow::on_progressiveTaxButton_toggled(bool checked)
{
    ui->singleTax_2Page2->setVisible(true);
    ui->singleTax_2Page1->setHidden(true);
}

