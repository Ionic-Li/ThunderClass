/****************************************************************************
** Meta object code from reading C++ file 'TeacherWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../TeacherWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TeacherWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TeacherWindow_t {
    QByteArrayData data[22];
    char stringdata0[324];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TeacherWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TeacherWindow_t qt_meta_stringdata_TeacherWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TeacherWindow"
QT_MOC_LITERAL(1, 14, 10), // "closeEvent"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "QCloseEvent*"
QT_MOC_LITERAL(4, 39, 1), // "e"
QT_MOC_LITERAL(5, 41, 9), // "showEvent"
QT_MOC_LITERAL(6, 51, 11), // "QShowEvent*"
QT_MOC_LITERAL(7, 63, 24), // "on_btnBeginClass_clicked"
QT_MOC_LITERAL(8, 88, 25), // "on_ckbScreenShare_clicked"
QT_MOC_LITERAL(9, 114, 24), // "on_ckbVoiceShare_clicked"
QT_MOC_LITERAL(10, 139, 22), // "on_btnEndClass_clicked"
QT_MOC_LITERAL(11, 162, 18), // "on_btnSend_clicked"
QT_MOC_LITERAL(12, 181, 22), // "on_btnSendQues_clicked"
QT_MOC_LITERAL(13, 204, 22), // "on_btnRandCall_clicked"
QT_MOC_LITERAL(14, 227, 12), // "ClassBegined"
QT_MOC_LITERAL(15, 240, 10), // "ClassEnded"
QT_MOC_LITERAL(16, 251, 16), // "RecvStudentLogin"
QT_MOC_LITERAL(17, 268, 4), // "Name"
QT_MOC_LITERAL(18, 273, 17), // "RecvStudentLogout"
QT_MOC_LITERAL(19, 291, 8), // "RecvChat"
QT_MOC_LITERAL(20, 300, 3), // "Msg"
QT_MOC_LITERAL(21, 304, 19) // "ShowRandCallStudent"

    },
    "TeacherWindow\0closeEvent\0\0QCloseEvent*\0"
    "e\0showEvent\0QShowEvent*\0"
    "on_btnBeginClass_clicked\0"
    "on_ckbScreenShare_clicked\0"
    "on_ckbVoiceShare_clicked\0"
    "on_btnEndClass_clicked\0on_btnSend_clicked\0"
    "on_btnSendQues_clicked\0on_btnRandCall_clicked\0"
    "ClassBegined\0ClassEnded\0RecvStudentLogin\0"
    "Name\0RecvStudentLogout\0RecvChat\0Msg\0"
    "ShowRandCallStudent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TeacherWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x08 /* Private */,
       5,    1,   92,    2, 0x08 /* Private */,
       7,    0,   95,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    0,  101,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    1,  104,    2, 0x08 /* Private */,
      18,    1,  107,    2, 0x08 /* Private */,
      19,    1,  110,    2, 0x08 /* Private */,
      21,    1,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,   17,

       0        // eod
};

void TeacherWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TeacherWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 1: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 2: _t->on_btnBeginClass_clicked(); break;
        case 3: _t->on_ckbScreenShare_clicked(); break;
        case 4: _t->on_ckbVoiceShare_clicked(); break;
        case 5: _t->on_btnEndClass_clicked(); break;
        case 6: _t->on_btnSend_clicked(); break;
        case 7: _t->on_btnSendQues_clicked(); break;
        case 8: _t->on_btnRandCall_clicked(); break;
        case 9: _t->ClassBegined(); break;
        case 10: _t->ClassEnded(); break;
        case 11: _t->RecvStudentLogin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->RecvStudentLogout((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->RecvChat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->ShowRandCallStudent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TeacherWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_TeacherWindow.data,
    qt_meta_data_TeacherWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TeacherWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TeacherWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TeacherWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TeacherWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
