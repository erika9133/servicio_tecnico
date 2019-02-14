QT -= gui

CONFIG += c++14 console
CONFIG -= app_bundle

LIBS += -lxml2
#INCLUDEPATH += libxml
TARGET = servidor_sv

DEFINES += QT_DEPRECATED_WARNINGS

QT += sql
QT += websockets
QT += xml


SOURCES += \
        main.cpp \
    bbdd.cpp \
    controlador.cpp \
    websockets.cpp \
    utils.cpp \
    xml.cpp \
    consultas.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    bbdd.h \
    controlador.h \
    websockets.h \
    utils.h \
    xml.h \
    consultas.h
