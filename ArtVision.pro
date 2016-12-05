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

SOURCES += src/main.cpp \
    src/imageviewerwidget.cpp \
    src/edgedetectionwidget.cpp \
    src/imageviewerwidget.cpp

HEADERS  += \
    src/imageviewerwidget.h \
    src/edgedetectionwidget.h \
    src/imageviewerwidget.h \
    src/core.h \
    src/stats.h

FORMS    += \
    src/edgedetectionwidget.ui

DISTFILES += \
    website/styles.css \
    website/index.html
