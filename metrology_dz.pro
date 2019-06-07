#-------------------------------------------------
#
# Project created by QtCreator 2019-06-04T18:03:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = metrology_dz
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
    sample.cpp \
    cont.cpp \
    cont1.cpp \
    tabl1dialog.cpp \
    tabl2dialog.cpp

HEADERS += \
        mainwindow.h \
    sample.h \
    table_cr2.h \
    cont.h \
    table_cr1.h \
    cont1.h \
    tabl1dialog.h \
    tabl2dialog.h

FORMS += \
        mainwindow.ui \
    tabl1dialog.ui \
    tabl1dialog.ui \
    tabl2dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
