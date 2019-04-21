#ifndef FORWARD_NODE_H
#define FORWARD_NODE_H

#include "node.h"
#include <memory>

template <typename T>
class ForwardNode : public Node<T> {

private:

    T __value;

public:

    typedef std::shared_ptr<ForwardNode<T>> NodePtr;

    NodePtr next;

    ForwardNode(const T& value);

    ForwardNode(const T& value, NodePtr next);

    T& value() override;

};

#include "forward_node.tpp"

#endif // FORWARD_NODE_H
