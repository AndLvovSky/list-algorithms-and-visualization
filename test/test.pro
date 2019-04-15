QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += $$PWD/../src

SOURCES += \   
    test_linked_list.cpp \
    main_test.cpp

HEADERS += \
    test_linked_list.h
