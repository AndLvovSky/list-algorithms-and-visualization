#ifndef DOUBLY_LINKED_LIST_ABSTRACT_ITERATOR_H
#define DOUBLY_LINKED_LIST_ABSTRACT_ITERATOR_H

#include "lists/auxiliary/iterators/bidirectional_iterator.h"
#include "lists/auxiliary/iterators/forward_iterator.h"
#include "lists/auxiliary/nodes/bidirectional_node.h"

template <typename T>
class DoublyLinkedListAbstractIterator : public BidirectionalIterator<T> {

protected:

    template <typename> friend class DoublyLinkedList;

    typedef std::shared_ptr<BidirectionalNode<T>> NodePtr;

    NodePtr current;

public:

    DoublyLinkedListAbstractIterator(NodePtr current);

    virtual ~DoublyLinkedListAbstractIterator();

    T& operator * () const override;

    bool operator == (const ForwardIterator<T>& it) const override;

    bool operator != (const ForwardIterator<T>& it) const override;

};

#include "doubly_linked_list_abstract_iterator.tpp"

#endif // DOUBLY_LINKED_LIST_ABSTRACT_ITERATOR_H
