#ifndef CONTAINER_EXCEPTION_H
#define CONTAINER_EXCEPTION_H

#include <stdexcept>

struct ContainerException : public std::runtime_error {

    ContainerException(const char* msg);

};

#endif // CONTAINER_EXCEPTION_H
