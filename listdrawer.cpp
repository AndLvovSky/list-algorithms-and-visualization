#include "listdrawer.h"


/**
 * @brief draws a rectangle and two his arrows
 * @param i list index
 */
void ListDrawer::drawListItem(int i, int v)
{
    const int itemWidth = 150;

    int offset = i * itemWidth;

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
    QGraphicsTextItem *text =  scene->addText(QString::number(v), QFont("Arial", 20));
    text->setPos(50 + offset - QString::number(v).size() * 8, 75);

    //Index text
    QGraphicsTextItem *index =  scene->addText(QString::number(i), QFont("Arial", 10));
    index->setPos(50 + offset - QString::number(i).size() * 4, 30);
}

void ListDrawer::drawList(DoublyLinkedList<int> list)
{
    scene->setSceneRect(0, 0, 150*list.get_size(), 200);
    scene->clear();

    int counter = 0;
    for (int i: list){
        drawListItem(counter++, i);
    }
}
