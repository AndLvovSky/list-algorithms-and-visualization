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
