#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "forward_iterator.h"

template <typename T>
/**
 * @brief The BidirectionalIterator class is an interface
 * for bidirectional iterators.
 */
struct BidirectionalIterator : ForwardIterator<T> {

    /**
     * Shifts iterator to the previous position.
     * @return This iterator.
     */
    virtual BidirectionalIterator& operator -- () = 0;

};

#endif // BIDIRECTIONAL_ITERATOR_H
