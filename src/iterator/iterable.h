#ifndef ITERABLE_H
#define ITERABLE_H

#include "forward_iterator.h"
#include <type_traits>

template <typename ValueType, typename IteratorType>
struct Iterable {

    static_assert(std::is_base_of<ForwardIterator<ValueType>, IteratorType>::value,
        "IteratorType must be inherited from ForwardIterator!");

    virtual IteratorType begin() const = 0;

    virtual IteratorType end() const = 0;

};

#endif // ITERABLE_H
