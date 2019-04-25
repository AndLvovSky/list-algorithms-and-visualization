#ifndef LISTDECORATOR_H
#define LISTDECORATOR_H

#include <list/container/doubly_linked_list/doubly_linked_list.h>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QMessageLogger>
#include "listdrawer.h"

class ListDecorator{
private:
    QGraphicsScene * scene;
    DoublyLinkedList<int> list;
    ListDrawer *listDrawer;
    std::vector<DoublyLinkedList<int>> memento;
    int currentMementoIndex;

public:
    ListDecorator(QGraphicsScene * scene) : scene(scene){
        listDrawer = new ListDrawer(scene);
        memento.push_back(list);
        currentMementoIndex = 0;
    };

    void push_back(int value);
    void insert(int value, int position);
    void erase(int position);
    void clear();
    void undo();
    void redo();

private:
    DoublyLinkedList<int>::iterator getIthIterator(int index);
    DoublyLinkedList<int> copy(DoublyLinkedList<int> list);
};

#endif // LISTDECORATOR_H
