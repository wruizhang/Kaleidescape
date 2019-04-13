#-------------------------------------------------
#
# Project created by QtCreator 2018-11-07T00:40:56
#
#-------------------------------------------------

QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projectsetup
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    options.cpp \
    rooms.cpp \
    room1.cpp \
    room2.cpp \
    room3.cpp \
    room4.cpp

HEADERS += \
        mainwindow.h \
    options.h \
    rooms.h \
    room1.h \
    room2.h \
    room3.h \
    room4.h

FORMS += \
        mainwindow.ui \
    options.ui \
    rooms.ui \
    room1.ui \
    room2.ui \
    room3.ui \
    room4.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    audio.qrc
