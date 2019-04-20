#ifndef TEST_ARRAY_LIST_H
#define TEST_ARRAY_LIST_H

#include <QtTest>

class TestArrayList : public QObject {

    Q_OBJECT

public:

    TestArrayList();

    ~TestArrayList();

private slots:

    void test_push_pop();

    void test_size_capacity();

    void test_index_operator();

    void test_iterator();

    void test_insert();

    void test_erase();

    void test_init_list();

    void test_equality_operator();

};

#endif // TEST_ARRAY_LIST_H
