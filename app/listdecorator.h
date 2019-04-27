#ifndef LISTDECORATOR_H
#define LISTDECORATOR_H

#include <list/container/doubly_linked_list/doubly_linked_list.h>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QMessageLogger>
#include "listitem.h"

class ListDecorator{
private:
    DoublyLinkedList<ListItem*> list;
    std::vector<DoublyLinkedList<ListItem*>> memento;
    int currentMementoIndex;
    QGraphicsScene *scene;

public:
    ListDecorator();

    void push_back(int value);
    void insert(int value, int position);
    void erase(int position);
    void clear();
    void undo();
    void redo();
    void drawList();

private:
    void updateSceneSize();
    DoublyLinkedList<ListItem*> copy(DoublyLinkedList<ListItem*> list);
    DoublyLinkedList<ListItem*>::iterator getIthIterator(int i);
    ListItem* getIthValue(int i);
    void connectTwoListItems(int index1, int index2);
    void blockGui(int ms);
};

#endif // LISTDECORATOR_H
