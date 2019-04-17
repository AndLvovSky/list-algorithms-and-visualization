#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "container/container.h"
#include "lists/auxiliary/iterators/iterable_list.h"
#include "lists/auxiliary/nodes/bidirectional_node.h"
#include "doubly_linked_list_iterator.h"
#include "lists/auxiliary/iterators/reverse_iterable.h"
#include "doubly_linked_list_reverse_iterator.h"
#include <memory>

template <typename T>
class DoublyLinkedList :
    public Container,
    public IterableList<T, DoublyLinkedListIterator<T>>,
    public ReverseIterable<T, DoublyLinkedListReverseIterator<T>> {

private:

    typedef BidirectionalNode<T> Node;

    typedef std::shared_ptr<Node> NodePtr;

    NodePtr head;

    NodePtr tail;

public:

    typedef DoublyLinkedListIterator<T> iterator;

    typedef DoublyLinkedListReverseIterator<T> reverse_iterator;

    DoublyLinkedList();

    iterator begin() const override;

    iterator end() const override;

    reverse_iterator rbegin() const override;

    reverse_iterator rend() const override;

    iterator find(const T& value) const override;

    void insert(const iterator& it, const T& value) override;

    void erase(const iterator& it) override;

    void push_front(const T& value);

    void push_back(const T& value);

    T front() const;

    T back() const;

    T pop_front();

    T pop_back();

};

#include "doubly_linked_list.tpp"

#endif // DOUBLY_LINKED_LIST_H
