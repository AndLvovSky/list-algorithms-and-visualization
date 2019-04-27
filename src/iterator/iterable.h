#ifndef ITERABLE_H
#define ITERABLE_H

#include "forward_iterator.h"
#include <type_traits>

template <typename ValueType, typename IteratorType>
/**
 * @brief The Iterable class is an interface for containers,
 * through which its possible to iterate in the straight order.
 *
 * Its possible to use range-base for loop for such containers.
 * Container must have its iterator inherited by ForwardIterator.
 */
struct Iterable {

    static_assert(std::is_base_of<ForwardIterator<ValueType>,
        IteratorType>::value,
        "IteratorType must be inherited from ForwardIterator!");

    /**
     * @return Iterator to the first element in the container.
     */
    virtual IteratorType begin() const = 0;

    /**
     * @return Iterator to the position after last element in the container.
     */
    virtual IteratorType end() const = 0;

};

#endif // ITERABLE_H
