#include "container_exception.h"

ContainerException::ContainerException(const char* msg) :
    std::runtime_error(msg) {}
