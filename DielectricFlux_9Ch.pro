#-------------------------------------------------
#
# Project created by QtCreator 2016-05-15T15:34:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DielectricFlux_9Ch
TEMPLATE = app
INCLUDEPATH += ./include/window/ \
    ./include

SOURCES += \
    source/System_main.cpp \
    source/main.cpp \
    source/Window/windowinterface.cpp \
    source/Window/standbywindow.cpp \
    source/Window/debugwindow.cpp \
    source/Window/bottomwindow.cpp

HEADERS  += \
    include/types.h \
    include/System_main.h \
    include/Window/windowinterface.h \
    include/Window/standbywindow.h \
    include/Window/debugwindow.h \
    include/Window/bottomwindow.h

FORMS    +=
