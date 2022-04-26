QT       += core gui
QT       += core network
QT       += core gui sql
 QT += widgets
QT += printsupport
QT       += core gui
QT       += gui
QT       += core
QT       += sql
QT += widgets
QT       += core gui  printsupport

QT       += core gui multimedia multimediawidgets
QT +=serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = Source_Projet2A
TEMPLATE = app
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
  ../../Desktop/test_interface/adherent.cpp \
    arduino.cpp \
    connection.cpp \
    employee.cpp \
    exel.cpp \
    familles.cpp \
    historique1.cpp \
    login.cpp \
    login_bd.cpp \
    main.cpp \
    mainwindow.cpp \
    produit.cpp \
    qrcodegen.cpp \
    smtp.cpp

HEADERS += \
    ../../Desktop/test_interface/adherent.h \
    arduino.h \
    connection.h \
    employee.h \
    exel.h \
    familles.h \
    historique1.h \
    login.h \
    login_bd.h \
    mainwindow.h \
    produit.h \
    qrcodegen.hpp \
    smtp.h

FORMS += \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
