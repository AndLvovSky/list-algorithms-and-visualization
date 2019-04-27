#ifndef STACK_H
#define STACK_H

#include "container/container.h"
#include "list/access/front_popable.h"
#include "list/access/back_pushable.h"
#include "list/node/forward_node.h"
#include <memory>

template <typename T>
/**
 * @brief The Queue class represents queue.
 *
 * Queue is a LIFO (Last In First Out) container,
 * that is you can push to back and pop from front of it.
 */
class Queue :
    public Container,
    public FrontPopable<T>,
    public BackPushable<T> {

private:

    /** Node type. */
    typedef ForwardNode<T> Node;

    /** Node pointer type. */
    typedef std::shared_ptr<Node> NodePtr;

    NodePtr head; /**< Pointer to the head node. */

    NodePtr tail; /**< Pointer to the tail node. */

public:

    /**
     * Default Queue constructor.
     */
    Queue();

    /**
     * Queue destructor.
     */
    virtual ~Queue() override;

    T& front() const override;

    void pop_front() override;

    void push_back(const T& value) override;

};

#include "queue.tpp"

#endif // STACK_H
