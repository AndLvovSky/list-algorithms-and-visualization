#ifndef ITERABLE_LIST_H
#define ITERABLE_LIST_H

#include "iterator/forward_iterator.h"
#include "iterator/iterable.h"

template <typename ValueType, typename IteratorType>
struct IterableList : Iterable<ValueType, IteratorType> {

    virtual IteratorType find(const ValueType& value) const = 0;

    virtual void insert(const IteratorType& it, const ValueType& value) = 0;

    virtual void erase(const IteratorType& it) = 0;

};

#endif // ITERABLE_LIST_H
