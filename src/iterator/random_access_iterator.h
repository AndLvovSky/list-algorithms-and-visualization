#ifndef RANDOM_ACCESS_ITERATOR_H
#define RANDOM_ACCESS_ITERATOR_H

#include "bidirectional_iterator.h"

template <typename T>
struct RandomAccessIterator : BidirectionalIterator<T> {

   virtual T& operator [] (int pos) const = 0;

};

#endif // RANDOM_ACCESS_ITERATOR_H
