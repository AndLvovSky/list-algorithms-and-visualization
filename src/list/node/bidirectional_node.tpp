#include "bidirectional_node.h"

template <typename T>
BidirectionalNode<T>::BidirectionalNode(const T& value) {
    __value = value;
}

template <typename T>
BidirectionalNode<T>::BidirectionalNode(
    const T& value, NodePtr prev, NodePtr next) :
    BidirectionalNode(value) {
    this->prev = prev;
    this->next = next;
}

template <typename T>
T& BidirectionalNode<T>::value() {
    return __value;
}
