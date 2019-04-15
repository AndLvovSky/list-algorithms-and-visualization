#include "test_linked_list.h"
#include <list_algorithms.h>
#include <list>

TestLinkedList::TestLinkedList()
{

}

TestLinkedList::~TestLinkedList()
{

}

void TestLinkedList::test_case1()
{
    std::list<int> l = {1, 2, 3};
    l.push_back(4);
    QVERIFY(l.back() == 4);
}
