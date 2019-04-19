#-------------------------------------------------
#
# Project created by QtCreator 2019-04-15T15:21:26
#
#-------------------------------------------------

QT       -= gui

TARGET = listlib

TEMPLATE = lib

SOURCES += \
    list/node/bidirectional_node.tpp \
    list/node/forward_node.tpp \
    list/container/doubly_linked_list/doubly_linked_list.tpp \
    list/container/doubly_linked_list/doubly_linked_list_iterator.tpp\
    list/container/doubly_linked_list/doubly_linked_list_reverse_iterator.tpp\
    list/container/doubly_linked_list/doubly_linked_list_abstract_iterator.tpp\
    list/container/array_list/array_list_iterator.tpp\
    list/container/array_list/array_list.tpp \
    container/container.cpp\
    list/container/stack/stack.tpp\
    list/container/queue/queue.tpp\
    list/container/deque/deque.tpp\

HEADERS += \
    list/iterable_list.h \
    list/node/bidirectional_node.h \
    list/node/forward_node.h \
    list/node/node.h \
    container/container.h \
    list/container/doubly_linked_list/doubly_linked_list.h \
    iterator/forward_iterator.h \
    iterator/bidirectional_iterator.h \
    iterator/iterable.h \
    list/container/doubly_linked_list/doubly_linked_list_iterator.h \
    iterator/reverse_iterable.h \
    list/container/doubly_linked_list/doubly_linked_list_abstract_iterator.h \
    list/container/doubly_linked_list/doubly_linked_list_reverse_iterator.h\
    list/access/back_pushable.h\
    list/access/front_pushable.h \
    list/access/back_popable.h \
    list/access/front_popable.h\
    list/container/array_list/array_list_iterator.h \
    list/container/array_list/array_list.h \
    list/access/random_accessible.h\
    list/container/stack/stack.h\
    list/container/queue/queue.h\
    list/container/deque/deque.h\

unix {
    target.path = /usr/lib
    INSTALLS += target
}
