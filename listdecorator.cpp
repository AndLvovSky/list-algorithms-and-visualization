#include "listdecorator.h"

void ListDecorator::push_back(int value)
{
    list.push_back(value);
    currentMementoIndex++;
    memento.insert(memento.begin() + currentMementoIndex, copy(list));
    listDrawer->drawList(list);
}

void ListDecorator::insert(int value, int position)
{
    if (position < 0 || position >= list.get_size()) {
        return;
    } else {
        list.insert(getIthIterator(position), value);
        currentMementoIndex++;
        memento.insert(memento.begin() + currentMementoIndex, copy(list));
        listDrawer->drawList(list);
    }
}

void ListDecorator::erase(int position)
{
    if (position >= 0 && position < list.get_size()) {
        list.erase(getIthIterator(position));
        currentMementoIndex++;
        memento.insert(memento.begin() + currentMementoIndex, copy(list));
        listDrawer->drawList(list);
    }
}

void ListDecorator::clear()
{
    if (list.get_size() > 0) {
        list = DoublyLinkedList<int>();
        currentMementoIndex++;
        memento.insert(memento.begin() + currentMementoIndex, copy(list));
        listDrawer->drawList(list);
    }
}

void ListDecorator::undo()
{
    if (currentMementoIndex > 0) {
        currentMementoIndex--;
        list = memento.at(currentMementoIndex);
        listDrawer->drawList(list);
    }
}

void ListDecorator::redo()
{
    if (currentMementoIndex < memento.size() - 1) {
        currentMementoIndex++;
        list = memento.at(currentMementoIndex);
        listDrawer->drawList(list);
    }
}

DoublyLinkedList<int>::iterator ListDecorator::getIthIterator(int index)
{
    DoublyLinkedList<int>::iterator it = list.begin();
    for (int i = 0; i < index; i++) {
        ++it;
    }
    return it;
}

DoublyLinkedList<int> ListDecorator::copy(DoublyLinkedList<int> list)
{
    DoublyLinkedList<int> copy;
    for (int i: list){
        copy.push_back(i);
    }
    return copy;
}
