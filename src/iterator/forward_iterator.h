#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H


template <typename T>
/**
 * @brief The ForwardIterator class is an interface for all iterators.
 */
struct ForwardIterator {

    /**
     * Shifts iterator to the next position.
     * @return This iterator.
     */
    virtual ForwardIterator& operator ++ () = 0;

    /**
     * @return Value pointed to by the iterator.
     */
    virtual T& operator * () const = 0;

    /**
     * @param it - other iterator.
     * @return True if iterators are equal, false otherwise.
     */
    virtual bool operator == (const ForwardIterator& it) const = 0;

    /**
     * @param it - other iterator.
     * @return True if iterators are not equal, false otherwise.
     */
    virtual bool operator != (const ForwardIterator& it) const = 0;

    /**
     * Assignment operator.
     * @param it - other iterator.
     * @return This iterator.
     */
    virtual ForwardIterator& operator = (const ForwardIterator& it) = 0;

};

#endif // FORWARD_ITERATOR_H
