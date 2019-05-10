#ifndef BACK_POPABLE_H
#define BACK_POPABLE_H

template <typename T>
/**
 * @brief The BackPopable class is an interface for containers,
 * in which its possible to delete an element from the back.
 */
struct BackPopable {

    /**
     * Delete the last element.
     * @return *this.
     */
    virtual BackPopable& pop_back() = 0;

    /**
     * @return Last element.
     */
    virtual T& back() const = 0;

};

#endif // BACK_POPABLE_H
