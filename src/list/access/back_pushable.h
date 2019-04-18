#ifndef BACK_PUSHABLE_LIST_H
#define BACK_PUSHABLE_LIST_H

template <typename T>
struct BackPushable {

    virtual void push_back(const T& value) = 0;

};

#endif // BACK_PUSHABLE_H
