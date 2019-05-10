#ifndef BACK_PUSHABLE_LIST_H
#define BACK_PUSHABLE_LIST_H

template <typename T>
/**
 * @brief The BackPushable class is an interface for containers,
 * in which its possible to add an element to the back.
 */
struct BackPushable {

    /**
     * Add specified element to the back.
     * @param value - value to add.
     * @return *this.
     */
    virtual BackPushable& push_back(const T& value) = 0;

};

#endif // BACK_PUSHABLE_H
