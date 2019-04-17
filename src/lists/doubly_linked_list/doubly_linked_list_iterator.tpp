#include "doubly_linked_list_iterator.h"

template <typename T>
DoublyLinkedListIterator<T>::DoublyLinkedListIterator(NodePtr current)
    : Parent(current) {}

template <typename T>
DoublyLinkedListIterator<T>& DoublyLinkedListIterator<T>::operator ++ () {
    Parent::current = Parent::current->next;
    return *this;
}


template <typename T>
DoublyLinkedListIterator<T>& DoublyLinkedListIterator<T>::operator -- () {
    Parent::current = Parent::current->prev;
    return *this;
}
