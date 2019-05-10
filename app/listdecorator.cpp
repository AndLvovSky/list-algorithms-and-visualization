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
    list.push_back(make_shared<ListItem>(value));
    currentMementoIndex++;
    memento.insert(memento.begin() + currentMementoIndex, copy(list));

    //Drawing
    blockGui(1000);
    updateSceneSize();
    int lastIndex = list.get_size() - 1;
    shared_ptr<ListItem> lastItem = getIthValue(lastIndex);
    QTimer::singleShot(300, [=](){ lastItem->drawBody(lastIndex); });
    QTimer::singleShot(600, [=](){ lastItem->drawLeftArrow(lastIndex); });
    QTimer::singleShot(900, [=](){ lastItem->drawRightArrow(lastIndex); });
}

void ListDecorator::insert(int value, int position)
{
    if (position < 0 || position >= list.get_size()) {
        return;
    } else {
        list.insert(getIthIterator(position), make_shared<ListItem>(value));
        currentMementoIndex++;
        memento.insert(memento.begin() + currentMementoIndex, copy(list));

        //Drawing
        updateSceneSize();
        shared_ptr<ListItem> insertItem = getIthValue(position);

        // shift all items after current to the right
        int counter = 0;
        for (shared_ptr<ListItem> item: list){
            if (counter > position) {
                item->moveRightByOne();
            }
            counter++;
        }

        if (position > 0 && position + 1 < list.get_size()) {
            blockGui(2200);
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
            blockGui(1300);
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
        shared_ptr<ListItem> eraseItem = getIthValue(position);
        list.erase(getIthIterator(position));
        currentMementoIndex++;
        memento.insert(memento.begin() + currentMementoIndex, copy(list));

        //Drawing
        eraseItem->hide();
        if (position > 0 && position < list.get_size()) {
            blockGui(1000);
            shared_ptr<ListItem> prevItem = getIthValue(position - 1);
            shared_ptr<ListItem> nextItem = getIthValue(position);
            QTimer::singleShot(300, [=](){ prevItem->connectToListItem(position - 1, position + 1, prevItem->LEFT); });
            QTimer::singleShot(600, [=](){ nextItem->connectToListItem(position + 2, position, prevItem->RIGHT); });
            QTimer::singleShot(900, [=](){ drawList(); });
        } else{
            blockGui(300);
            QTimer::singleShot(300, [=](){ drawList(); });
        }

    }
}

void ListDecorator::clear()
{
    if (list.get_size() > 0) {
        list = DoublyLinkedList<shared_ptr<ListItem>>();
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
    for (auto item: list){
        item->draw(counter++);
    }
}

void ListDecorator::updateSceneSize()
{
    scene->setSceneRect(0, 0, 150*list.get_size() + 100, 400);
}

DoublyLinkedList<shared_ptr<ListItem>>::iterator ListDecorator::getIthIterator(int index)
{
    DoublyLinkedList<shared_ptr<ListItem>>::iterator it = list.begin();
    for (int i = 0; i < index; i++) {
        ++it;
    }
    return it;
}

shared_ptr<ListItem> ListDecorator::getIthValue(int i)
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

void ListDecorator::blockGui(int ms)
{
    AppContext::guiBlocker->disableAll();
    QTimer::singleShot(ms, [=](){ AppContext::guiBlocker->enableAll(); });
}

DoublyLinkedList<shared_ptr<ListItem>> ListDecorator::copy(DoublyLinkedList<shared_ptr<ListItem>> list)
{
    DoublyLinkedList<shared_ptr<ListItem>> copy;
    for (auto i: list){
        copy.push_back(i);
    }
    return copy;
}
