#include <QtTest/QtTest>
#include "test_doubly_linked_list.h"
#include "test_array_list.h"
#include "test_stack.h"
#include "test_queue.h"
#include "test_deque.h"
#include "test_algorithm.h"

int main(int argc, char* argv[]) {
    int status = 0;
    {
        TestDoublyLinkedList obj;
        status |= QTest::qExec(&obj, argc, argv);
    }
    {
        TestArrayList obj;
        status |= QTest::qExec(&obj, argc, argv);
    }
    {
        TestStack obj;
        status |= QTest::qExec(&obj, argc, argv);
    }
    {
        TestQueue obj;
        status |= QTest::qExec(&obj, argc, argv);
    }
    {
        TestDeque obj;
        status |= QTest::qExec(&obj, argc, argv);
    }
    {
        TestAlgorithm obj;
        status |= QTest::qExec(&obj, argc, argv);
    }
    return status;
}
