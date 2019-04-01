QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_calculustest.cpp \
    ../app/function.cpp \
    ../app/functionbuilder.cpp \
    ../app/differentiate.cpp

HEADERS += \
    ../app/function.h \
    ../app/functionbuilder.h \
    ../app/differentiate.h

INCLUDEPATH +=\
    ../app
