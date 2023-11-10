#include "../include/bracketStateHandler.h"
#include "../include/mainwindow.h"

#include "ui/ui_mainwindow.h"


void bracketStateHandler::enableTaxBrackets(MainWindow* mainWindow,int userInput) {
    QGridLayout* gridLayout = mainWindow->findChild<QGridLayout*>("gridLayout");
    if (!gridLayout)
        return;

    for (int i = MIN_BRACKETS; i <= userInput; ++i) {
        QString limName = QString("Br%1Lim").arg(i);
        QString percName = QString("Br%1Perc").arg(i);

        QLineEdit* limLineEdit = mainWindow->findChild<QLineEdit*>(limName);
        QSpinBox* percLineEdit = mainWindow->findChild<QSpinBox*>(percName);

        if (limLineEdit && percLineEdit) {
            limLineEdit->setEnabled(true);
            percLineEdit->setEnabled(true);
        }
    }
}

void bracketStateHandler::disableRestOfBrackets(MainWindow* mainWindow,int userInput)
{
    QGridLayout* gridLayout = mainWindow->findChild<QGridLayout*>("gridLayout");
    if (!gridLayout)
        return;

    for (int i = userInput + 1; i <= MAX_BRACKETS; i++)
    {
        QString limName = QString("Br%1Lim").arg(i);
        QString percName = QString("Br%1Perc").arg(i);

        QLineEdit* limLineEdit = mainWindow->findChild<QLineEdit*>(limName);
        QSpinBox* percLineEdit = mainWindow->findChild<QSpinBox*>(percName);

        if (limLineEdit && percLineEdit) {
            limLineEdit->setEnabled(false);
            percLineEdit->setEnabled(false);
        }
    }
}

void bracketStateHandler::disableLastBracketLimit(MainWindow* mainWindow, int userInput)
{
    QGridLayout* gridLayout = mainWindow->findChild<QGridLayout*>("gridLayout");
    if (!gridLayout)
        return;

    QString limName = QString("Br%1Lim").arg(userInput);

    QLineEdit* limLineEdit = mainWindow->findChild<QLineEdit*>(limName);

    if (limLineEdit)
    {
        limLineEdit->setEnabled(false);
    }

}
