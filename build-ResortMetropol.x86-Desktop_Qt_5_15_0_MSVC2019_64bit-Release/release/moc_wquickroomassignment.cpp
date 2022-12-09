/****************************************************************************
** Meta object code from reading C++ file 'wquickroomassignment.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/wquickroomassignment.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wquickroomassignment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WQuickRoomAssignment_t {
    QByteArrayData data[10];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WQuickRoomAssignment_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WQuickRoomAssignment_t qt_meta_stringdata_WQuickRoomAssignment = {
    {
QT_MOC_LITERAL(0, 0, 20), // "WQuickRoomAssignment"
QT_MOC_LITERAL(1, 21, 9), // "showRooms"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 22), // "tblLineEditTextChanged"
QT_MOC_LITERAL(4, 55, 4), // "text"
QT_MOC_LITERAL(5, 60, 21), // "on_btnRefresh_clicked"
QT_MOC_LITERAL(6, 82, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(7, 101, 20), // "on_tbl_doubleClicked"
QT_MOC_LITERAL(8, 122, 11), // "QModelIndex"
QT_MOC_LITERAL(9, 134, 5) // "index"

    },
    "WQuickRoomAssignment\0showRooms\0\0"
    "tblLineEditTextChanged\0text\0"
    "on_btnRefresh_clicked\0on_btnSave_clicked\0"
    "on_tbl_doubleClicked\0QModelIndex\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WQuickRoomAssignment[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    1,   40,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void WQuickRoomAssignment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WQuickRoomAssignment *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showRooms(); break;
        case 1: _t->tblLineEditTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_btnRefresh_clicked(); break;
        case 3: _t->on_btnSave_clicked(); break;
        case 4: _t->on_tbl_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WQuickRoomAssignment::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseWidget::staticMetaObject>(),
    qt_meta_stringdata_WQuickRoomAssignment.data,
    qt_meta_data_WQuickRoomAssignment,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WQuickRoomAssignment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WQuickRoomAssignment::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WQuickRoomAssignment.stringdata0))
        return static_cast<void*>(this);
    return BaseWidget::qt_metacast(_clname);
}

int WQuickRoomAssignment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
