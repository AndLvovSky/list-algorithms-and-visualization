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
    lists/auxiliary/nodes/bidirectional_node.tpp \
    lists/auxiliary/nodes/forward_node.tpp \
    lists/doubly_linked_list/doubly_linked_list.tpp \
    container/container.tpp\
    lists/doubly_linked_list/doubly_linked_list_iterator.tpp\
    lists/doubly_linked_list/doubly_linked_list_reverse_iterator.tpp\
    lists/doubly_linked_list/doubly_linked_list_abstract_iterator.tpp

HEADERS += \
    lists/auxiliary/iterators/iterable_list.h \
    lists/auxiliary/nodes/bidirectional_node.h \
    lists/auxiliary/nodes/forward_node.h \
    lists/auxiliary/nodes/node.h \
    container/container.h \
    lists/doubly_linked_list/doubly_linked_list.h \
    lists/auxiliary/iterators/forward_iterator.h \
    lists/auxiliary/iterators/bidirectional_iterator.h \
    lists/auxiliary/iterators/random_access_iterator.h \
    lists/auxiliary/iterators/iterable.h \
    lists/doubly_linked_list/doubly_linked_list_iterator.h \
    lists/auxiliary/iterators/reverse_iterable.h \
    lists/doubly_linked_list/doubly_linked_list_abstract_iterator.h \
    lists/doubly_linked_list/doubly_linked_list_reverse_iterator.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

SUBDIRS += \
    src.pro
