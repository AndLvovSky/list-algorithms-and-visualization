#ifndef RANDOM_ACCESSIBLE_H
#define RANDOM_ACCESSIBLE_H

template <typename T>
struct RandomAccessible {

    virtual T& operator [] (int pos) const = 0;

};

#endif // RANDOM_ACCESSIBLE_H
