#include "array_list_iterator.h"

template <typename T>
ArrayListIterator<T>::ArrayListIterator(
    int current, const RandomAccessible<T>& list)
    : current(current), list(list) {}

template <typename T>
ArrayListIterator<T>::~ArrayListIterator<T>() {}

template <typename T>
T& ArrayListIterator<T>::operator * () const {
    return list[current];
};

template <typename T>
bool ArrayListIterator<T>::
operator == (const ForwardIterator<T>& it) const {
    return this->current ==
        static_cast<const ArrayListIterator<T>&>(it).current;
}

template <typename T>
bool ArrayListIterator<T>::
operator != (const ForwardIterator<T>& it) const {
    return !(*this == it);
}

template <typename T>
ArrayListIterator<T>& ArrayListIterator<T>::operator ++ () {
    current++;
    return *this;
}


template <typename T>
ArrayListIterator<T>& ArrayListIterator<T>::operator -- () {
    current--;
    return *this;
}

template <typename T>
int ArrayListIterator<T>::operator - (const ArrayListIterator& it) {
    return this->current - it.current;
}

template <typename T>
ArrayListIterator<T> ArrayListIterator<T>::operator + (int delta) {
    return ArrayListIterator<T>(current + delta, list);
}
