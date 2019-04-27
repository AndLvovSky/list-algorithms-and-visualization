#ifndef APPCONTEXT_H
#define APPCONTEXT_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include "guiblocker.h"

class AppContext
{
public:
    static QGraphicsScene * scene;
    static GuiBlocker * guiBlocker;

private:
    AppContext(){}
};

#endif // APPCONTEXT_H
