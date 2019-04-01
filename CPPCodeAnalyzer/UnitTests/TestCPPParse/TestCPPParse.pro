QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testcppparse.cpp \
    ../../CPPParser/parser.cpp

SUBDIRS += \
    ../../CPPParser/CPPParser.pro

HEADERS += \
    ../../CPPParser/parser.h
