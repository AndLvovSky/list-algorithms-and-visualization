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

void TestDeque::test_exceptions() {
    Deque<int> deque;
    deque.set_safety(true);
    deque.push_back(1);
    deque.pop_back();
    bool flag;
    flag = false;
    try { deque.pop_back(); }
    catch (...) { flag = true; }
    QVERIFY(flag);
    flag = false;
    try { deque.pop_front(); }
    catch (...) { flag = true; }
    QVERIFY(flag);
    flag = false;
    try { deque.back(); }
    catch (...) { flag = true; }
    QVERIFY(flag);
    flag = false;
    try { deque.front(); }
    catch (...) { flag = true; }
    QVERIFY(flag);
    flag = false;
    try { deque.push_back(1).push_front(2)
        .pop_back().pop_front().pop_back(); }
    catch (...) { flag = true; }
    QVERIFY(flag);
    QVERIFY(deque.get_size() == 0);
}

void TestDeque::test_chaining() {
    Deque<int> deque;
    deque.push_back(1).push_front(2).push_back(3);
    QVERIFY(deque.get_size() == 3);
    QVERIFY(deque.front() == 2);
    QVERIFY(deque.back() == 3);
    deque.pop_back().pop_front().push_back(5);
    QVERIFY(deque.front() == 1);
    QVERIFY(deque.back() == 5);
    QVERIFY(deque.get_size() == 2);
}
