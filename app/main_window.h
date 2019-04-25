#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <list/container/doubly_linked_list/doubly_linked_list.h>
#include <list/container/doubly_linked_list/doubly_linked_list_abstract_iterator.h>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include "listdecorator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushBackButton_clicked();

    void on_insertButton_clicked();

    void on_clearButton_clicked();

    void on_eraseButton_clicked();

    void on_undoButton_clicked();

    void on_redoButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene * scene;

private:
    ListDecorator *listDecorator;
};

#endif // MAIN_WINDOW_H
