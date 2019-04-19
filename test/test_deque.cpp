#include "test_deque.h"
#include "list/container/deque/deque.h"

TestDeque::TestDeque() {}

TestDeque::~TestDeque() {}

void TestDeque::test_push() {
    Deque<int> deque;
    deque.push_back(3);
    deque.push_back(4);
    deque.push_front(2);
    deque.push_front(1);
    QVERIFY(deque.get_size() == 4);
    QVERIFY(deque.front() == 1);
    QVERIFY(deque.back() == 4);
}

void TestDeque::test_pop() {
   Deque<int> deque;
   for (int i = 1; i <= 5; i++) deque.push_back(i);
   deque.pop_back();
   deque.pop_back();
   deque.pop_front();
   QVERIFY(deque.get_size() == 2);
   QVERIFY(deque.front() == 2);
   QVERIFY(deque.back() == 3);
}
