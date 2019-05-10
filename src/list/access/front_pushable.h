#ifndef FRONT_PUSHABLE_H
#define FRONT_PUSHABLE_H

template <typename T>
/**
 * @brief The FrontPushable class is an interface for containers,
 * in which its possible to add an element to the front.
 */
struct FrontPushable {

    /**
     * Add specified element to the front.
     * @param value - value to add.
     * @return *this.
     */
    virtual FrontPushable& push_front(const T& value) = 0;

};

#endif // FRONT_PUSHABLE_H
