#-------------------------------------------------
#
# Project created by QtCreator 2016-11-14T22:13:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proyecto_PDI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mat2qimage.cpp

HEADERS  += mainwindow.h \
    mat2qimage.h

LIBS += `pkg-config \
    opencv \
    --cflags \
    --libs`

FORMS    += mainwindow.ui
