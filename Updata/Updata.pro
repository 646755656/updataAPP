#-------------------------------------------------
#
# Project created by QtCreator 2018-01-18T21:21:59
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Updata
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    series.cpp

HEADERS  += mainwindow.h \
    series.h

FORMS    += mainwindow.ui
