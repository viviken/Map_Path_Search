TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    map.cpp \
    tinystr.cpp \
    tinyxml.cpp \
    tinyxmlerror.cpp \
    tinyxmlparser.cpp \
    linkedlist.cpp \
    astarsearch.cpp

HEADERS += \
    gl_const.h \
    map.h \
    tinystr.h \
    tinyxml.h \
    linkedlist.h \
    astarsearch.h

