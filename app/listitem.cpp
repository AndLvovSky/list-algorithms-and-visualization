#include "listitem.h"
#include "appcontext.h"

ListItem::ListItem(int value): value(value)
{

}

void ListItem::draw(int index)
{
    QGraphicsScene *scene = AppContext::scene;
    const int itemWidth = 150;

    int offset = index * itemWidth + 50;

    scene->addRect(0 + offset, 50, 100, 100);

    //Right arrow
    scene->addLine(100 + offset, 75, 150 + offset, 75);
    scene->addLine(150 + offset, 75, 125 + offset, 60);
    scene->addLine(150 + offset, 75, 125 + offset, 90);

    //Left arrow
    scene->addLine(0 + offset, 125, -50 + offset, 125);
    scene->addLine(-50 + offset, 125, -25 + offset, 110);
    scene->addLine(-50 + offset, 125, -25 + offset, 140);

    //Text
    QGraphicsTextItem *text =  scene->addText(QString::number(value), QFont("Arial", 20));
    text->setPos(50 + offset - QString::number(value).size() * 8, 75);

    //Index text
    QGraphicsTextItem *textIndex =  scene->addText(QString::number(index), QFont("Arial", 10));
    textIndex->setPos(50 + offset - QString::number(index).size() * 4, 30);
}
