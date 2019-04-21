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

public:

    typedef ArrayListIterator<T> iterator;

protected:

    T* values = new T[1];

    int capacity = 1;

    void enlarge(int capacity);

    void check_iterator(const iterator& it) const;

    void check_size(int size) const;

public:

    ArrayList();

    ArrayList(const std::initializer_list<T>& init_list);

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

    bool operator == (const ArrayList& other) const;

    bool operator != (const ArrayList& other) const;

};

#include "array_list.tpp"

#endif // ARRAY_LIST_H
