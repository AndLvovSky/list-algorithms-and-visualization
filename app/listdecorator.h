#ifndef LISTDECORATOR_H
#define LISTDECORATOR_H

#include <list/container/doubly_linked_list/doubly_linked_list.h>
#include <QtCore>
#include <QtGui>
#include  <QtWidgets>
#include "listdrawer.h"

class ListDecorator{
private:
    QGraphicsScene * scene;
    DoublyLinkedList<int> list;
    ListDrawer *listDrawer;

public:
    ListDecorator(QGraphicsScene * scene) : scene(scene){
        listDrawer = new ListDrawer(scene);
    };
    void push_back(int value);
    void insert(int value, int position);
    void erase(int position);
    void clear();

private:
    DoublyLinkedList<int>::iterator getIthIterator(int index);
};

#endif // LISTDECORATOR_H
