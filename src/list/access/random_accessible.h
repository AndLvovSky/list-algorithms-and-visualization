#ifndef RANDOM_ACCESSIBLE_H
#define RANDOM_ACCESSIBLE_H

template <typename T>
/**
 * @brief The RandomAccessible class is an interface for containers,
 * in which its possible to get an element by position.
 */
struct RandomAccessible {

    /**
     * @return Value of the element in specified position.
     */
    virtual T& operator [] (int pos) const = 0;

};

#endif // RANDOM_ACCESSIBLE_H
