/****************************************************************************
** Meta object code from reading C++ file 'VideoWindowThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VideoWindowThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VideoWindowThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VideoWindowThread_t {
    QByteArrayData data[9];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoWindowThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoWindowThread_t qt_meta_stringdata_VideoWindowThread = {
    {
QT_MOC_LITERAL(0, 0, 17), // "VideoWindowThread"
QT_MOC_LITERAL(1, 18, 13), // "frameAcquired"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 2), // "pm"
QT_MOC_LITERAL(4, 36, 11), // "vidFinished"
QT_MOC_LITERAL(5, 48, 16), // "onAlteredChanged"
QT_MOC_LITERAL(6, 65, 7), // "altered"
QT_MOC_LITERAL(7, 73, 18), // "onFrameworkChanged"
QT_MOC_LITERAL(8, 92, 9) // "useOpenCV"

    },
    "VideoWindowThread\0frameAcquired\0\0pm\0"
    "vidFinished\0onAlteredChanged\0altered\0"
    "onFrameworkChanged\0useOpenCV"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoWindowThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    0,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   38,    2, 0x0a /* Public */,
       7,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    8,

       0        // eod
};

void VideoWindowThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoWindowThread *_t = static_cast<VideoWindowThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->frameAcquired((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 1: _t->vidFinished(); break;
        case 2: _t->onAlteredChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onFrameworkChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VideoWindowThread::*_t)(QPixmap );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoWindowThread::frameAcquired)) {
                *result = 0;
            }
        }
        {
            typedef void (VideoWindowThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoWindowThread::vidFinished)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject VideoWindowThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_VideoWindowThread.data,
      qt_meta_data_VideoWindowThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VideoWindowThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoWindowThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VideoWindowThread.stringdata0))
        return static_cast<void*>(const_cast< VideoWindowThread*>(this));
    return QThread::qt_metacast(_clname);
}

int VideoWindowThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void VideoWindowThread::frameAcquired(QPixmap _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VideoWindowThread::vidFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
