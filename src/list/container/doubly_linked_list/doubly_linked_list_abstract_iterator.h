#ifndef DOUBLY_LINKED_LIST_ABSTRACT_ITERATOR_H
#define DOUBLY_LINKED_LIST_ABSTRACT_ITERATOR_H

#include "iterator/bidirectional_iterator.h"
#include "iterator/forward_iterator.h"
#include "list/node/bidirectional_node.h"

template <typename T>
class DoublyLinkedListAbstractIterator : public BidirectionalIterator<T> {

protected:

    typedef std::shared_ptr<BidirectionalNode<T>> NodePtr;

    NodePtr current;

public:

    DoublyLinkedListAbstractIterator(NodePtr current);

    virtual ~DoublyLinkedListAbstractIterator();

    T& operator * () const override;

    bool operator == (const ForwardIterator<T>& it) const override;

    bool operator != (const ForwardIterator<T>& it) const override;

    DoublyLinkedListAbstractIterator& operator = (
        const ForwardIterator<T>& it) override;

};

#include "doubly_linked_list_abstract_iterator.tpp"

#endif // DOUBLY_LINKED_LIST_ABSTRACT_ITERATOR_H
