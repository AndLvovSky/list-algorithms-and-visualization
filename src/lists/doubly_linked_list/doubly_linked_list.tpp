#include "doubly_linked_list.h"

using std::make_shared;

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : Container() {
    head = tail = nullptr;
}

template <typename T>
typename DoublyLinkedList<T>::iterator
DoublyLinkedList<T>::begin() const {
    return iterator(this->head);
}

template <typename T>
typename DoublyLinkedList<T>::iterator
DoublyLinkedList<T>::end() const {
    return iterator(nullptr);
}

template <typename T>
typename DoublyLinkedList<T>::reverse_iterator
DoublyLinkedList<T>::rbegin() const {
    return reverse_iterator(this->tail);
}

template <typename T>
typename DoublyLinkedList<T>::reverse_iterator
DoublyLinkedList<T>::rend() const {
    return reverse_iterator(nullptr);
}

template <typename T>
typename DoublyLinkedList<T>::iterator
DoublyLinkedList<T>::find(const T& value) const {
    for (auto it = this->begin(); it != this->end(); ++it) {
        if (*it == value) {
            return it;
        }
    }
    return this->end();
}

template <typename T>
void DoublyLinkedList<T>::insert(const iterator& it, const T& value) {
    if (it == this->begin()) {
        push_front(value);
        return;
    }
    if (it == this->end()) {
        push_back(value);
        return;
    }
    auto node = it.current;
    auto new_node = make_shared<Node>(value, node->prev, node);
    node->prev->next = new_node;
    node->prev = new_node;
}

template <typename T>
void DoublyLinkedList<T>::erase(const iterator& it) {
    //...
}

template <typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    if (is_empty()) {
        head = tail = make_shared<Node>(value, nullptr, nullptr);
    } else {
        auto new_head = make_shared<Node>(value, nullptr, head);
        head->prev = new_head;
        head = new_head;
    }
    inc_size();
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    if (is_empty()) {
        head = tail = make_shared<Node>(value, nullptr, nullptr);
    } else {
        auto new_tail = make_shared<Node>(value, tail, nullptr);
        tail->next = new_tail;
        tail = new_tail;
    }
    inc_size();
}

template <typename T>
T DoublyLinkedList<T>::front() const {
    //...
}

template <typename T>
T DoublyLinkedList<T>::back() const {
    //...
}

template <typename T>
T DoublyLinkedList<T>::pop_front() {
    //...
}

template <typename T>
T DoublyLinkedList<T>::pop_back() {
    //...
}

template class  DoublyLinkedList<int>;
