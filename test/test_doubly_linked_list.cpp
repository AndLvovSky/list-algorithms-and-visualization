#include "test_doubly_linked_list.h"
#include "list/container/doubly_linked_list/doubly_linked_list.h"
#include <vector>

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

void TestDoublyLinkedList::test_insert() {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.insert(list.begin(), 5);
    list.insert(list.end(), 7);
    list.insert(list.find(2), 9);
    std::vector<int> nums;
    for (auto num: list) nums.push_back(num);
    std::vector<int> target_nums = {5, 1, 9, 2, 3, 7};
    QVERIFY(list.get_size() == 6);
    QVERIFY(nums == target_nums);
}

void TestDoublyLinkedList::test_erase() {
    DoublyLinkedList<int> list;
    for (int i = 1; i <= 6; i++) {
        list.push_back(i);
    }
    list.erase(list.find(3));
    list.erase(list.find(4));
    list.erase(list.begin());
    list.erase(list.end());
    std::vector<int> nums;
    for (auto num: list) nums.push_back(num);
    std::vector<int> target_nums = {2, 5};
    QVERIFY(list.get_size() == 2);
    QVERIFY(nums == target_nums);
}

void TestDoublyLinkedList::test_additional_methods() {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    QVERIFY(list.front() == 1);
    QVERIFY(list.back() == 3);

    list.pop_back();
    list.pop_front();
    list.push_front(4);
    list.push_back(5);
    QVERIFY(list.front() == 4);
    QVERIFY(list.back() == 5);

    std::vector<int> nums;
    for (auto num: list) nums.push_back(num);
    std::vector<int> target_nums = {4, 2, 5};
    QVERIFY(list.get_size() == 3);
    QVERIFY(nums == target_nums);
}
