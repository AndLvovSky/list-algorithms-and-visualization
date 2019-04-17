#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node {

    virtual T& value() = 0;

};

#endif // NODE_H
