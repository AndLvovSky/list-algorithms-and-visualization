#ifndef CONTAINER_H
#define CONTAINER_H

class Container {

public:

    typedef int SizeType;

private:

    SizeType size;

protected:

    virtual void set_size(SizeType size);

    virtual void inc_size();

    virtual void dec_size();

public:

    Container();

    Container(SizeType start_size);

    virtual ~Container();

    virtual SizeType get_size() const;

    virtual bool is_empty() const;

};

#include "container.tpp"

#endif // CONTAINER_H
