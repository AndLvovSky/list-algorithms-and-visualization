#ifndef NODE_H
#define NODE_H

template<typename T>
/**
 * @brief The Node class is an interface for all nodes.
 */
struct Node {

    /**
     * @return Value, that this node keeps.
     */
    virtual T& value() = 0;

};

#endif // NODE_H
