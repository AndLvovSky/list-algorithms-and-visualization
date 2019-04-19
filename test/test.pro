QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \   
    main_test.cpp \
    test_doubly_linked_list.cpp \
    test_array_list.cpp \
    test_stack.cpp \
    test_queue.cpp \
    test_deque.cpp

HEADERS += \
    test_doubly_linked_list.h \
    test_array_list.h \
    test_stack.h \
    test_queue.h \
    test_deque.h

LIBS += -L$$OUT_PWD/../src/debug/ -llistlib

INCLUDEPATH += $$PWD/../src

DEPENDPATH += $$PWD/../src

DESTDIR = $$OUT_PWD/../src/debug/
