#ifndef TEST_QUEUE_H
#define TEST_QUEUE_H

#include <QtTest>

class TestQueue : public QObject {

    Q_OBJECT

public:

    TestQueue();

    ~TestQueue();

private slots:

    void test_push();

    void test_pop();

    void test_exceptions();

};

#endif // TEST_QUEUE_H
