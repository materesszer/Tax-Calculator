#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->deductionAmount->setVisible(false);

    ui->singleTaxButton->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

