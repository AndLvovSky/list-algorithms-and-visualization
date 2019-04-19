#include "deque.h"

template <typename T>
Deque<T>::Deque() : Container() {
    head = tail = nullptr;
}

template <typename T>
Deque<T>::~Deque() {}

template <typename T>
void Deque<T>::push_front(const T& value) {
    if (is_empty()) {
        head = tail = std::make_shared<Node>(value, nullptr, nullptr);
    } else {
        auto new_head = std::make_shared<Node>(value, nullptr, head);
        head->prev = new_head;
        head = new_head;
    }
    inc_size();
}

template <typename T>
void Deque<T>::push_back(const T& value) {
    if (is_empty()) {
        head = tail = std::make_shared<Node>(value, nullptr, nullptr);
    } else {
        auto new_tail = std::make_shared<Node>(value, tail, nullptr);
        tail->next = new_tail;
        tail = new_tail;
    }
    inc_size();
}

template <typename T>
T& Deque<T>::front() const {
    return head->value();
}

template <typename T>
T& Deque<T>::back() const {
    return tail->value();
}

template <typename T>
void Deque<T>::pop_front() {
    if (is_empty()) return;
    head = head->next;
    head->prev = nullptr;
    dec_size();
}

template <typename T>
void Deque<T>::pop_back() {
    if (is_empty()) return;
    tail = tail->prev;
    tail->next = nullptr;
    dec_size();
}

template class Deque<int>;
