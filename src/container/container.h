#ifndef CONTAINER_H
#define CONTAINER_H

class Container {

public:

    typedef int SizeType;

private:

    SizeType size;

    bool safe = false;

protected:

    virtual void set_size(SizeType size);

    virtual void inc_size();

    virtual void dec_size();

    virtual void check_not_empty() const;

public:

    Container();

    Container(SizeType start_size);

    virtual ~Container();

    virtual SizeType get_size() const;

    virtual bool is_empty() const;

    virtual void set_safety(bool safe);

    virtual bool is_safe() const;

};

#endif // CONTAINER_H
