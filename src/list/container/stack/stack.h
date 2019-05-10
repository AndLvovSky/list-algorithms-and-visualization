#ifndef STACK_H
#define STACK_H

#include "container/container.h"
#include "list/access/back_popable.h"
#include "list/access/back_pushable.h"
#include "list/node/forward_node.h"
#include <memory>

template <typename T>
/**
 * @brief The Stack class represents stack.
 *
 * Stack is a FIFO (First In First Out) container,
 * that is you can push to back and pop from back of it.
 */
class Stack :
    public Container,
    public BackPopable<T>,
    public BackPushable<T> {

private:

    /** Node type. */
    typedef ForwardNode<T> Node;

    /** Node pointer type. */
    typedef std::shared_ptr<Node> NodePtr;

    NodePtr tail; /**< Pointer to the tail node. */

public:

    /**
     * Default Stack constructor.
     */
    Stack();

    /**
     * Stack destructor.
     */
    virtual ~Stack() override;

    Stack& push_back(const T& value) override;

    T& back() const override;

    Stack& pop_back() override;

};

#include "stack.tpp"

#endif // STACK_H
