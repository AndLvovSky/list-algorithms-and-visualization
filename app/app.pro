#-------------------------------------------------
#
# Project created by QtCreator 2019-04-15T15:51:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

INCLUDEPATH += $$PWD/../src

SOURCES += \
        main.cpp \
        main_window.cpp \
    listdecorator.cpp \
    listitem.cpp \
    arrow.cpp \
    appcontext.cpp \
    guiblocker.cpp

HEADERS += \
        main_window.h \
    listdecorator.h \
    listitem.h \
    arrow.h \
    point.h \
    appcontext.h \
    guiblocker.h

FORMS += \
        main_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


SOURCES += \
    $$PWD/../src/list/node/bidirectional_node.tpp \
    $$PWD/../src/list/node/forward_node.tpp \
    $$PWD/../src/list/container/doubly_linked_list/doubly_linked_list.tpp \
    $$PWD/../src/list/container/doubly_linked_list/doubly_linked_list_iterator.tpp\
    $$PWD/../src/list/container/doubly_linked_list/doubly_linked_list_reverse_iterator.tpp\
    $$PWD/../src/list/container/doubly_linked_list/doubly_linked_list_abstract_iterator.tpp\
    $$PWD/../src/list/container/array_list/array_list_iterator.tpp\
    $$PWD/../src/list/container/array_list/array_list.tpp \
    $$PWD/../src/container/container.cpp\
    $$PWD/../src/list/container/stack/stack.tpp\
    $$PWD/../src/list/container/queue/queue.tpp\
    $$PWD/../src/list/container/deque/deque.tpp\
    $$PWD/../src/container/algorithm/algorithm.tpp \
    $$PWD/../src/container/exception/container_exception.cpp

HEADERS += \
    $$PWD/../src/list/iterable_list.h \
    $$PWD/../src/list/node/bidirectional_node.h \
    $$PWD/../src/list/node/forward_node.h \
    $$PWD/../src/list/node/node.h \
    $$PWD/../src/container/container.h \
    $$PWD/../src/list/container/doubly_linked_list/doubly_linked_list.h \
    $$PWD/../src/iterator/forward_iterator.h \
    $$PWD/../src/iterator/bidirectional_iterator.h \
    $$PWD/../src/iterator/iterable.h \
    $$PWD/../src/list/container/doubly_linked_list/doubly_linked_list_iterator.h \
    $$PWD/../src/iterator/reverse_iterable.h \
    $$PWD/../src/list/container/doubly_linked_list/doubly_linked_list_abstract_iterator.h \
    $$PWD/../src/list/container/doubly_linked_list/doubly_linked_list_reverse_iterator.h\
    $$PWD/../src/list/access/back_pushable.h\
    $$PWD/../src/list/access/front_pushable.h \
    $$PWD/../src/list/access/back_popable.h \
    $$PWD/../src/list/access/front_popable.h\
    $$PWD/../src/list/container/array_list/array_list_iterator.h \
    $$PWD/../src/list/container/array_list/array_list.h \
    $$PWD/../src/list/access/random_accessible.h\
    $$PWD/../src/list/container/stack/stack.h\
    $$PWD/../src/list/container/queue/queue.h\
    $$PWD/../src/list/container/deque/deque.h\
    $$PWD/../src/container/algorithm/algorithm.h\
    $$PWD/../src/container/sfinae/sfinae_checker.h \
    $$PWD/../src/container/exception/container_exception.h

INCLUDEPATH += $$PWD/../src

DEPENDPATH += $$PWD/../src

DESTDIR = $$OUT_PWD/../src/debug/
