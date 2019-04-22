#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "container/container.h"
#include "list/iterable_list.h"
#include "list/node/bidirectional_node.h"
#include "doubly_linked_list_iterator.h"
#include "iterator/reverse_iterable.h"
#include "doubly_linked_list_reverse_iterator.h"
#include "list/access/back_popable.h"
#include "list/access/back_pushable.h"
#include "list/access/front_popable.h"
#include "list/access/front_pushable.h"
#include <memory>

template <typename T>
/**
 * @brief The DoublyLinkedList class represents doubly-linked list.
 *
 * DoublyLinkedList is a container. It's possible to iterate through it in
 * straight and in reverse orders. You can push to and pop from
 * back and front of this list.
 */
class DoublyLinkedList :
    public Container,
    public IterableList<T, DoublyLinkedListIterator<T>>,
    public ReverseIterable<T, DoublyLinkedListReverseIterator<T>>,
    public BackPopable<T>,
    public BackPushable<T>,
    public FrontPopable<T>,
    public FrontPushable<T> {

public:

    /** Type of straight iterator. */
    typedef DoublyLinkedListIterator<T> iterator;

    /** Type of reverse iterator. */
    typedef DoublyLinkedListReverseIterator<T> reverse_iterator;

private:

    /** Type of node, that uses this list. */
    typedef BidirectionalNode<T> Node;

    /** Type of node pointer. */
    typedef std::shared_ptr<Node> NodePtr;

    NodePtr head; /**< Pointer to head node. */

    NodePtr tail; /**< Pointer to tail node. */

    /**
     * Throws ContainerException if specified iterator is incorrect.
     */
    void check_iterator(const iterator& it);

public:

    /**
     * Default DoublyLinkedList constructor.
     */
    DoublyLinkedList();

    /**
     * DoublyLinkedList destructor.
     */
    virtual ~DoublyLinkedList() override;

    iterator begin() const override;

    iterator end() const override;

    reverse_iterator rbegin() const override;

    reverse_iterator rend() const override;

    iterator find(const T& value) const override;

    void insert(const iterator& it, const T& value) override;

    void erase(const iterator& it) override;

    void push_front(const T& value) override;

    void push_back(const T& value) override;

    T& front() const override;

    T& back() const override;

    void pop_front() override;

    void pop_back() override;

};

#include "doubly_linked_list.tpp"

#endif // DOUBLY_LINKED_LIST_H
