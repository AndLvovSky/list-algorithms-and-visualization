#ifndef TEST_DEQUE_H
#define TEST_DEQUE_H

#include <QtTest>

class TestDeque : public QObject {

    Q_OBJECT

public:

    TestDeque();

    ~TestDeque();

private slots:

    void test_push();

    void test_pop();

};

#endif // TEST_DEQUE_H
