#ifndef FORWARD_NODE_H
#define FORWARD_NODE_H

#include "node.h"
#include <memory>

template <typename T>
/**
 * @brief The ForwardNode class represents node with a
 * pointer to the next node.
 */
class ForwardNode : public Node<T> {

private:

    T __value; /**< node value */

public:

    /** Node pointer type. */
    typedef std::shared_ptr<ForwardNode<T>> NodePtr;

    NodePtr next; /**< Pointer to the next node. */

    /**
     * Initializes node with specified value.
     * @param value - node value.
     */
    ForwardNode(const T& value);

    /**
     * Initializes node with specified value and pointer to the next node.
     * @param value - node value.
     * @param next - pointer to the next node.
     */
    ForwardNode(const T& value, NodePtr next);

    T& value() override;

};

#include "forward_node.tpp"

#endif // FORWARD_NODE_H
