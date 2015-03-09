TEMPLATE = app
CONFIG += console

CONFIG -= qt
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

VERSION = 0.0.0.0

SOURCES += main.cpp \
    parametrparser.cpp

HEADERS += \
    parametrparser.h

