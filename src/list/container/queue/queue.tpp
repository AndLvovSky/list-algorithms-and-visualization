#include "queue.h"

template <typename T>
Queue<T>::Queue() : Container() {
    head = tail = nullptr;
}

template <typename T>
Queue<T>::~Queue() {}

template <typename T>
void Queue<T>::push_back(const T& value) {
    if (is_empty()) {
        head = tail = std::make_shared<Node>(value, nullptr);
    } else {
        auto new_tail = std::make_shared<Node>(value, nullptr);
        tail->next = new_tail;
        tail = new_tail;
    }
    inc_size();
}

template <typename T>
void Queue<T>::pop_front() {
    if (is_empty()) return;
    head = head->next;
    dec_size();
}

template <typename T>
T& Queue<T>::front() const {
    return head->value();
}

template class Queue<int>;
