QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += $$PWD/../src

SOURCES += \   
    main_test.cpp \
    test_doubly_linked_list.cpp

HEADERS += \
    test_doubly_linked_list.h
