#ifndef FRONT_POPABLE_H
#define FRONT_POPABLE_H

template <typename T>
/**
 * @brief The FrontPopable class is an interface for containers,
 * in which its possible to delete an element from the front.
 */
struct FrontPopable {

    /**
     * Delete the first element.
     * @return *this.
     */
    virtual FrontPopable& pop_front() = 0;

    /**
     * @return First element.
     */
    virtual T& front() const = 0;

};


#endif // FRONT_POPABLE_H
