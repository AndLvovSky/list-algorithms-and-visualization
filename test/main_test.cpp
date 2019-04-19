#include <QtTest/QtTest>
#include "test_doubly_linked_list.h"
#include "test_array_list.h"

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
    return status;
}
