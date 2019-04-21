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
class Deque :
    public Container,
    public BackPopable<T>,
    public BackPushable<T>,
    public FrontPopable<T>,
    public FrontPushable<T> {

protected:

    typedef BidirectionalNode<T> Node;

    typedef std::shared_ptr<Node> NodePtr;

    NodePtr head;

    NodePtr tail;

public:

    Deque();

    virtual ~Deque() override;

    void push_front(const T& value) override;

    void push_back(const T& value) override;

    void pop_front() override;

    void pop_back() override;

    T& front() const override;

    T& back() const override;

};

#include "deque.tpp"

#endif // STACK_H
