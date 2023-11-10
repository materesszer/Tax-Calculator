#include "../include/bracketInputHandler.h"
#include "../include/mainwindow.h"

#include "../ui/ui_mainwindow.h"

std::array<int, MAX_BRACKETS> bracketInputHandler::getBracketLimits(MainWindow* mainWindow)
{
    QGridLayout* gridLayout = mainWindow->findChild<QGridLayout*>("gridLayout");
    std::array<int, MAX_BRACKETS> returnArray;

    for (int i = 1; i <= MAX_BRACKETS; ++i) {
        QString limName = QString("Br%1Lim").arg(i);

        QLineEdit* limLineEdit = mainWindow->findChild<QLineEdit*>(limName);

        if (limLineEdit->isEnabled()) {
            returnArray[i-1] = limLineEdit->text().toInt();
        }
    }
    return returnArray;
}

std::array<int, MAX_BRACKETS> bracketInputHandler::getBracketPercentages(MainWindow* mainWindow)
{
    QGridLayout* gridLayout = mainWindow->findChild<QGridLayout*>("gridLayout");
    std::array<int, MAX_BRACKETS> returnArray;
    for (int i = 1; i <= MAX_BRACKETS; ++i) {
        QString percName = QString("Br%1Perc").arg(i);

        QSpinBox* percLineEdit = mainWindow->findChild<QSpinBox*>(percName);

        if (percLineEdit->isEnabled()) {
            returnArray[i-1] = percLineEdit->text().toInt();
        }
    }
    return returnArray;
}
