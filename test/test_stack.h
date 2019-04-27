#ifndef TEST_STACK_H
#define TEST_STACK_H

#include <QtTest>

class TestStack : public QObject {

    Q_OBJECT

public:

    TestStack();

    ~TestStack();

private slots:

    void test_push();

    void test_pop();

    void test_exceptions();

};

#endif // TEST_STACK_H
