#include "array_list.h"
#include <cmath>

template <typename T>
ArrayList<T>::ArrayList() : Container() {
    values = new int[1];
}

template <typename T>
ArrayList<T>::~ArrayList() {
    delete values;
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
void ArrayList<T>::insert(const iterator& it, const T& value) {
    if (get_size() == capacity) {
        resize(get_size() + 1);
    }
    int pos = it.current;
    for (int i = get_size() - 2; i >= pos; i--) {
        values[i + 1] = values[i];
    }
    values[pos] = value;
}

template <typename T>
void ArrayList<T>::erase(const iterator& it) {
    int pos = it.current;
    for (int i = pos + 1; i < get_size(); i++) {
        values[i - 1] = values[i];
    }
    dec_size();
}

template <typename T>
void ArrayList<T>::push_back(const T& value) {
    if (get_size() == capacity) {
        resize(get_size() + 1);
    }
    values[get_size() - 1] = value;
}

template <typename T>
T& ArrayList<T>::back() const {
    return values[get_size() - 1];
}

template <typename T>
void ArrayList<T>::pop_back() {
    dec_size();
}

template <typename T>
int ArrayList<T>::get_capacity() {
    return this->capacity;
}

template <typename T>
void ArrayList<T>::enlarge(int size) {
    if (capacity <= this->capacity) return;
    int new_capacity = 1 << int(ceil(std::log2(size)));
    this->capacity = new_capacity;
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
    if (size > get_size()) {
        enlarge(size);
    }
    set_size(size);
}

template class ArrayList<int>;
