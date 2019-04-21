#ifndef FRONT_PUSHABLE_H
#define FRONT_PUSHABLE_H

template <typename T>
struct FrontPushable {

    virtual void push_front(const T& value) = 0;

};

#endif // FRONT_PUSHABLE_H
