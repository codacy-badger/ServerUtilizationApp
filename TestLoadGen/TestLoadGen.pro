QT += testlib core
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += $$PWD/../UtilizationLib

SOURCES +=  tst_testloadgen.cpp

LIBS += -L../UtilizationLib -lUtilizationLib
