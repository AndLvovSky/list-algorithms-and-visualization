TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS += \
    src \
    test \
    app

test.depends = src
app.depends = src
