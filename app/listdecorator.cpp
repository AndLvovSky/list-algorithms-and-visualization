#include "listdecorator.h"


void ListDecorator::push_back(int value)
{
    list.push_back(value);
//    listDrawer->push_back(value);
    listDrawer->drawList(list);
}

void ListDecorator::insert(int value, int position)
{
    if (position < 0 || position >= list.get_size()) {
        return;
    } else {
        list.insert(getIthIterator(position), value);
    //    listDrawer->insert(value, position);
        listDrawer->drawList(list);
    }
}

void ListDecorator::erase(int position)
{
    list.erase(getIthIterator(position));
//    listDrawer->erase(position);
    listDrawer->drawList(list);
}

void ListDecorator::clear()
{
    list = DoublyLinkedList<int>();
//    listDrawer->clear();
    listDrawer->drawList(list);
}

DoublyLinkedList<int>::iterator ListDecorator::getIthIterator(int index)
{
    DoublyLinkedList<int>::iterator it = list.begin();
    for (int i = 0; i < index; i++){
        ++it;
    }
    return it;
}
