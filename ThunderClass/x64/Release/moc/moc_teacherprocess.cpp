/****************************************************************************
** Meta object code from reading C++ file 'teacherprocess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../teacherprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'teacherprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TeacherProcess_t {
    QByteArrayData data[11];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TeacherProcess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TeacherProcess_t qt_meta_stringdata_TeacherProcess = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TeacherProcess"
QT_MOC_LITERAL(1, 15, 12), // "ClassBegined"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "ClassEnded"
QT_MOC_LITERAL(4, 40, 14), // "RecvBeginClass"
QT_MOC_LITERAL(5, 55, 16), // "RecvStudentLogin"
QT_MOC_LITERAL(6, 72, 4), // "Name"
QT_MOC_LITERAL(7, 77, 17), // "RecvStudentLogout"
QT_MOC_LITERAL(8, 95, 8), // "RecvChat"
QT_MOC_LITERAL(9, 104, 3), // "Msg"
QT_MOC_LITERAL(10, 108, 15) // "SelectedStudent"

    },
    "TeacherProcess\0ClassBegined\0\0ClassEnded\0"
    "RecvBeginClass\0RecvStudentLogin\0Name\0"
    "RecvStudentLogout\0RecvChat\0Msg\0"
    "SelectedStudent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TeacherProcess[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,
       7,    1,   55,    2, 0x06 /* Public */,
       8,    1,   58,    2, 0x06 /* Public */,
      10,    1,   61,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void TeacherProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TeacherProcess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ClassBegined(); break;
        case 1: _t->ClassEnded(); break;
        case 2: _t->RecvBeginClass(); break;
        case 3: _t->RecvStudentLogin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->RecvStudentLogout((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->RecvChat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->SelectedStudent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TeacherProcess::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeacherProcess::ClassBegined)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TeacherProcess::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeacherProcess::ClassEnded)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TeacherProcess::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeacherProcess::RecvBeginClass)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TeacherProcess::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeacherProcess::RecvStudentLogin)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TeacherProcess::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeacherProcess::RecvStudentLogout)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TeacherProcess::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeacherProcess::RecvChat)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TeacherProcess::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TeacherProcess::SelectedStudent)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TeacherProcess::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TeacherProcess.data,
    qt_meta_data_TeacherProcess,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TeacherProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TeacherProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TeacherProcess.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TeacherProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TeacherProcess::ClassBegined()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TeacherProcess::ClassEnded()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TeacherProcess::RecvBeginClass()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TeacherProcess::RecvStudentLogin(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TeacherProcess::RecvStudentLogout(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TeacherProcess::RecvChat(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TeacherProcess::SelectedStudent(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
