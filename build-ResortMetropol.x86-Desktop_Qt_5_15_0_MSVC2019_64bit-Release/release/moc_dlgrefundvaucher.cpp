/****************************************************************************
** Meta object code from reading C++ file 'dlgrefundvaucher.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/dlgrefundvaucher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgrefundvaucher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DlgRefundVaucher_t {
    QByteArrayData data[8];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlgRefundVaucher_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlgRefundVaucher_t qt_meta_stringdata_DlgRefundVaucher = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DlgRefundVaucher"
QT_MOC_LITERAL(1, 17, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 19), // "on_btnPrint_clicked"
QT_MOC_LITERAL(4, 57, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(5, 78, 18), // "on_rgGuest_clicked"
QT_MOC_LITERAL(6, 97, 7), // "checked"
QT_MOC_LITERAL(7, 105, 15) // "on_rgCL_clicked"

    },
    "DlgRefundVaucher\0on_btnSave_clicked\0"
    "\0on_btnPrint_clicked\0on_btnCancel_clicked\0"
    "on_rgGuest_clicked\0checked\0on_rgCL_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlgRefundVaucher[] = {

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
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,

       0        // eod
};

void DlgRefundVaucher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DlgRefundVaucher *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnSave_clicked(); break;
        case 1: _t->on_btnPrint_clicked(); break;
        case 2: _t->on_btnCancel_clicked(); break;
        case 3: _t->on_rgGuest_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_rgCL_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DlgRefundVaucher::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseDialog::staticMetaObject>(),
    qt_meta_stringdata_DlgRefundVaucher.data,
    qt_meta_data_DlgRefundVaucher,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DlgRefundVaucher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlgRefundVaucher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DlgRefundVaucher.stringdata0))
        return static_cast<void*>(this);
    return BaseDialog::qt_metacast(_clname);
}

int DlgRefundVaucher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseDialog::qt_metacall(_c, _id, _a);
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
