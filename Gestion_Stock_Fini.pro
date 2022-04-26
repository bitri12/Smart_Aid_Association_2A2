QT       += core gui sql serialport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ajouterproduit.cpp \
    arduino.cpp \
    arduinowindow.cpp \
    connection.cpp \
    deleteproduit.cpp \
    excel.cpp \
    main.cpp \
    menugestionstock.cpp \
    modifierproduit.cpp \
    produit.cpp \
    statistique.cpp \
    tridispo.cpp \
    trinondispo.cpp \
    voirstock.cpp

HEADERS += \
    ajouterproduit.h \
    arduino.h \
    arduinowindow.h \
    connection.h \
    deleteproduit.h \
    excel.h \
    export.h \
    menugestionstock.h \
    modifierproduit.h \
    produit.h \
    statistique.h \
    tridispo.h \
    trinondispo.h \
    voirstock.h

FORMS += \
    ajouterproduit.ui \
    arduinowindow.ui \
    deleteproduit.ui \
    menugestionstock.ui \
    modifierproduit.ui \
    statistique.ui \
    tridispo.ui \
    trinondispo.ui \
    voirstock.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
