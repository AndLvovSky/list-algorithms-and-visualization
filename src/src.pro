#-------------------------------------------------
#
# Project created by QtCreator 2019-04-15T15:21:26
#
#-------------------------------------------------

QT       -= gui

TARGET = src
TEMPLATE = lib

DEFINES += SRC_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    list/node/bidirectional_node.tpp \
    list/node/forward_node.tpp \
    list/container/doubly_linked_list/doubly_linked_list.tpp \
    container/container.tpp\
    list/container/doubly_linked_list/doubly_linked_list_iterator.tpp\
    list/container/doubly_linked_list/doubly_linked_list_reverse_iterator.tpp\
    list/container/doubly_linked_list/doubly_linked_list_abstract_iterator.tpp\
    list/container/array_list/array_list_iterator.tpp\
    list/container/array_list/array_list.tpp

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
    list/access/random_accessible.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

SUBDIRS += \
    src.pro
