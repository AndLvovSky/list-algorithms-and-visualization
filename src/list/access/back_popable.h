#ifndef BACK_POPABLE_H
#define BACK_POPABLE_H

template <typename T>
struct BackPopable {

    virtual void pop_back() = 0;

    virtual T& back() const = 0;

};

#endif // BACK_POPABLE_H
