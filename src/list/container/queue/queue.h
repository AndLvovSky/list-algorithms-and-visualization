#ifndef STACK_H
#define STACK_H

#include "container/container.h"
#include "list/access/front_popable.h"
#include "list/access/back_pushable.h"
#include "list/node/forward_node.h"
#include <memory>

template <typename T>
class Queue :
    public Container,
    public FrontPopable<T>,
    public BackPushable<T> {

private:

    typedef ForwardNode<T> Node;

    typedef std::shared_ptr<Node> NodePtr;

    NodePtr head;

    NodePtr tail;

public:

    Queue();

    virtual ~Queue() override;

    T& front() const override;

    void pop_front() override;

    void push_back(const T& value) override;

};

#include "queue.tpp"

#endif // STACK_H
