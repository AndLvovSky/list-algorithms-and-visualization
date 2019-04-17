#ifndef TEST_DOUBLY_LINKED_LIST_H
#define TEST_DOUBLY_LINKED_LIST_H

#include <QtTest>

class TestDoublyLinkedList : public QObject {

    Q_OBJECT

public:

    TestDoublyLinkedList();

    ~TestDoublyLinkedList();

private slots:

    void test_iterator();

    void test_reverse_iterator();

};

#endif // TEST_DOUBLY_LINKED_LIST_H