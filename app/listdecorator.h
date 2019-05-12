#ifndef LISTDECORATOR_H
#define LISTDECORATOR_H

#include <list/container/doubly_linked_list/doubly_linked_list.h>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QMessageLogger>
#include "listitem.h"

using namespace std;

class ListDecorator{
private:
    DoublyLinkedList<shared_ptr<ListItem>> list;
    std::vector<DoublyLinkedList<shared_ptr<ListItem>>> memento;
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
    DoublyLinkedList<shared_ptr<ListItem>> copy(DoublyLinkedList<shared_ptr<ListItem>> list);
    DoublyLinkedList<shared_ptr<ListItem>>::iterator getIthIterator(int i);
    shared_ptr<ListItem> getIthValue(int i);
    void connectTwoListItems(int index1, int index2);
    void blockGui(int ms);
    void iterateOverTo(int index);
    void shiftAllAfter(int position);
};

#endif // LISTDECORATOR_H
