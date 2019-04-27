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
    QGraphicsTextItem *valueText, *indexText;
    QGraphicsScene *scene;

public:
    enum Position{
        LEFT, RIGHT
    };

    int value;
    ListItem(int value);

    /**
     * @brief draw draw everything
     * @param index
     */
    void draw(int index);

    /**
     * @brief drawBody draw rectangle, value and index text
     * @param index
     */
    void drawBody(int index);
    void drawArrows(int index);
    void drawBodyUnderList(int index);
    void drawLeftArrow(int index);
    void drawRightArrow(int index);
    void moveRightByOne();
    void moveBodyToTop();
    void connectToListItem(int thisIndex, int otherIndex, Position thisPosition);
    void connectToLeftItem(int index);
    void connectToRightItem(int index);
    void connectToBelowItem(int thisIndex, Position thisPosition);

private:
    void drawValueText(int index, int verticalOffset);
    void drawIndexText(int index);
    void drawRectangle(int index, int verticalOffset);
    void moveValueText(int index);
    void moveIndexText(int index);
    void moveRectangle(int index);
    int offset(int index);
};

#endif // LISTITEM_H
