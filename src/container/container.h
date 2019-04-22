#ifndef CONTAINER_H
#define CONTAINER_H

/**
 * @brief The Container class represents all containers.
 *
 * Every container has a size, that is a number of its elements,
 * and it can be used in the two modes: safe and not safe.
 * In the safe mode incorrect parameters lead to
 * throwing ContainerException, otherwise it will be undefined behavior.
 */
class Container {

public:

    typedef int SizeType; /**< Type of container size. */

private:

    SizeType size; /**< size of the container */

    bool safe = false; /**< is mode safe */

protected:

    /**
     * @param size - size to set.
     */
    virtual void set_size(SizeType size);

    /**
     * Increases container size by one.
     */
    virtual void inc_size();

    /**
     * Decreases container size by one.
     */
    virtual void dec_size();

    /**
     * Throws ContainerException if container is empty.
     */
    virtual void check_not_empty() const;

public:

    /**
     * Default container constructor.
     */
    Container();

    /**
     * Initializes container with specified start size.
     * @param start_size - start size of the container.
     */
    Container(SizeType start_size);

    /**
     * Container destructor.
     */
    virtual ~Container();

    /**
     * @return Current container size.
     */
    virtual SizeType get_size() const;

    /**
     * @return True if container is empty, false otherwise.
     */
    virtual bool is_empty() const;

    /**
     * @param safe - safety mode to set.
     */
    virtual void set_safety(bool safe);

    /**
     * @return True if mode is safe, false otherwise.
     */
    virtual bool is_safe() const;

};

#endif // CONTAINER_H
