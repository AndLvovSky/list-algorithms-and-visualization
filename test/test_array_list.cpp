#include "test_array_list.h"
#include "list/container/array_list/array_list.h"
#include <vector>

TestArrayList::TestArrayList() {}

TestArrayList::~TestArrayList() {}

void TestArrayList::test_push_pop() {
    ArrayList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    QVERIFY(list.back() == 3);

    list.pop_back();
    QVERIFY(list.back() == 2);

    list.push_back(5);
    std::vector<int> target_nums = {1, 2, 5};
    std::vector<int> real_nums;
    for (auto num: list) real_nums.push_back(num);
    QVERIFY(target_nums == real_nums);
}

void TestArrayList::test_size_capacity() {
    ArrayList<int> list;
    for (int i = 1; i <= 3; i++) list.push_back(i);
    QVERIFY(list.get_size() == 3);
    QVERIFY(list.get_capacity() == 4);

    list.resize(6);
    QVERIFY(list.get_size() == 6);
    QVERIFY(list.get_capacity() == 8);

    list.resize(1);
    QVERIFY(list.get_size() == 1);
    QVERIFY(list.get_capacity() == 8);
}

void TestArrayList::test_index_operator() {
    ArrayList<int> list;
    for (int i = 1; i <= 3; i++) list.push_back(i);
    QVERIFY(list[0] == 1 && list[1] == 2 && list[2] == 3);
    QVERIFY(list[-1] == 3 && list[-2] == 2 && list[-3] == 1);
    QVERIFY(list[4] == 2 && list[-4] == 3);
}

void TestArrayList::test_iterator() {
    ArrayList<int> list;
    for (int i = 1; i <= 5; i++) list.push_back(i);
    QVERIFY(*list.begin() == 1);
    QVERIFY(*(list.begin() + 2) == 3);
    QVERIFY(list.end() - list.begin() == list.get_size());

    auto it1 = list.begin() + 1;
    auto it2 = list.begin() + 3;
    QVERIFY(it2 - it1 == 2);
}

void TestArrayList::test_insert() {
    ArrayList<int> list;
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

void TestArrayList::test_erase() {
    ArrayList<int> list;
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

void TestArrayList::test_init_list() {
    ArrayList<int> list = {1, 2, 3};
    QVERIFY(list.get_size() == 3);
    QVERIFY(list.get_capacity() == 4);
    std::vector<int> target_nums = {1, 2, 3};
    std::vector<int> real_nums;
    for (auto num: list) real_nums.push_back(num);
    QVERIFY(real_nums == target_nums);
}

void TestArrayList::test_equality_operator() {
    ArrayList<int> list = {1, 2, 3};
    QVERIFY(list == ArrayList<int>({1, 2, 3}));
    QVERIFY(list != ArrayList<int>({1, 2, 3, 4}));
    QVERIFY(list != ArrayList<int>({5, 4, 7}));
}
