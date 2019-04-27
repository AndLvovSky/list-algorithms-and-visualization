#ifndef DOUBLY_LINKED_LIST_REVERSE_ITERATOR_H
#define DOUBLY_LINKED_LIST_REVERSE_ITERATOR_H

#include "doubly_linked_list_abstract_iterator.h"

template <typename T>
/**
 * @brief The DoublyLinkedListReverseIterator class represents
 * DoublyLinkedList reverse iterator.
 */
class DoublyLinkedListReverseIterator :
    public DoublyLinkedListAbstractIterator<T> {

private:

    /**< Type of node pointer. */
    typedef std::shared_ptr<BidirectionalNode<T>> NodePtr;

    /**< Type of parent iterator. */
    typedef DoublyLinkedListAbstractIterator<T> Parent;

    template <typename> friend class DoublyLinkedList;

    using Parent::current;

public:

    DoublyLinkedListReverseIterator(NodePtr current);

    DoublyLinkedListReverseIterator& operator ++ () override;

    DoublyLinkedListReverseIterator& operator -- () override;

};

#include "doubly_linked_list_reverse_iterator.tpp"

#endif // DOUBLY_LINKED_LIST_REVERSE_ITERATOR_H
