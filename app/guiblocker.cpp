#include "guiblocker.h"

void GuiBlocker::disableAll()
{
    ui->clearButton->setDisabled(true);
    ui->insertButton->setDisabled(true);
    ui->pushBackButton->setDisabled(true);
    ui->eraseButton->setDisabled(true);
    ui->redoButton->setDisabled(true);
    ui->undoButton->setDisabled(true);
}

void GuiBlocker::enableAll()
{
    ui->clearButton->setEnabled(true);
    ui->insertButton->setEnabled(true);
    ui->pushBackButton->setEnabled(true);
    ui->eraseButton->setEnabled(true);
    ui->redoButton->setEnabled(true);
    ui->undoButton->setEnabled(true);
}
