#include "algorithm.h"
#include <type_traits>
#include <functional>

template <template <typename ...Args> class ContainerType, typename ValueType>
template <typename ForwardIteratorType>
typename std::enable_if<
std::is_base_of<ForwardIterator<ValueType>, ForwardIteratorType>::value &&
std::is_same<ForwardIteratorType, typename ContainerType<ValueType>::iterator>::value,
void>::type
Algorithm<ContainerType, ValueType>::
for_each(const IteratorType& start_iterator,
         const IteratorType& finish_iterator,
         const std::function<void(ValueType&)>& call_back_function) {
    for (auto it = start_iterator; it != finish_iterator; ++it) {
        call_back_function(*it);
    }
}

template <template <typename ...Args> class ContainerType, typename ValueType>
template <typename ForwardIteratorType>
typename std::enable_if<
std::is_base_of<ForwardIterator<ValueType>, ForwardIteratorType>::value &&
std::is_same<ForwardIteratorType, typename ContainerType<ValueType>::iterator>::value,
unsigned int>::type
Algorithm<ContainerType, ValueType>::
count_if(const IteratorType& start_iterator,
         const IteratorType& finish_iterator,
         const std::function<bool(const ValueType&)>& condition_function) {
    auto count = 0U;
    for (auto it = start_iterator; it != finish_iterator; ++it) {
        if (condition_function(*it)) {
            count++;
        }
    }
    return count;
}

template <template <typename ...Args> class ContainerType, typename ValueType>
template <typename BidirectionalIteratorType>
typename std::enable_if<
std::is_base_of<BidirectionalIterator<ValueType>, BidirectionalIteratorType>::value &&
std::is_same<BidirectionalIteratorType, typename ContainerType<ValueType>::iterator>::value,
void>::type
Algorithm<ContainerType, ValueType>::
reverse(const IteratorType& start_iterator,
        const IteratorType& finish_iterator) {
    auto left_it = start_iterator;
    auto right_it = finish_iterator;
    --right_it;
    while (left_it != right_it) {
        std::swap(*left_it, *right_it);
        ++left_it;
        if (*left_it == *right_it) break;
        --right_it;
    }
}

template <template <typename ...Args> class ContainerType, typename ValueType>
template <typename ForwardIteratorType, typename ComparableValueType>
typename std::enable_if<
std::is_base_of<ForwardIterator<ValueType>, ForwardIteratorType>::value &&
SFINAEChecker::less_operator_exists<ValueType>() &&
std::is_same<ForwardIteratorType, typename ContainerType<ValueType>::iterator>::value &&
std::is_same<ComparableValueType, ValueType>::value,
typename ContainerType<ValueType>::iterator>::type
Algorithm<ContainerType, ValueType>::
min(const IteratorType& start_iterator,
    const IteratorType& finish_iterator) {
    auto min_it = start_iterator;
    for (auto it = start_iterator; it != finish_iterator; ++it) {
        if (*it < *min_it) {
            min_it = static_cast<const ForwardIterator<ValueType>&>(it);
        }
    }
    return min_it;
}

template <template <typename ...Args> class ContainerType, typename ValueType>
template <typename ForwardIteratorType, typename ComparableValueType>
typename std::enable_if<
std::is_base_of<ForwardIterator<ValueType>, ForwardIteratorType>::value &&
SFINAEChecker::less_operator_exists<ValueType>() &&
std::is_same<ForwardIteratorType, typename ContainerType<ValueType>::iterator>::value &&
std::is_same<ComparableValueType, ValueType>::value,
typename ContainerType<ValueType>::iterator>::type
Algorithm<ContainerType, ValueType>::
max(const IteratorType& start_iterator,
    const IteratorType& finish_iterator) {
    auto min_it = start_iterator;
    for (auto it = start_iterator; it != finish_iterator; ++it) {
        if (*min_it < *it) {
            min_it = static_cast<const ForwardIterator<ValueType>&>(it);
        }
    }
    return min_it;
}
