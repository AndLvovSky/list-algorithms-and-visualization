#ifndef DOUBLY_LINKED_LIST_ITERATOR_H
#define DOUBLY_LINKED_LIST_ITERATOR_H

#include "doubly_linked_list_abstract_iterator.h"

template <typename T>
class DoublyLinkedListIterator : public DoublyLinkedListAbstractIterator<T> {

private:

    typedef std::shared_ptr<BidirectionalNode<T>> NodePtr;

    typedef DoublyLinkedListAbstractIterator<T> Parent;

public:

    DoublyLinkedListIterator(NodePtr current);

    DoublyLinkedListIterator& operator ++ () override;

    DoublyLinkedListIterator& operator -- () override;

};

#include "doubly_linked_list_iterator.tpp"

#endif // DOUBLY_LINKED_LIST_ITERATOR_H
