/****************************************************************************
** Meta object code from reading C++ file 'dlgcouponsales.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/dlgcouponsales.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgcouponsales.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DlgCouponSales_t {
    QByteArrayData data[6];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlgCouponSales_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlgCouponSales_t qt_meta_stringdata_DlgCouponSales = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DlgCouponSales"
QT_MOC_LITERAL(1, 15, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(4, 56, 20), // "on_leQty_textChanged"
QT_MOC_LITERAL(5, 77, 4) // "arg1"

    },
    "DlgCouponSales\0on_btnCancel_clicked\0"
    "\0on_btnSave_clicked\0on_leQty_textChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlgCouponSales[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    1,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void DlgCouponSales::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DlgCouponSales *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnCancel_clicked(); break;
        case 1: _t->on_btnSave_clicked(); break;
        case 2: _t->on_leQty_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DlgCouponSales::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseExtendedDialog::staticMetaObject>(),
    qt_meta_stringdata_DlgCouponSales.data,
    qt_meta_data_DlgCouponSales,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DlgCouponSales::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlgCouponSales::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DlgCouponSales.stringdata0))
        return static_cast<void*>(this);
    return BaseExtendedDialog::qt_metacast(_clname);
}

int DlgCouponSales::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseExtendedDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
