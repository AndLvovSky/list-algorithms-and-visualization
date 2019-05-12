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

void ListDecorator::shiftAllAfter(int position)
{
    int counter = 0;
    for (shared_ptr<ListItem> item: list){
        if (counter > position) {
            item->moveRightByOne();
        }
        counter++;
    }
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

        if (position > 0 && position + 1 < list.get_size()) {
            blockGui(2400 + 300 * position);
            iterateOverTo(position);
            QTimer::singleShot(300 * position, [=](){ shiftAllAfter(position); });
            QTimer::singleShot(300 + 300 * position, [=](){ connectTwoListItems(position - 1, position + 1); });
            QTimer::singleShot(600 + 300 * position, [=](){ insertItem->drawBodyUnderList(position); });
            QTimer::singleShot(900 + 300 * position, [=](){ getIthValue(position - 1)->connectToBelowItem(position, insertItem->LEFT); });
            QTimer::singleShot(1200 + 300 * position, [=](){ getIthValue(position + 1)->connectToBelowItem(position, insertItem->RIGHT); });
            QTimer::singleShot(1500 + 300 * position, [=](){
                insertItem->moveBodyToTop();
                getIthValue(position - 1)->connectToListItem(position - 1, position, insertItem->LEFT);
                getIthValue(position + 1)->connectToListItem(position +1, position, insertItem->RIGHT);
            });
            QTimer::singleShot(1800 + 300 * position, [=](){ insertItem->connectToLeftItem(position); });
            QTimer::singleShot(2100 + 300 * position, [=](){ insertItem->connectToRightItem(position); });
            QTimer::singleShot(2400 + 300 * position, [=](){ drawList(); });
        } else { // position = 0
            blockGui(1300 + 300 * position);
            QTimer::singleShot(300 * position, [=](){ shiftAllAfter(position); });
            QTimer::singleShot(300 + 300 * position, [=](){ insertItem->drawBody(position); });
            QTimer::singleShot(600 + 300 * position, [=](){ insertItem->connectToLeftItem(position); });
            QTimer::singleShot(900 + 300 * position, [=](){ insertItem->connectToRightItem(position); });
            QTimer::singleShot(1200 + 300 * position, [=](){ drawList(); });
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
        if (position > 0 && position < list.get_size()) {
            blockGui(1200 + 300*position);
            iterateOverTo(position);
            QTimer::singleShot(300 * position, [=](){ eraseItem->hide(); });
            shared_ptr<ListItem> prevItem = getIthValue(position - 1);
            shared_ptr<ListItem> nextItem = getIthValue(position);
            QTimer::singleShot(600 + 300 * position, [=](){ prevItem->connectToListItem(position - 1, position + 1, prevItem->LEFT); });
            QTimer::singleShot(900 + 300 * position, [=](){ nextItem->connectToListItem(position + 2, position, prevItem->RIGHT); });
            QTimer::singleShot(1200 + 300 * position, [=](){ drawList(); });
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

void ListDecorator::iterateOverTo(int index)
{
    if (index == 0) return;
    shared_ptr<QPen> arrowPen = make_shared<QPen>();
    arrowPen->setWidth(4);
    arrowPen->setColor(Qt::red);
    Arrow * arrow = new Arrow(make_shared<Point>(0,0), make_shared<Point>(100, 100), arrowPen);
    qInfo() << "Before list.begin()";
    DoublyLinkedList<shared_ptr<ListItem>>::iterator it = list.begin();
    qInfo() << "After list.begin()";
    qInfo() << "Index: " << index;
    for (int i = 0; i < index; i++) {
        qInfo() << "i = " << i;
        ++it;
        qInfo() << "after ++it;";
        QTimer::singleShot(300 * i, [=](){ (*it)->drawArrowOver(i, arrow); });
    }
    QTimer::singleShot(300 * index, [=](){ arrow->hide(); });
}

DoublyLinkedList<shared_ptr<ListItem>> ListDecorator::copy(DoublyLinkedList<shared_ptr<ListItem>> list)
{
    DoublyLinkedList<shared_ptr<ListItem>> copy;
    for (auto i: list){
        copy.push_back(i);
    }
    return copy;
}
