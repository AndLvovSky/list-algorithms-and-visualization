#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "iterator/iterable.h"
#include "iterator/forward_iterator.h"
#include "iterator/bidirectional_iterator.h"
#include "container/sfinae/sfinae_checker.h"
#include <type_traits>
#include <functional>
#include <variant>

template <template <typename ...Args> class ContainerType, typename ValueType>
struct Algorithm {

    typedef typename ContainerType<ValueType>::iterator IteratorType;

    template <typename ForwardIteratorType = IteratorType>
    static typename std::enable_if<
    std::is_base_of<ForwardIterator<ValueType>, ForwardIteratorType>::value &&
    std::is_same<ForwardIteratorType, IteratorType>::value,
    void>::type
    for_each(const IteratorType& start_iterator,
             const IteratorType& finish_iterator,
             const std::function<void(ValueType&)>& call_back_function);

    template <typename ForwardIteratorType = IteratorType>
    static typename std::enable_if<
    std::is_base_of<ForwardIterator<ValueType>, ForwardIteratorType>::value &&
    std::is_same<ForwardIteratorType, IteratorType>::value,
    unsigned int>::type
    count_if(const IteratorType& start_iterator,
             const IteratorType& finish_iterator,
             const std::function<bool(const ValueType&)>& condition_function);

    template <typename BidirectionalIteratorType = IteratorType>
    static typename std::enable_if<
    std::is_base_of<BidirectionalIterator<ValueType>, BidirectionalIteratorType>::value &&
    std::is_same<BidirectionalIteratorType, IteratorType>::value,
    void>::type
    reverse(const IteratorType& start_iterator,
            const IteratorType& finish_iterator);

    template <typename ForwardIteratorType = IteratorType,
    typename ComparableValueType = ValueType>
    static typename std::enable_if<
    std::is_base_of<ForwardIterator<ValueType>, ForwardIteratorType>::value &&
    SFINAEChecker::less_operator_exists<ValueType>() &&
    std::is_same<ForwardIteratorType, IteratorType>::value &&
    std::is_same<ComparableValueType, ValueType>::value,
    IteratorType>::type
    min(const IteratorType& start_iterator,
        const IteratorType& finish_iterator);

    template <typename ForwardIteratorType = IteratorType,
    typename ComparableValueType = ValueType>
    static typename std::enable_if<
    std::is_base_of<ForwardIterator<ValueType>, ForwardIteratorType>::value &&
    SFINAEChecker::less_operator_exists<ValueType>() &&
    std::is_same<ForwardIteratorType, IteratorType>::value &&
    std::is_same<ComparableValueType, ValueType>::value,
    IteratorType>::type
    max(const IteratorType& start_iterator,
        const IteratorType& finish_iterator);

};

#include "algorithm.tpp"

#endif // LIST_ALGORITHM
