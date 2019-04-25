#ifndef LISTDRAWER_H
#define LISTDRAWER_H

#include <list/container/doubly_linked_list/doubly_linked_list.h>
#include <QtCore>
#include <QtGui>
#include  <QtWidgets>

class ListDrawer{
private:
    QGraphicsScene * scene;

public:
    ListDrawer(QGraphicsScene * scene) : scene(scene){};
    /*void push_back(int value);
    void insert(int value, int position);
    void erase(int position);
    void clear();*/
    void drawList(DoublyLinkedList<int> list);
    void drawListItem(int index, int value);
};

#endif // LISTDRAWER_H
