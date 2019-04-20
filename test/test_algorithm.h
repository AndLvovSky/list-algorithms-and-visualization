#ifndef TEST_ALGORITHM_H
#define TEST_ALGORITHM_H

#include <QtTest>

class TestAlgorithm : public QObject {

    Q_OBJECT

public:

    TestAlgorithm();

    ~TestAlgorithm();

private slots:

    void test_for_each_1();

    void test_for_each_2();

    void test_count_if();

    void test_reverse();

};

#endif // TEST_ALGORITHM_H
