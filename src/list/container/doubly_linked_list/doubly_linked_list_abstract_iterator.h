#ifndef DOUBLY_LINKED_LIST_ABSTRACT_ITERATOR_H
#define DOUBLY_LINKED_LIST_ABSTRACT_ITERATOR_H

#include "iterator/bidirectional_iterator.h"
#include "iterator/forward_iterator.h"
#include "list/node/bidirectional_node.h"

template <typename T>
/**
 * @brief The DoublyLinkedListAbstractIterator class implements similar
 * methods for straight and reverse iterators of DoublyLinkedList.
 */
class DoublyLinkedListAbstractIterator : public BidirectionalIterator<T> {

protected:

     /** Type of node pointer. */
    typedef std::shared_ptr<BidirectionalNode<T>> NodePtr;

    NodePtr current; /**< Node pointer pointed by the iterator. */

public:

    /**
     * Initializes DoublyLinkedListAbstractIterator with specified node.
     * @param current - current pointed node.
     */
    DoublyLinkedListAbstractIterator(NodePtr current);

    /**
     * DoublyLinkedListAbstractIterator destructor.
     */
    virtual ~DoublyLinkedListAbstractIterator();

    T& operator * () const override;

    bool operator == (const ForwardIterator<T>& it) const override;

    bool operator != (const ForwardIterator<T>& it) const override;

    DoublyLinkedListAbstractIterator& operator = (
        const ForwardIterator<T>& it) override;

};

#include "doubly_linked_list_abstract_iterator.tpp"

#endif // DOUBLY_LINKED_LIST_ABSTRACT_ITERATOR_H
