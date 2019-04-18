#ifndef FRONT_POPABLE_H
#define FRONT_POPABLE_H

template <typename T>
struct FrontPopable {

    virtual void pop_front() = 0;

    virtual T& front() const = 0;

};


#endif // FRONT_POPABLE_H
