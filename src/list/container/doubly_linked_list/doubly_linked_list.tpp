#include "doubly_linked_list.h"
#include "container/exception/container_exception.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : Container() {
    head = tail = nullptr;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {}

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
    for (auto it = begin(); it != end(); ++it) {
        if (*it == value) {
            return it;
        }
    }
    return end();
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::insert(const iterator& it, const T& value) {
    if (it == begin()) {
        push_front(value);
        return *this;
    }
    if (it == end()) {
        push_back(value);
        return *this;
    }
    if (is_safe()) {
        check_iterator(it);
    }
    auto node = it.current;
    auto new_node = std::make_shared<Node>(value, node->prev, node);
    node->prev->next = new_node;
    node->prev = new_node;
    inc_size();
    return *this;
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::erase(const iterator& it) {
    if (is_safe()) {
        check_not_empty();
        check_iterator(it);
    }
    if (it == begin()) {
        pop_front();
        return *this;
    }
    if (*it == back()) {
        pop_back();
        return *this;
    }
    auto node = it.current;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    dec_size();
    return *this;
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::push_front(const T& value) {
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
DoublyLinkedList<T>& DoublyLinkedList<T>::push_back(const T& value) {
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
T& DoublyLinkedList<T>::front() const {
    if (is_safe()) {
        check_not_empty();
    }
    return head->value();
}

template <typename T>
T& DoublyLinkedList<T>::back() const {
    if (is_safe()) {
        check_not_empty();
    }
    return tail->value();
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::pop_front() {
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
DoublyLinkedList<T>& DoublyLinkedList<T>::pop_back() {
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

template <typename T>
void DoublyLinkedList<T>::check_iterator(const iterator& it) {
    bool is_this = false;
    for (auto this_it = begin(); this_it != end(); ++this_it) {
        if (it == this_it) {
            is_this = true;
            break;
        }
    }
    if (!is_this) {
        throw ContainerException("Incorrect iterator!");
    }
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    head = tail = nullptr;
    Container::clear();
}

template class  DoublyLinkedList<int>;
