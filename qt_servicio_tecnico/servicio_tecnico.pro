QT -= gui

CONFIG += c++14 console
CONFIG -= app_bundle
TARGET = xml_dtd

DEFINES += QT_DEPRECATED_WARNINGS

QT += sql
QT += websockets

SOURCES += \
        main.cpp \
    tablaordenes.cpp \
    bbdd.cpp \
    controlador.cpp \
    websockets.cpp \
    utils.cpp \
    xml.cpp \
    tablatecnicos.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    tablaordenes.h \
    bbdd.h \
    controlador.h \
    websockets.h \
    utils.h \
    xml.h \
    tablatecnicos.h
