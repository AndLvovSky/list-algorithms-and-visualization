#ifndef CONTAINER_EXCEPTION_H
#define CONTAINER_EXCEPTION_H

#include <stdexcept>

/**
 * @brief The ContainerException class
 * is a class for all container's exceptions.
 */
struct ContainerException : public std::runtime_error {

    /**
     * Constructor, that calls base class constructor.
     * @param msg - message to show.
     */
    ContainerException(const char* msg);

};

#endif // CONTAINER_EXCEPTION_H
