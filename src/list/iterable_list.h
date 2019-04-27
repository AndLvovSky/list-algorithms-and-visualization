#ifndef ITERABLE_LIST_H
#define ITERABLE_LIST_H

#include "iterator/forward_iterator.h"
#include "iterator/iterable.h"

template <typename ValueType, typename IteratorType>
/**
 * @brief The IterableList class is an interface for list-like containers
 * through which its possible to iterate.
 */
struct IterableList : Iterable<ValueType, IteratorType> {

    /**
     * @param value - value to search.
     * @return Iterator that is pointed to specified value.
     */
    virtual IteratorType find(const ValueType& value) const = 0;

    /**
     * Inserts element to the list with specified value before position
     * pointed to by specified iterator.
     * @param it - iterator where to insert the value.
     * @param value - value to insert.
     */
    virtual void insert(const IteratorType& it, const ValueType& value) = 0;

    /**
     * Erases element pointed to by specified iterator.
     * @param it - iterator where to erase the element.
     */
    virtual void erase(const IteratorType& it) = 0;

};

#endif // ITERABLE_LIST_H
