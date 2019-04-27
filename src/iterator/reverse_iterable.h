#ifndef REVERSE_ITERABLE_H
#define REVERSE_ITERABLE_H

#include "forward_iterator.h"
#include <type_traits>

template <typename ValueType, typename IteratorType>
/**
 * @brief The ReverseIterable class is an interface for containers,
 * through which its possible to iterate in the reverse order.
 *
 * Container must have its iterator inherited by ForwardIterator.
 */
struct ReverseIterable {

    static_assert(std::is_base_of<ForwardIterator<ValueType>,
        IteratorType>::value,
        "IteratorType must be inhererited from ForwardIterator!");

    /**
     * @return Iterator to the last element in the container.
     */
    virtual IteratorType rbegin() const = 0;

    /**
     * @return Iterator to the position before
     * the first element in the container.
     */
    virtual IteratorType rend() const = 0;

};

#endif // REVERSE_ITERABLE_H
