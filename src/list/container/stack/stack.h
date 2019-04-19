#ifndef STACK_H
#define STACK_H

#include "container/container.h"
#include "list/access/back_popable.h"
#include "list/access/back_pushable.h"
#include "list/node/forward_node.h"
#include <memory>

template <typename T>
class Stack :
    public Container,
    public BackPopable<T>,
    public BackPushable<T> {

private:

    typedef ForwardNode<T> Node;

    typedef std::shared_ptr<Node> NodePtr;

    NodePtr tail;

public:

    Stack();

    virtual ~Stack() override;

    void push_back(const T& value) override;

    T& back() const override;

    void pop_back() override;

};

#include "stack.tpp"

#endif // STACK_H
