#include "main_window.h"
#include "ui_main_window.h"
#include "appcontext.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMainWindow::showFullScreen();
    resizeElements(QMainWindow::width(), QMainWindow::height());

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


void MainWindow::on_closeButton_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::resizeElements(int width, int height)
{
    ui->pushBackButton->move(30, 20);
    ui->pushBackField->move(230, 20);

    ui->undoButton->move(30, 200);
    ui->redoButton->move(250, 200);

    ui->clearButton->move(width - 230, 20);
    ui->closeButton->move(width - 230, 200);

    int insertLeftW = width * 0.25;
    ui->insertButton->move(insertLeftW, 20);
    ui->insertValueField->move(insertLeftW + 200, 20);
    ui->insertPositionField->move(insertLeftW + 200, 100);
    ui->valueLabel->move(insertLeftW + 300, 20);
    ui->positionLabel->move(insertLeftW + 300, 100);

    int eraseLeftW = width * 0.6;
    ui->eraseButton->move(eraseLeftW, 20);
    ui->erasePositionField->move(eraseLeftW, 100);
    ui->positionLabel_2->move(eraseLeftW + 100, 100);

    ui->graphicsView->resize(width, height -  330);
    ui->graphicsView->move(0, 300);
}
