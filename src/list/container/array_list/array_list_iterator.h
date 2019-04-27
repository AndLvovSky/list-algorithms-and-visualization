#ifndef ARRAY_LIST_ITERATOR
#define ARRAY_LIST_ITERATOR

#include "iterator/bidirectional_iterator.h"
#include "list/access/random_accessible.h"

template <typename T>
/**
 * @brief The ArrayListIterator class represents ArrayList straight iterator.
 */
class ArrayListIterator : public BidirectionalIterator<T> {

private:

    int current; /**< Current position pointed by iterator. */

    /** Reference to ArrayList of this iterator. */
    const RandomAccessible<T>& list;

    template <typename> friend class ArrayList;

public:

    /**
     * Initializes ArrayListIterator of specified list with specified value.
     * @param current - position pointed to by iterator.
     * @param list - reference to ArrayList, that creates this iterator.
     */
    ArrayListIterator(int current, const RandomAccessible<T>& list);

    /**
     * ArrayListIterator destructor.
     */
    virtual ~ArrayListIterator();

    T& operator * () const override;

    bool operator == (const ForwardIterator<T>& it) const override;

    bool operator != (const ForwardIterator<T>& it) const override;

    virtual ArrayListIterator& operator ++ () override;

    virtual ArrayListIterator& operator -- () override;

    /**
     * @return Difference in positions between this and specified iterators.
     */
    int operator - (const ArrayListIterator& it);

    /**
     * @return Iterator to element with position, that is
     * equal to current position plus delta.
     */
    ArrayListIterator operator + (int delta);

    ArrayListIterator& operator = (const ForwardIterator<T>& it) override;

};

#include "array_list_iterator.tpp"

#endif // ARRAY_LIST_ITERATOR
