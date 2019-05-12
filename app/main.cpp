#include "main_window.h"
#include <QApplication>
#include "resizefilter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ResizeFilter filter;

    MainWindow window;
    window.installEventFilter(&filter);
    window.showMaximized();

    return a.exec();
}
