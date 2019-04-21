#ifndef BIDIRECTIONAL_NODE_H
#define BIDIRECTIONAL_NODE_H

#include "node.h"
#include <memory>

template <typename T>
class BidirectionalNode : public Node<T> {

private:

    T __value;

public:

    typedef std::shared_ptr<BidirectionalNode<T>> NodePtr;

    NodePtr prev;

    NodePtr next;

    BidirectionalNode(const T& value);

    BidirectionalNode(const T& value, NodePtr prev, NodePtr next);

    T& value() override;

};

#include "bidirectional_node.tpp"

#endif // BIDIRECTIONAL_NODE_H
