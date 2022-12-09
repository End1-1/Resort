/****************************************************************************
** Meta object code from reading C++ file 'roomstate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RoomChart/roomstate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roomstate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RoomState_t {
    QByteArrayData data[12];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RoomState_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RoomState_t qt_meta_stringdata_RoomState = {
    {
QT_MOC_LITERAL(0, 0, 9), // "RoomState"
QT_MOC_LITERAL(1, 10, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 16), // "on_btnOk_clicked"
QT_MOC_LITERAL(4, 49, 22), // "on_deStart_textChanged"
QT_MOC_LITERAL(5, 72, 4), // "arg1"
QT_MOC_LITERAL(6, 77, 20), // "on_deEnd_textChanged"
QT_MOC_LITERAL(7, 98, 20), // "on_btnSticky_clicked"
QT_MOC_LITERAL(8, 119, 7), // "checked"
QT_MOC_LITERAL(9, 127, 25), // "on_lbStatus_linkActivated"
QT_MOC_LITERAL(10, 153, 4), // "link"
QT_MOC_LITERAL(11, 158, 17) // "on_btnWhy_clicked"

    },
    "RoomState\0on_btnCancel_clicked\0\0"
    "on_btnOk_clicked\0on_deStart_textChanged\0"
    "arg1\0on_deEnd_textChanged\0"
    "on_btnSticky_clicked\0checked\0"
    "on_lbStatus_linkActivated\0link\0"
    "on_btnWhy_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoomState[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       6,    1,   54,    2, 0x08 /* Private */,
       7,    1,   57,    2, 0x08 /* Private */,
       9,    1,   60,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,

       0        // eod
};

void RoomState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RoomState *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnCancel_clicked(); break;
        case 1: _t->on_btnOk_clicked(); break;
        case 2: _t->on_deStart_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_deEnd_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_btnSticky_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_lbStatus_linkActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_btnWhy_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RoomState::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseExtendedDialog::staticMetaObject>(),
    qt_meta_stringdata_RoomState.data,
    qt_meta_data_RoomState,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RoomState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoomState::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RoomState.stringdata0))
        return static_cast<void*>(this);
    return BaseExtendedDialog::qt_metacast(_clname);
}

int RoomState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseExtendedDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
