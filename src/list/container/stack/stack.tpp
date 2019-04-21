#include "stack.h"

template <typename T>
Stack<T>::Stack() : Container() {
    tail = nullptr;
}

template <typename T>
Stack<T>::~Stack() {}

template <typename T>
void Stack<T>::push_back(const T& value) {
    if (is_empty()) {
        tail = std::make_shared<Node>(value, nullptr);
    } else {
        auto new_tail = std::make_shared<Node>(value, tail);
        tail = new_tail;
    }
    inc_size();
}

template <typename T>
void Stack<T>::pop_back() {
    if (is_safe()) {
        check_not_empty();
    }
    tail = tail->next;
    dec_size();
}

template <typename T>
T& Stack<T>::back() const {
    if (is_safe()) {
        check_not_empty();
    }
    return tail->value();
}

template class Stack<int>;
