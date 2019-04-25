#include "listdecorator.h"
#include "appcontext.h"

ListDecorator::ListDecorator() {
    memento.push_back(list);
    currentMementoIndex = 0;
}

void ListDecorator::push_back(int value)
{
    list.push_back(new ListItem(value));
    currentMementoIndex++;
    memento.insert(memento.begin() + currentMementoIndex, copy(list));
    drawList();
}

void ListDecorator::insert(int value, int position)
{
    if (position < 0 || position >= list.get_size()) {
        return;
    } else {
        list.insert(getIthIterator(position), new ListItem(value));
        currentMementoIndex++;
        memento.insert(memento.begin() + currentMementoIndex, copy(list));
        drawList();
    }
}

void ListDecorator::erase(int position)
{
    if (position >= 0 && position < list.get_size()) {
        list.erase(getIthIterator(position));
        currentMementoIndex++;
        memento.insert(memento.begin() + currentMementoIndex, copy(list));
        drawList();
    }
}

void ListDecorator::clear()
{
    if (list.get_size() > 0) {
        list = DoublyLinkedList<ListItem*>();
        currentMementoIndex++;
        memento.insert(memento.begin() + currentMementoIndex, copy(list));
        drawList();
    }
}

void ListDecorator::undo()
{
    if (currentMementoIndex > 0) {
        currentMementoIndex--;
        list = copy(memento.at(currentMementoIndex));
        drawList();
    }
}

void ListDecorator::redo()
{
    if (currentMementoIndex < memento.size() - 1) {
        currentMementoIndex++;
        list = copy(memento.at(currentMementoIndex));
        drawList();
    }
}

void ListDecorator::drawList()
{
    QGraphicsScene *scene = AppContext::scene;

    scene->setSceneRect(0, 0, 150*list.get_size() + 100, 200);
    scene->clear();

    int counter = 0;
    for (auto *item: list){
        item->draw(counter++);
    }
}

DoublyLinkedList<ListItem*>::iterator ListDecorator::getIthIterator(int index)
{
    DoublyLinkedList<ListItem*>::iterator it = list.begin();
    for (int i = 0; i < index; i++) {
        ++it;
    }
    return it;
}

DoublyLinkedList<ListItem*> ListDecorator::copy(DoublyLinkedList<ListItem*> list)
{
    DoublyLinkedList<ListItem*> copy;
    for (auto *i: list){
        copy.push_back(i);
    }
    return copy;
}
