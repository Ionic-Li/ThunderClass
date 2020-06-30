/****************************************************************************
** Meta object code from reading C++ file 'studentprocess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../studentprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'studentprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StudentProcess_t {
    QByteArrayData data[14];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StudentProcess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StudentProcess_t qt_meta_stringdata_StudentProcess = {
    {
QT_MOC_LITERAL(0, 0, 14), // "StudentProcess"
QT_MOC_LITERAL(1, 15, 12), // "ClassEntered"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14), // "ConnectionFail"
QT_MOC_LITERAL(4, 44, 11), // "ClassExited"
QT_MOC_LITERAL(5, 56, 8), // "RecvChat"
QT_MOC_LITERAL(6, 65, 3), // "Msg"
QT_MOC_LITERAL(7, 69, 10), // "RecvScreen"
QT_MOC_LITERAL(8, 80, 3), // "Img"
QT_MOC_LITERAL(9, 84, 12), // "RecvQuestion"
QT_MOC_LITERAL(10, 97, 4), // "Ques"
QT_MOC_LITERAL(11, 102, 14), // "RecvStopAnswer"
QT_MOC_LITERAL(12, 117, 13), // "RecvOpenAudio"
QT_MOC_LITERAL(13, 131, 14) // "RecvCloseAudio"

    },
    "StudentProcess\0ClassEntered\0\0"
    "ConnectionFail\0ClassExited\0RecvChat\0"
    "Msg\0RecvScreen\0Img\0RecvQuestion\0Ques\0"
    "RecvStopAnswer\0RecvOpenAudio\0"
    "RecvCloseAudio"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StudentProcess[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       7,    1,   65,    2, 0x06 /* Public */,
       9,    1,   68,    2, 0x06 /* Public */,
      11,    0,   71,    2, 0x06 /* Public */,
      12,    0,   72,    2, 0x06 /* Public */,
      13,    0,   73,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QImage,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StudentProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StudentProcess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ClassEntered(); break;
        case 1: _t->ConnectionFail(); break;
        case 2: _t->ClassExited(); break;
        case 3: _t->RecvChat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->RecvScreen((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 5: _t->RecvQuestion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->RecvStopAnswer(); break;
        case 7: _t->RecvOpenAudio(); break;
        case 8: _t->RecvCloseAudio(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StudentProcess::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StudentProcess::ClassEntered)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (StudentProcess::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StudentProcess::ConnectionFail)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (StudentProcess::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StudentProcess::ClassExited)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (StudentProcess::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StudentProcess::RecvChat)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (StudentProcess::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StudentProcess::RecvScreen)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (StudentProcess::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StudentProcess::RecvQuestion)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (StudentProcess::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StudentProcess::RecvStopAnswer)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (StudentProcess::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StudentProcess::RecvOpenAudio)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (StudentProcess::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StudentProcess::RecvCloseAudio)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject StudentProcess::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_StudentProcess.data,
    qt_meta_data_StudentProcess,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *StudentProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StudentProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StudentProcess.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int StudentProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void StudentProcess::ClassEntered()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void StudentProcess::ConnectionFail()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void StudentProcess::ClassExited()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void StudentProcess::RecvChat(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void StudentProcess::RecvScreen(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void StudentProcess::RecvQuestion(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void StudentProcess::RecvStopAnswer()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void StudentProcess::RecvOpenAudio()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void StudentProcess::RecvCloseAudio()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
