#include "test_algorithm.h"
#include "container/algorithm/algorithm.h"
#include "list/container/doubly_linked_list/doubly_linked_list.h"
#include "list/container/array_list/array_list.h"
#include <vector>

TestAlgorithm::TestAlgorithm() {}

TestAlgorithm::~TestAlgorithm() {}

void TestAlgorithm::test_for_each_1() {
    DoublyLinkedList<int> list;
    for (int i = 1; i <= 3; i++) list.push_back(i);
    Algorithm<DoublyLinkedList, int>::for_each(list.begin(), list.end(),
    [](int& num) {
        num *= 2;
    });
    std::vector<int> real_nums;
    for (auto num: list) real_nums.push_back(num);
    QVERIFY(real_nums == std::vector<int>({2, 4, 6}));
}

void TestAlgorithm::test_for_each_2() {
    ArrayList<int> list;
    for (int i = 1; i <= 5; i++) list.push_back(i);
    Algorithm<ArrayList, int>::for_each(list.begin() + 2, list.end(),
    [](int& num) {
        num += 3;
    });
    std::vector<int> real_nums;
    for (auto num: list) real_nums.push_back(num);
    QVERIFY(real_nums == std::vector<int>({1, 2, 6, 7, 8}));
}

void TestAlgorithm::test_count_if() {
    ArrayList<int> list = {3, -2, 5, 0, 4, -2, -6};
    auto negative_count = Algorithm<ArrayList, int>::count_if(
        list.begin(), list.end(), [](int a) -> bool {
        return a < 0;
    });
    QVERIFY(negative_count == 3);
}

void TestAlgorithm::test_reverse() {
    ArrayList<int> list = {1, 2, 3, 4};
    Algorithm<ArrayList, int>::reverse(list.begin(), list.end());
    QCOMPARE(list, ArrayList<int>({4, 3, 2, 1}));
}
