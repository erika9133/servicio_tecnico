/****************************************************************************
** Meta object code from reading C++ file 'websockets.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qt_servicio_tecnico/websockets.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'websockets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WebSocket_t {
    QByteArrayData data[13];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebSocket_t qt_meta_stringdata_WebSocket = {
    {
QT_MOC_LITERAL(0, 0, 9), // "WebSocket"
QT_MOC_LITERAL(1, 10, 6), // "closed"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 15), // "mensajeRecibido"
QT_MOC_LITERAL(4, 34, 15), // "mensajeEntrante"
QT_MOC_LITERAL(5, 50, 1), // "m"
QT_MOC_LITERAL(6, 52, 15), // "onNewConnection"
QT_MOC_LITERAL(7, 68, 18), // "processTextMessage"
QT_MOC_LITERAL(8, 87, 7), // "message"
QT_MOC_LITERAL(9, 95, 15), // "emitTextMessage"
QT_MOC_LITERAL(10, 111, 11), // "QWebSocket*"
QT_MOC_LITERAL(11, 123, 7), // "pClient"
QT_MOC_LITERAL(12, 131, 18) // "socketDisconnected"

    },
    "WebSocket\0closed\0\0mensajeRecibido\0"
    "mensajeEntrante\0m\0onNewConnection\0"
    "processTextMessage\0message\0emitTextMessage\0"
    "QWebSocket*\0pClient\0socketDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebSocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   48,    2, 0x08 /* Private */,
       7,    1,   49,    2, 0x08 /* Private */,
       9,    2,   52,    2, 0x08 /* Private */,
      12,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 10,    8,   11,
    QMetaType::Void,

       0        // eod
};

void WebSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WebSocket *_t = static_cast<WebSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->mensajeRecibido((*reinterpret_cast< mensajeEntrante(*)>(_a[1]))); break;
        case 2: _t->onNewConnection(); break;
        case 3: _t->processTextMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->emitTextMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QWebSocket*(*)>(_a[2]))); break;
        case 5: _t->socketDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (WebSocket::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocket::closed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WebSocket::*_t)(mensajeEntrante );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocket::mensajeRecibido)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject WebSocket::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WebSocket.data,
      qt_meta_data_WebSocket,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WebSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WebSocket.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WebSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void WebSocket::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WebSocket::mensajeRecibido(mensajeEntrante _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
