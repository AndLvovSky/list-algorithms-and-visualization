#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "iterator/iterable.h"
#include "iterator/forward_iterator.h"
#include "iterator/bidirectional_iterator.h"
#include <type_traits>
#include <functional>
#include <variant>

template <template <typename ...Args> class ContainerType, typename ValueType>
struct Algorithm {

    typedef typename ContainerType<ValueType>::iterator IteratorType;

    static typename std::enable_if<
    std::is_base_of<ForwardIterator<ValueType>, IteratorType>::value,
    void>::type
    for_each(const IteratorType& start_iterator,
             const IteratorType& finish_iterator,
             const std::function<void(ValueType&)>& call_back_function);

    static typename std::enable_if<
    std::is_base_of<ForwardIterator<ValueType>, IteratorType>::value,
    unsigned int>::type
    count_if(const IteratorType& start_iterator,
             const IteratorType& finish_iterator,
             const std::function<bool(const ValueType&)>& condition_function);

    static typename std::enable_if<
    std::is_base_of<BidirectionalIterator<ValueType>, IteratorType>::value,
    void>::type
    reverse(const IteratorType& start_iterator,
            const IteratorType& finish_iterator);

};

#include "algorithm.tpp"

#endif // LIST_ALGORITHM
