#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "forward_iterator.h"

template <typename T>
struct BidirectionalIterator : ForwardIterator<T> {

    virtual BidirectionalIterator& operator -- () = 0;

};

#endif // BIDIRECTIONAL_ITERATOR_H
