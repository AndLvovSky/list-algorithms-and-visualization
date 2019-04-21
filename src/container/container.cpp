#include "container.h"
#include "container/exception/container_exception.h"

Container::Container() {
    this->size = 0;
}

Container::Container(int start_size) {
    this->size = start_size;
}

Container::~Container() {}

int Container::get_size() const {
    return size;
}

bool Container::is_empty() const {
    return size == 0;
}

void Container::set_size(SizeType size) {
    this->size = size;
}

void Container::inc_size() {
    this->size++;
}

void Container::dec_size() {
    this->size--;
}

void Container::set_safety(bool safe) {
    this->safe = safe;
}

bool Container::is_safe() const {
    return this->safe;
}

void Container::check_not_empty() const {
    if (is_empty()) {
        throw ContainerException("Container is empty!");
    }
}
