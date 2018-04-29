#-------------------------------------------------
#
# Project created by QtCreator 2018-04-29T21:26:26
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_Login
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    userinfo.cpp

HEADERS  += mainwindow.h \
    userinfo.h

FORMS    += mainwindow.ui \
    userinfo.ui
