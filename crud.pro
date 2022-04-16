QT       += core gui
QT       += gui
QT       += core
QT       += sql
QT += widgets
QT       += core gui  printsupport
QT += qml
QT       += core gui multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Employee.cpp \
    connection.cpp \
    historique1.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Employee.h \
    connection.h \
    historique1.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target




#notification
QMAKE_CXXFLAGS += -std=gnu++14

RESOURCES +=\
     notiff.qrc
