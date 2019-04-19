#include "test_stack.h"
#include "list/container/stack/stack.h"

TestStack::TestStack() {}

TestStack::~TestStack() {}

void TestStack::test_push() {
    Stack<int> stack;
    stack.push_back(1);
    stack.push_back(2);
    stack.push_back(3);
    QVERIFY(stack.get_size() == 3);
    QVERIFY(stack.back() == 3);
}

void TestStack::test_pop() {
    Stack<int> stack;
    for (int i = 1; i <= 5; i++) stack.push_back(i);
    stack.pop_back();
    stack.pop_back();
    stack.pop_back();
    QVERIFY(stack.get_size() == 2);
    QVERIFY(stack.back() == 2);
}
