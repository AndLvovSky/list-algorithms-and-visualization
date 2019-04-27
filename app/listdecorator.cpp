#include "listdecorator.h"
#include "appcontext.h"
#include <QTimer>
#include <QtCore>
#include <QTimer>

ListDecorator::ListDecorator() {
    memento.push_back(list);
    currentMementoIndex = 0;
    scene = AppContext::scene;
}

void ListDecorator::push_back(int value)
{
    list.push_back(new ListItem(value));
    currentMementoIndex++;
    memento.insert(memento.begin() + currentMementoIndex, copy(list));

    //Drawing
    updateSceneSize();
    int lastIndex = list.get_size() - 1;
    ListItem *lastItem = getIthValue(lastIndex);
    QTimer::singleShot(300, [=](){ lastItem->drawBody(lastIndex); });
    QTimer::singleShot(600, [=](){ lastItem->drawLeftArrow(lastIndex); });
    QTimer::singleShot(900, [=](){ lastItem->drawRightArrow(lastIndex); });
}

void ListDecorator::insert(int value, int position)
{
    if (position < 0 || position >= list.get_size()) {
        return;
    } else {
        list.insert(getIthIterator(position), new ListItem(value));
        currentMementoIndex++;
        memento.insert(memento.begin() + currentMementoIndex, copy(list));

        //Drawing
        updateSceneSize();
        ListItem *insertItem = getIthValue(position);

        // shift all items after current to the right
        int counter = 0;
        for (ListItem* item: list){
            if (counter > position) {
                item->moveRightByOne();
            }
            counter++;
        }

        if (position > 0 && position + 1 < list.get_size()) {
            connectTwoListItems(position - 1, position + 1);
            QTimer::singleShot(300, [=](){ insertItem->drawBodyUnderList(position); });
            QTimer::singleShot(600, [=](){ getIthValue(position - 1)->connectToBelowItem(position, insertItem->LEFT); });
            QTimer::singleShot(900, [=](){ getIthValue(position + 1)->connectToBelowItem(position, insertItem->RIGHT); });
            QTimer::singleShot(1200, [=](){
                insertItem->moveBodyToTop();
                getIthValue(position - 1)->connectToListItem(position - 1, position, insertItem->LEFT);
                getIthValue(position + 1)->connectToListItem(position +1, position, insertItem->RIGHT);
            });
            QTimer::singleShot(1500, [=](){ insertItem->connectToLeftItem(position); });
            QTimer::singleShot(1800, [=](){ insertItem->connectToRightItem(position); });
            QTimer::singleShot(2100, [=](){ drawList(); });
        } else { // position = 0
            QTimer::singleShot(300, [=](){ insertItem->drawBody(position); });
            QTimer::singleShot(600, [=](){ insertItem->connectToLeftItem(position); });
            QTimer::singleShot(900, [=](){ insertItem->connectToRightItem(position); });
            QTimer::singleShot(1200, [=](){ drawList(); });
        }
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

    updateSceneSize();
    scene->clear();

    int counter = 0;
    for (auto *item: list){
        item->draw(counter++);
    }
}

void ListDecorator::updateSceneSize()
{
    scene->setSceneRect(0, 0, 150*list.get_size() + 100, 400);
}

DoublyLinkedList<ListItem*>::iterator ListDecorator::getIthIterator(int index)
{
    DoublyLinkedList<ListItem*>::iterator it = list.begin();
    for (int i = 0; i < index; i++) {
        ++it;
    }
    return it;
}

ListItem *ListDecorator::getIthValue(int i)
{
    int counter = 0;
    for (auto item: list){
        if (counter == i) {
            return item;
        }
        counter++;
    }
    return nullptr;
}

void ListDecorator::connectTwoListItems(int index1, int index2)
{
    getIthValue(index1)->connectToListItem(index1, index2, (new ListItem(0))->LEFT);
    getIthValue(index2)->connectToListItem(index2, index1, (new ListItem(0))->RIGHT);
}

DoublyLinkedList<ListItem*> ListDecorator::copy(DoublyLinkedList<ListItem*> list)
{
    DoublyLinkedList<ListItem*> copy;
    for (auto *i: list){
        copy.push_back(i);
    }
    return copy;
}
