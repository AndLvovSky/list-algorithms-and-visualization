#ifndef ARRAY_LIST_ITERATOR
#define ARRAY_LIST_ITERATOR

#include "iterator/bidirectional_iterator.h"
#include "list/access/random_accessible.h"

template <typename T>
class ArrayListIterator : public BidirectionalIterator<T> {

protected:

    int current;

    const RandomAccessible<T>& list;

    template <typename> friend class ArrayList;

public:

    ArrayListIterator(int current, const RandomAccessible<T>& list);

    virtual ~ArrayListIterator();

    T& operator * () const override;

    bool operator == (const ForwardIterator<T>& it) const override;

    bool operator != (const ForwardIterator<T>& it) const override;

    virtual ArrayListIterator& operator ++ () override;

    virtual ArrayListIterator& operator -- () override;

    int operator - (const ArrayListIterator& it);

    ArrayListIterator operator + (int delta);

};

#include "array_list_iterator.tpp"

#endif // ARRAY_LIST_ITERATOR
