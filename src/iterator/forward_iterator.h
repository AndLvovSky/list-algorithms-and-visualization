#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

template <typename T>
struct ForwardIterator {

    virtual ForwardIterator& operator ++ () = 0;

    virtual T& operator * () const = 0;

    virtual bool operator == (const ForwardIterator& it) const = 0;

    virtual bool operator != (const ForwardIterator& it) const = 0;

    virtual ForwardIterator& operator = (const ForwardIterator& it) = 0;

};

#endif // FORWARD_ITERATOR_H
