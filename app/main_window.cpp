#include "main_window.h"
#include "ui_main_window.h"
#include "appcontext.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMainWindow::showMaximized();

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    AppContext::scene = scene;
    AppContext::guiBlocker = new GuiBlocker(ui);

    listDecorator = new ListDecorator();
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
    int position = ui->erasePositionField->value();
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
