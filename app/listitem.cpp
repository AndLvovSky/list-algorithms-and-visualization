#include "listitem.h"
#include "appcontext.h"

ListItem::ListItem(int value): value(value)
{
    scene = AppContext::scene;
    leftArrow = nullptr;
    rightArrow = nullptr;
    valueText = nullptr;
    indexText = nullptr;
    rectangle = nullptr;
}

void ListItem::hide()
{
    rectangle->setVisible(false);
    valueText->setVisible(false);
    indexText->setVisible(false);
    leftArrow->hide();
    rightArrow->hide();
}

void ListItem::draw(int index)
{
    drawBody(index);
    drawArrows(index);
}

void ListItem::drawBody(int index)
{
    drawRectangle(index, 0);
    drawValueText(index, 0);
    drawIndexText(index);
}

void ListItem::drawArrows(int index)
{
    drawLeftArrow(index);
    drawRightArrow(index);
}

void ListItem::drawBodyUnderList(int index)
{
    int verticalOffset = 200;
    drawRectangle(index, verticalOffset);
    drawValueText(index, verticalOffset);
}

void ListItem::drawLeftArrow(int index)
{
    leftArrow = new Arrow(make_shared<Point>(0 + offset(index), 125), make_shared<Point>(-50 + offset(index), 125));
    leftArrow->draw();
}

void ListItem::drawRightArrow(int index)
{
    rightArrow = new Arrow(make_shared<Point>(100 + offset(index), 75), make_shared<Point>(150 + offset(index), 75));
    rightArrow->draw();
}

void ListItem::moveRightByOne()
{
    rectangle->setPos(rectangle->x() + 150, rectangle->y());
    valueText->setPos(valueText->x() + 150, valueText->y());
    indexText->setPos(indexText->x() + 150, indexText->y());
    leftArrow->moveRightByOne();
    rightArrow->moveRightByOne();
}

void ListItem::moveBodyToTop()
{
    rectangle->setPos(rectangle->x(), rectangle->y() - 200);
    valueText->setPos(valueText->x(), 75);
}

void ListItem::connectToListItem(int thisIndex, int otherIndex, ListItem::Position thisPosition)
{
    int topArrowY = 75;
    int bottomArrowY = 125;
    if (thisPosition == LEFT) {
        int thisRightX = 50 + thisIndex * 150 + 100;
        int otherLeftX = 50 + otherIndex * 150;

        if (!rightArrow) {
            rightArrow = new Arrow(make_shared<Point>(thisRightX, topArrowY), make_shared<Point>(otherLeftX, topArrowY));
            rightArrow->draw();
        } else {
            rightArrow->change(make_shared<Point>(thisRightX, topArrowY), make_shared<Point>(otherLeftX, topArrowY));
        }
    } else if (thisPosition == RIGHT) {
        int thisLeftX = 50 + (thisIndex - 1) * 150 ;
        int otherRightX = 50 + (otherIndex - 1) * 150 + 100;

        if (!leftArrow) {
            leftArrow = new Arrow(make_shared<Point>(thisLeftX, bottomArrowY), make_shared<Point>(otherRightX, bottomArrowY));
            leftArrow->draw();
        } else {
            leftArrow->change(make_shared<Point>(thisLeftX, bottomArrowY), make_shared<Point>(otherRightX, bottomArrowY));
        }
    }
}

void ListItem::connectToLeftItem(int index)
{
    connectToListItem(index + 1, index, RIGHT);
}

void ListItem::connectToRightItem(int index)
{
    connectToListItem(index, index + 1, LEFT);
}

void ListItem::connectToBelowItem(int thisIndex, ListItem::Position thisPosition)
{
    int topArrowY = 75;
    int bottomArrowY = 125;
    if (thisPosition == LEFT) {
        int thisRightX = -100 + thisIndex * 150 + 100;
        int otherLeftX = -100 + (thisIndex + 1) * 150;
        rightArrow->change(make_shared<Point>(thisRightX, topArrowY), make_shared<Point>(otherLeftX, 275));
    } else if (thisPosition == RIGHT) {
        int thisLeftX = 50 + (thisIndex - 1) * 150 + 150;
        int otherRightX = thisIndex * 150;
        leftArrow->change(make_shared<Point>(thisLeftX, bottomArrowY), make_shared<Point>(otherRightX, 325));
    }
}

Arrow *ListItem::drawArrowOver(int index, Arrow *arrow)
{
    arrow->change(make_shared<Point>(50 + offset(index), -20),
                              make_shared<Point>(50 + offset(index), 40));
    return arrow;
}

void ListItem::drawValueText(int index, int verticalOffset)
{
    valueText = scene->addText(QString::number(value), QFont("Arial", 30));
    valueText->setPos(50 + offset(index) - QString::number(value).size() * 14, 70 + verticalOffset);
}

void ListItem::drawIndexText(int index)
{
    indexText = scene->addText(QString::number(index), QFont("Arial", 20));
    indexText->setPos(50 + offset(index) - QString::number(index).size() * 11, 150);
}

void ListItem::drawRectangle(int index, int verticalOffset)
{
    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(4);
    rectangle = scene->addRect(0 + offset(index), 50 + verticalOffset, 100, 100, pen);
}

int ListItem::offset(int index)
{
    return index * 150 + 50;
}
