#ifndef STACK_H
#define STACK_H

#include "container/container.h"
#include "list/access/back_popable.h"
#include "list/access/back_pushable.h"
#include "list/access/front_popable.h"
#include "list/access/front_pushable.h"
#include "list/node/bidirectional_node.h"
#include <memory>

template <typename T>
/**
 * @brief The Deque class represents double-ended queue.
 *
 * Deque is a container.
 * You can push to and pop from back and front of it.
 */
class Deque :
    public Container,
    public BackPopable<T>,
    public BackPushable<T>,
    public FrontPopable<T>,
    public FrontPushable<T> {

private:

    /** Node type */
    typedef BidirectionalNode<T> Node;

    /** Node pointer type */
    typedef std::shared_ptr<Node> NodePtr;

    NodePtr head; /**< Pointer to the head node. */

    NodePtr tail; /**< Pointer to the tail node. */

public:

    /**
     * Default Deque constructor.
     */
    Deque();

    /**
     * Deque destructor.
     */
    virtual ~Deque() override;

    Deque& push_front(const T& value) override;

    Deque& push_back(const T& value) override;

    Deque& pop_front() override;

    Deque& pop_back() override;

    T& front() const override;

    T& back() const override;

};

#include "deque.tpp"

#endif // STACK_H
