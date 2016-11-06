#-------------------------------------------------
#
# Project created by QtCreator 2016-11-06T12:00:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ArtVision
TEMPLATE = app

include(opencv.pri)

SOURCES += main.cpp \
    imageviewer.cpp \
    imageviewerwidget.cpp

HEADERS  += \
    imageviewer.h \
    imageviewerwidget.h

FORMS    += \
    imageviewerwidget.ui
