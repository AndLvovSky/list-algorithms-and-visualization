#ifndef LISTITEM_H
#define LISTITEM_H

#include <QtGui>
#include <QtWidgets>
#include "arrow.h"

class ListItem
{
private:
    QGraphicsRectItem *rectangle;
    Arrow *leftArrow, *rightArrow;

public:
    int value;
    ListItem(int value);
    void draw(int index);
};

#endif // LISTITEM_H
