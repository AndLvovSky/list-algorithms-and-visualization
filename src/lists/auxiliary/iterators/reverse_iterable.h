#ifndef REVERSE_ITERABLE_H
#define REVERSE_ITERABLE_H

#include "forward_iterator.h"
#include <type_traits>

template <typename ValueType, typename IteratorType>
struct ReverseIterable {

    static_assert(std::is_base_of<ForwardIterator<ValueType>, IteratorType>::value,
        "IteratorType must be inhererited from ForwardIterator!");

    virtual IteratorType rbegin() const = 0;

    virtual IteratorType rend() const = 0;

};

#endif // REVERSE_ITERABLE_H
