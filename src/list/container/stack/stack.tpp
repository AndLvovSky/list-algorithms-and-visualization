#include "stack.h"

template <typename T>
Stack<T>::Stack() : Container() {
    tail = nullptr;
}

template <typename T>
Stack<T>::~Stack() {}

template <typename T>
Stack<T>& Stack<T>::push_back(const T& value) {
    if (is_empty()) {
        tail = std::make_shared<Node>(value, nullptr);
    } else {
        auto new_tail = std::make_shared<Node>(value, tail);
        tail = new_tail;
    }
    inc_size();
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::pop_back() {
    if (is_safe()) {
        check_not_empty();
    }
    tail = tail->next;
    dec_size();
    return *this;
}

template <typename T>
T& Stack<T>::back() const {
    if (is_safe()) {
        check_not_empty();
    }
    return tail->value();
}

template class Stack<int>;
