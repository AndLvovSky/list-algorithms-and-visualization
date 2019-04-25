#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    listDecorator = new ListDecorator(scene);

    // initial list (for test purposes)
    int q = 1;
    for (int i = 0; i < 6; i++) {
        listDecorator->push_back(q);
        q*=10;
    }
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushBackButton_clicked()
{
    int value = ui->pushBackField->value();
    listDecorator->push_back(value);
}

void MainWindow::on_insertButton_clicked()
{
    int value = ui->insertValueField->value();
    int position = ui->insertPositionField->value();
    listDecorator->insert(value, position);
}

void MainWindow::on_clearButton_clicked()
{
    listDecorator->clear();
}

void MainWindow::on_eraseButton_clicked()
{
    int position = ui->insertPositionField->value();
    listDecorator->erase(position);
}

void MainWindow::on_undoButton_clicked()
{
    listDecorator->undo();
}

void MainWindow::on_redoButton_clicked()
{
    listDecorator->redo();
}
