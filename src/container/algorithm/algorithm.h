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
/**
 * @brief The Algorithm class contains methods, that extend using containers.
 *
 * This class uses SFINAE approach. It determines possibility to use a method
 * according to ContainerType and ValueType.
 */
struct Algorithm {

    /** Type of container iterator. */
    typedef typename ContainerType<ValueType>::iterator IteratorType;

    template <typename ForwardIteratorType = IteratorType>
    /**
     * @brief Calls specified function for specified elements.
     *
     * Container must have an iterator, that is inherited from ForwardIterator.
     * @param start_iterator - iterator to the start element.
     * @param finish_iterator - iterator to element after the last.
     * @param call_back_function - function to call.
     */
    static typename std::enable_if<
    std::is_base_of<ForwardIterator<ValueType>, ForwardIteratorType>::value &&
    std::is_same<ForwardIteratorType, IteratorType>::value,
    void>::type
    for_each(const IteratorType& start_iterator,
             const IteratorType& finish_iterator,
             const std::function<void(ValueType&)>& call_back_function);

    template <typename ForwardIteratorType = IteratorType>
    /**
     * @brief Checks condition for specified elements.
     *
     * Container must have an iterator, that is inherited from ForwardIterator.
     * @param start_iterator - iterator to the start element.
     * @param finish_iterator - iterator to element after the last.
     * @param condition_function - function, that returns true if condition
     * is true and false otherwise.
     * @return Number of elements, for which condition_function returns true.
     */
    static typename std::enable_if<
    std::is_base_of<ForwardIterator<ValueType>, ForwardIteratorType>::value &&
    std::is_same<ForwardIteratorType, IteratorType>::value,
    unsigned int>::type
    count_if(const IteratorType& start_iterator,
             const IteratorType& finish_iterator,
             const std::function<bool(const ValueType&)>& condition_function);

    template <typename BidirectionalIteratorType = IteratorType>
    /**
     * @brief Reverses elements in specified range.
     *
     * Container must have an iterator,
     * that is inherited from BidirectionalIterator.
     * @param start_iterator - iterator to the start element.
     * @param finish_iterator - iterator to element after the last.
     * @return
     */
    static typename std::enable_if<
    std::is_base_of<BidirectionalIterator<ValueType>, BidirectionalIteratorType>::value &&
    std::is_same<BidirectionalIteratorType, IteratorType>::value,
    void>::type
    reverse(const IteratorType& start_iterator,
            const IteratorType& finish_iterator);

    template <typename ForwardIteratorType = IteratorType,
    typename ComparableValueType = ValueType>
    /**
     * @brief Finds the minimum element of specified elements.
     *
     * Container must have an iterator, that is inherited from ForwardIterator.
     * ValueType must override operator less (<) or it's primitive type.
     * @param start_iterator - iterator to the start element.
     * @param finish_iterator - iterator to element after the last.
     * @return Iterator to the minimum element.
     */
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
    /**
     * @brief Finds the maximum element of specified elements.
     *
     * Container must have an iterator, that is inherited from ForwardIterator.
     * ValueType must override operator less (<) or it's primitive type.
     * @param start_iterator - iterator to the start element.
     * @param finish_iterator - iterator to element after the last.
     * @return Iterator to the maximum element.
     */
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
