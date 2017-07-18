TEMPLATE = lib

CONFIG += c++11
CONFIG -= debug_and_release

TARGET = ApplicationLib

DEFINES += APPLICATIONLIB_LIBRARY

HEADERS += \
    test_lib.h


SOURCES += \
    test_lib.cpp
