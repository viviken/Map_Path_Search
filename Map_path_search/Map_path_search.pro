TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    map.cpp \
    close.cpp \
    tinyxml.cpp \
    tinystr.cpp \
    tinyxmlerror.cpp \
    tinyxmlparser.cpp \
    open.cpp \
    vertex.cpp

HEADERS += \
    map.h \
    gl_const.h \
    tinyxml.h \
    tinystr.h \
    close.h \
    open.h \
    vertex.h

