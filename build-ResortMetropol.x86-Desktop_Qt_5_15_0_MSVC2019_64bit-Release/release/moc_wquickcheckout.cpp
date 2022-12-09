/****************************************************************************
** Meta object code from reading C++ file 'wquickcheckout.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/wquickcheckout.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wquickcheckout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WQuickCheckout_t {
    QByteArrayData data[10];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WQuickCheckout_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WQuickCheckout_t qt_meta_stringdata_WQuickCheckout = {
    {
QT_MOC_LITERAL(0, 0, 14), // "WQuickCheckout"
QT_MOC_LITERAL(1, 15, 24), // "on_chAllInvoices_clicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 7), // "checked"
QT_MOC_LITERAL(4, 49, 21), // "on_btnRefresh_clicked"
QT_MOC_LITERAL(5, 71, 20), // "on_tbl_doubleClicked"
QT_MOC_LITERAL(6, 92, 11), // "QModelIndex"
QT_MOC_LITERAL(7, 104, 5), // "index"
QT_MOC_LITERAL(8, 110, 22), // "on_btnCheckout_clicked"
QT_MOC_LITERAL(9, 133, 30) // "on_btnCommonPostCharge_clicked"

    },
    "WQuickCheckout\0on_chAllInvoices_clicked\0"
    "\0checked\0on_btnRefresh_clicked\0"
    "on_tbl_doubleClicked\0QModelIndex\0index\0"
    "on_btnCheckout_clicked\0"
    "on_btnCommonPostCharge_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WQuickCheckout[] = {

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
       1,    1,   39,    2, 0x08 /* Private */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    1,   43,    2, 0x08 /* Private */,
       8,    0,   46,    2, 0x08 /* Private */,
       9,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WQuickCheckout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WQuickCheckout *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_chAllInvoices_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_btnRefresh_clicked(); break;
        case 2: _t->on_tbl_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_btnCheckout_clicked(); break;
        case 4: _t->on_btnCommonPostCharge_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WQuickCheckout::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseWidget::staticMetaObject>(),
    qt_meta_stringdata_WQuickCheckout.data,
    qt_meta_data_WQuickCheckout,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WQuickCheckout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WQuickCheckout::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WQuickCheckout.stringdata0))
        return static_cast<void*>(this);
    return BaseWidget::qt_metacast(_clname);
}

int WQuickCheckout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
