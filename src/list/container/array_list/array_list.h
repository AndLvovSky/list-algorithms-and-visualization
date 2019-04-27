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
/**
 * @brief The ArrayList class represents array list.
 *
 * ArrayList is a container. It's possible to iterate through it in
 * straight order. You can push to and pop from back of this list.
 * Every element is accesible with constant time.
 */
class ArrayList :
        public Container,
        public IterableList<T, ArrayListIterator<T>>,
        public BackPopable<T>,
        public BackPushable<T>,
        public RandomAccessible<T> {

public:

    /** Type of straight iterator. */
    typedef ArrayListIterator<T> iterator;

private:

    T* values = new T[1]; /**< Array in which values are located. */

    int capacity = 1; /**< Current capacity. */

    /**
     * Enlarges list to specified capacity.
     */
    void enlarge(int capacity);

    /**
     * Throws exception if specified iterator is incorrect.
     */
    void check_iterator(const iterator& it) const;

    /**
     * Throws exception if specified size is incorrect.
     */
    void check_size(int size) const;

public:

    /**
     * Default ArrayList constructor.
     */
    ArrayList();

    /**
     * Initializes ArrayList with elements of specified initializer list.
     * @param init_list - elements to set.
     */
    ArrayList(const std::initializer_list<T>& init_list);

    /**
     * ArrayList destrcutor.
     */
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

    /**
     * @return Current capacity.
     *
     * It's not the same with size. You have access to elements in
     * positions beetween size and capacity, but their values are undefined.
     */
    int get_capacity();

    /**
     * Changes list size to the specified.
     * @param size
     */
    void resize(int size);

    bool operator == (const ArrayList& other) const;

    bool operator != (const ArrayList& other) const;

};

#include "array_list.tpp"

#endif // ARRAY_LIST_H
