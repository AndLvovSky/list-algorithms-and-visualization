#include "doubly_linked_list_abstract_iterator.h"

template <typename T>
DoublyLinkedListAbstractIterator<T>::
DoublyLinkedListAbstractIterator(NodePtr current)
    : current(current) {}

template <typename T>
DoublyLinkedListAbstractIterator<T>::
~DoublyLinkedListAbstractIterator() {}

template <typename T>
T& DoublyLinkedListAbstractIterator<T>::operator * () const {
    return current->value();
}

template <typename T>
bool DoublyLinkedListAbstractIterator<T>::
operator == (const ForwardIterator<T>& it) const {
    return this->current ==
        static_cast<const DoublyLinkedListAbstractIterator<T>&>(it).current;
}

template <typename T>
bool DoublyLinkedListAbstractIterator<T>::
operator != (const ForwardIterator<T>& it) const {
    return !(*this == it);
}

template <typename T>
DoublyLinkedListAbstractIterator<T>& DoublyLinkedListAbstractIterator<T>::
operator = (const ForwardIterator<T>& it) {
    this->current =
        static_cast<const DoublyLinkedListAbstractIterator<T>&>(it).current;
    return *this;
}
