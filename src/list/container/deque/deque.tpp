#include "deque.h"

template <typename T>
Deque<T>::Deque() : Container() {
    head = tail = nullptr;
}

template <typename T>
Deque<T>::~Deque() {}

template <typename T>
Deque<T>& Deque<T>::push_front(const T& value) {
    if (is_empty()) {
        head = tail = std::make_shared<Node>(value, nullptr, nullptr);
    } else {
        auto new_head = std::make_shared<Node>(value, nullptr, head);
        head->prev = new_head;
        head = new_head;
    }
    inc_size();
    return *this;
}

template <typename T>
Deque<T>& Deque<T>::push_back(const T& value) {
    if (is_empty()) {
        head = tail = std::make_shared<Node>(value, nullptr, nullptr);
    } else {
        auto new_tail = std::make_shared<Node>(value, tail, nullptr);
        tail->next = new_tail;
        tail = new_tail;
    }
    inc_size();
    return *this;
}

template <typename T>
T& Deque<T>::front() const {
    if (is_safe()) {
        check_not_empty();
    }
    return head->value();
}

template <typename T>
T& Deque<T>::back() const {
    if (is_safe()) {
        check_not_empty();
    }
    return tail->value();
}

template <typename T>
Deque<T>& Deque<T>::pop_front() {
    if (is_safe()) {
        check_not_empty();
    }
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    } else {
        head->prev = nullptr;
    }
    dec_size();
    return *this;
}

template <typename T>
Deque<T>& Deque<T>::pop_back() {
    if (is_safe()) {
        check_not_empty();
    }
    tail = tail->prev;
    if (tail == nullptr) {
        head = nullptr;
    } else {
        tail->next = nullptr;
    }
    dec_size();
    return *this;
}

template class Deque<int>;
