#ifndef TEST_LINKED_LIST_H
#define TEST_LINKED_LIST_H

#include <QtTest>

class TestLinkedList : public QObject
{
    Q_OBJECT

public:
    TestLinkedList();
    ~TestLinkedList();

private slots:
    void test_case1();

};

#endif // TEST_LINKED_LIST_H
