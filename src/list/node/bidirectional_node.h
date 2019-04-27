#ifndef BIDIRECTIONAL_NODE_H
#define BIDIRECTIONAL_NODE_H

#include "node.h"
#include <memory>

template <typename T>
/**
 * @brief The BidirectionalNode class represents node with a
 * pointer to the next and to the previous nodes.
 */
class BidirectionalNode : public Node<T> {

private:

    T __value; /**< node value */

public:

    /** Node pointer type. */
    typedef std::shared_ptr<BidirectionalNode<T>> NodePtr;

    NodePtr prev; /**< Pointer to the previous node. */

    NodePtr next; /**< Pointer to the next node. */

    /**
     * Initializes node with specified value.
     * @param value - node value.
     */
    BidirectionalNode(const T& value);

    /**
     * Initializes node with specified value and
     * pointer to the next and to the previous nodes.
     * @param value - node value.
     * @param prev - pointer to the previous node.
     * @param next - pointer to the next node.
     */
    BidirectionalNode(const T& value, NodePtr prev, NodePtr next);

    T& value() override;

};

#include "bidirectional_node.tpp"

#endif // BIDIRECTIONAL_NODE_H
