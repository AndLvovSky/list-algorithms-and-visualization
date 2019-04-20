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

void TestAlgorithm::test_min_max_1() {
    ArrayList<int> list = {1, 0, -5, 3, 1};
    auto min_it = Algorithm<ArrayList, int>::min(list.begin(), list.end());
    QVERIFY(*min_it == -5);
    auto max_it = Algorithm<ArrayList, int>::max(list.begin(), list.end());
    QVERIFY(*max_it == 3);
}

void TestAlgorithm::test_min_max_2() {
    struct C {
        int x;
        int y;
        C() = default;
        C(int x, int y) : x(x), y(y) {}
        bool operator<(const C& other) {
            return this->x < other.x;
        }
        bool operator==(const C& other) {
            return this->x == other.x && this->y == other.y;
        }
    };
    ArrayList<C> list = {C(1, 2), C(-4, -1), C(3, -5), C(2, 5)};
    auto min_it = Algorithm<ArrayList, C>::min(list.begin(), list.end());
    QVERIFY(*min_it == C(-4, -1));
    auto max_it = Algorithm<ArrayList, C>::max(list.begin(), list.end());
    QVERIFY(*max_it == C(3, -5));
}
