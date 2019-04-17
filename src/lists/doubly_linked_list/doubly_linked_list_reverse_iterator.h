#ifndef DOUBLY_LINKED_LIST_REVERSE_ITERATOR_H
#define DOUBLY_LINKED_LIST_REVERSE_ITERATOR_H

#include "doubly_linked_list_abstract_iterator.h"

template <typename T>
class DoublyLinkedListReverseIterator : public DoublyLinkedListAbstractIterator<T> {

private:

    typedef std::shared_ptr<BidirectionalNode<T>> NodePtr;

    typedef DoublyLinkedListAbstractIterator<T> Parent;

public:

    DoublyLinkedListReverseIterator(NodePtr current);

    DoublyLinkedListReverseIterator& operator ++ () override;

    DoublyLinkedListReverseIterator& operator -- () override;

};

#include "doubly_linked_list_reverse_iterator.tpp"

#endif // DOUBLY_LINKED_LIST_REVERSE_ITERATOR_H
