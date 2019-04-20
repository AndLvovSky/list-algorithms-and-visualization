#include "algorithm.h"
#include <type_traits>
#include <functional>

template <template <typename ...Args> class ContainerType, typename ValueType>
typename std::enable_if<std::is_base_of<ForwardIterator<ValueType>,
typename ContainerType<ValueType>::iterator>::value, void>::type
Algorithm<ContainerType, ValueType>::
for_each(const IteratorType& start_iterator,
         const IteratorType& finish_iterator,
         const std::function<void(ValueType&)>& call_back_function) {
    for (auto it = start_iterator; it != finish_iterator; ++it) {
        call_back_function(*it);
    }
}

template <template <typename ...Args> class ContainerType, typename ValueType>
typename std::enable_if<std::is_base_of<ForwardIterator<ValueType>,
typename ContainerType<ValueType>::iterator>::value, unsigned int>::type
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
typename std::enable_if<std::is_base_of<BidirectionalIterator<ValueType>,
typename ContainerType<ValueType>::iterator>::value, void>::type
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
