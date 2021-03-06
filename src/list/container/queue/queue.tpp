#include "queue.h"

template <typename T>
Queue<T>::Queue() : Container() {
    head = tail = nullptr;
}

template <typename T>
Queue<T>::~Queue() {}

template <typename T>
Queue<T>& Queue<T>::push_back(const T& value) {
    if (is_empty()) {
        head = tail = std::make_shared<Node>(value, nullptr);
    } else {
        auto new_tail = std::make_shared<Node>(value, nullptr);
        tail->next = new_tail;
        tail = new_tail;
    }
    inc_size();
    return *this;
}

template <typename T>
Queue<T>& Queue<T>::pop_front() {
    if (is_safe()) {
        check_not_empty();
    }
    head = head->next;
    dec_size();
    return *this;
}

template <typename T>
T& Queue<T>::front() const {
    if (is_safe()) {
        check_not_empty();
    }
    return head->value();
}

template <typename T>
void Queue<T>::clear() {
    head = tail = nullptr;
    Container::clear();
}

template class Queue<int>;
