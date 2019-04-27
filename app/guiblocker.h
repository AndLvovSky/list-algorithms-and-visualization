#ifndef GUIBLOCKER_H
#define GUIBLOCKER_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <ui_main_window.h>

class GuiBlocker
{
private:
    Ui::MainWindow *ui;

public:
    GuiBlocker(Ui::MainWindow * ui) : ui(ui) {};
    void disableAll();
    void enableAll();
};

#endif // GUIBLOCKER_H
