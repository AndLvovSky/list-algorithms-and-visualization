#ifndef DOUBLY_LINKED_LIST_ITERATOR_H
#define DOUBLY_LINKED_LIST_ITERATOR_H

#include "doubly_linked_list_abstract_iterator.h"

template <typename T>
/**
 * @brief The DoublyLinkedListIterator class represents
 * DoublyLinkedList straight iterator.
 */
class DoublyLinkedListIterator :
    public DoublyLinkedListAbstractIterator<T> {

private:

    /**< Type of node pointer. */
    typedef std::shared_ptr<BidirectionalNode<T>> NodePtr;

    /**< Type of parent iterator. */
    typedef DoublyLinkedListAbstractIterator<T> Parent;

    template <typename> friend class DoublyLinkedList;

    using Parent::current;

public:    

    DoublyLinkedListIterator(NodePtr current);

    DoublyLinkedListIterator& operator ++ () override;

    DoublyLinkedListIterator& operator -- () override;

};

#include "doubly_linked_list_iterator.tpp"

#endif // DOUBLY_LINKED_LIST_ITERATOR_H
