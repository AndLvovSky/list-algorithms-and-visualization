#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "container/container.h"
#include "list/iterable_list.h"
#include "list/node/bidirectional_node.h"
#include "iterator/reverse_iterable.h"
#include "list/access/back_popable.h"
#include "list/access/back_pushable.h"
#include "list/access/front_popable.h"
#include "list/access/front_pushable.h"
#include "list/access/random_accessible.h"
#include "list/container/doubly_linked_list/doubly_linked_list_reverse_iterator.h"
#include "iterator/reverse_iterable.h"
#include "array_list_iterator.h"

template <typename T>
class ArrayList :
        public Container,
        public IterableList<T, ArrayListIterator<T>>,
        public BackPopable<T>,
        public BackPushable<T>,
        public RandomAccessible<T> {

protected:

    T* values;

    int capacity;

    void enlarge(int capacity);

public:

    typedef ArrayListIterator<T> iterator;

    ArrayList();

    virtual ~ArrayList() override;

    iterator begin() const override;

    iterator end() const override;

    iterator find(const T& value) const override;

    void insert(const iterator& it, const T& value) override;

    void erase(const iterator& it) override;

    void push_back(const T& value) override;

    T& back() const override;

    void pop_back() override;

    T& operator [] (int pos) const override;

    int get_capacity();

    void resize(int size);

};

#include "array_list.tpp"

#endif // ARRAY_LIST_H
