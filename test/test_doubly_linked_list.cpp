#include "test_doubly_linked_list.h"
#include "lists/doubly_linked_list/doubly_linked_list.h"
#include <vector>
#include <iostream>

TestDoublyLinkedList::TestDoublyLinkedList() {}

TestDoublyLinkedList::~TestDoublyLinkedList() {}

void TestDoublyLinkedList::test_iterator() {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    std::vector<int> nums;
    for (auto num : list) {
        nums.push_back(num);
    }
    QVERIFY(nums[0] == 1 && nums[1] == 2 && nums[2] == 3);
}

void TestDoublyLinkedList::test_reverse_iterator() {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    std::vector<int> nums;
    for (DoublyLinkedList<int>::reverse_iterator it = list.rbegin();
         it != list.rend(); ++it) {
        nums.push_back(*it);
    }
    QVERIFY(nums[0] == 3 && nums[1] == 2 && nums[2] == 1);
}
