#include "array_list.h"
#include "container/exception/container_exception.h"
#include <cmath>

template <typename T>
ArrayList<T>::ArrayList() : Container() {}

template <typename T>
ArrayList<T>::ArrayList(const std::initializer_list<T>& init_list) : ArrayList() {
    resize(init_list.size());
    int i = 0;
    for (auto& value: init_list) {
        values[i++] = value;
    }
}

template <typename T>
ArrayList<T>::~ArrayList() {
    delete[] values;
}

template <typename T>
typename ArrayList<T>::iterator
ArrayList<T>::begin() const {
    return iterator(0, *this);
}

template <typename T>
typename ArrayList<T>::iterator
ArrayList<T>::end() const {
    return iterator(get_size(), *this);
}

template <typename T>
typename ArrayList<T>::iterator
ArrayList<T>::find(const T& value) const {
    for (int i = 0; i < get_size(); i++) {
        if (values[i] == value) {
            return iterator(i, *this);
        }
    }
    return end();
}

template <typename T>
ArrayList<T>& ArrayList<T>::insert(const iterator& it, const T& value) {
    if (it == end()) {
        push_back(value);
        return *this;
    }
    if (is_safe()) {
        check_iterator(it);
    }
    if (get_size() == capacity) {
        resize(get_size() + 1);
    } else {
        inc_size();
    }
    int pos = it.current;
    for (int i = get_size() - 2; i >= pos; i--) {
        values[i + 1] = values[i];
    }
    values[pos] = value;
    return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::erase(const iterator& it) {
    if (is_safe()) {
        check_not_empty();
        check_iterator(it);
    }
    int pos = it.current;
    for (int i = pos + 1; i < get_size(); i++) {
        values[i - 1] = values[i];
    }
    dec_size();
    return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::push_back(const T& value) {
    if (get_size() == capacity) {
        resize(get_size() + 1);
    } else {
        inc_size();
    }
    values[get_size() - 1] = value;
    return *this;
}

template <typename T>
T& ArrayList<T>::back() const {
    if (is_safe()) {
        check_not_empty();
    }
    return values[get_size() - 1];
}

template <typename T>
ArrayList<T>& ArrayList<T>::pop_back() {
    if (is_safe()) {
        check_not_empty();
    }
    dec_size();
    return *this;
}

template <typename T>
int ArrayList<T>::get_capacity() {
    return this->capacity;
}

template <typename T>
void ArrayList<T>::enlarge(int size) {
    if (size <= capacity) return;
    while (size > capacity) capacity *= 2;
    if (is_empty()) {
        delete[] values;
        values = new T[capacity];
        return;
    }
    T* values_copy = new T[get_size()];
    for (int i = 0; i < get_size(); i++) {
        values_copy[i] = values[i];
    }
    delete[] values;
    values = new T[capacity];
    for (int i = 0; i < get_size(); i++) {
        values[i] = values_copy[i];
    }
    delete[] values_copy;
}

template <typename T>
void ArrayList<T>::resize(int size) {
    if (is_safe()) {
        check_size(size);
    }
    if (size > get_size()) {
        enlarge(size);
    }
    set_size(size);
}

template <typename T>
T& ArrayList<T>::operator [] (int pos) const {
    if (is_safe()) {
        check_not_empty();
    }
    return values[((pos % get_size()) + get_size()) % get_size()];
}

template <typename T>
bool ArrayList<T>::operator == (const ArrayList& other) const {
    if (this->get_size() != other.get_size()) return false;
    auto this_it = this->begin();
    auto other_it = other.begin();
    while (this_it != this->end()) {
        if (!(*this_it == *other_it)) return false;
        ++this_it;
        ++other_it;
    }
    return true;
}

template <typename T>
bool ArrayList<T>::operator != (const ArrayList& other) const {
    return !(*this == other);
}

template <typename T>
void ArrayList<T>::check_iterator(const iterator& it) const {
    if (this != &it.list || it == end()) {
        throw ContainerException("Incorrect iterator!");
    }
}

template <typename T>
void ArrayList<T>::check_size(int size) const {
    if (size < 0) {
        throw ContainerException("Negative size!");
    }
}

template <typename T>
void ArrayList<T>::clear() {
    resize(0);
}

template class ArrayList<int>;
