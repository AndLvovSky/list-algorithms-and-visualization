#include "forward_node.h"

template <typename T>
ForwardNode<T>::ForwardNode(const T& value) : __value(value) {}

template <typename T>
ForwardNode<T>::ForwardNode(const T& value, NodePtr next) :
    ForwardNode(value) {
    this->next = next;
}

template <typename T>
T& ForwardNode<T>::value() {
    return __value;
}
