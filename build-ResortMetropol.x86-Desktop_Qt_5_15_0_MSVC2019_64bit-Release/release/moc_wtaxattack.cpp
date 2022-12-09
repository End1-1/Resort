/****************************************************************************
** Meta object code from reading C++ file 'wtaxattack.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/wtaxattack.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wtaxattack.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WTaxAttack_t {
    QByteArrayData data[16];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WTaxAttack_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WTaxAttack_t qt_meta_stringdata_WTaxAttack = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WTaxAttack"
QT_MOC_LITERAL(1, 11, 15), // "checkboxClicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 1), // "v"
QT_MOC_LITERAL(4, 30, 8), // "checkAll"
QT_MOC_LITERAL(5, 39, 10), // "uncheckAll"
QT_MOC_LITERAL(6, 50, 21), // "on_btnRefresh_clicked"
QT_MOC_LITERAL(7, 72, 20), // "on_tbl_doubleClicked"
QT_MOC_LITERAL(8, 93, 11), // "QModelIndex"
QT_MOC_LITERAL(9, 105, 5), // "index"
QT_MOC_LITERAL(10, 111, 23), // "on_leSearch_textChanged"
QT_MOC_LITERAL(11, 135, 4), // "arg1"
QT_MOC_LITERAL(12, 140, 26), // "on_leInvoice_returnPressed"
QT_MOC_LITERAL(13, 167, 33), // "on_tbl_customContextMenuReque..."
QT_MOC_LITERAL(14, 201, 3), // "pos"
QT_MOC_LITERAL(15, 205, 22) // "on_btnPrintTax_clicked"

    },
    "WTaxAttack\0checkboxClicked\0\0v\0checkAll\0"
    "uncheckAll\0on_btnRefresh_clicked\0"
    "on_tbl_doubleClicked\0QModelIndex\0index\0"
    "on_leSearch_textChanged\0arg1\0"
    "on_leInvoice_returnPressed\0"
    "on_tbl_customContextMenuRequested\0pos\0"
    "on_btnPrintTax_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WTaxAttack[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    0,   62,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    1,   65,    2, 0x08 /* Private */,
      10,    1,   68,    2, 0x08 /* Private */,
      12,    0,   71,    2, 0x08 /* Private */,
      13,    1,   72,    2, 0x08 /* Private */,
      15,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   14,
    QMetaType::Void,

       0        // eod
};

void WTaxAttack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WTaxAttack *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkboxClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->checkAll(); break;
        case 2: _t->uncheckAll(); break;
        case 3: _t->on_btnRefresh_clicked(); break;
        case 4: _t->on_tbl_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_leSearch_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_leInvoice_returnPressed(); break;
        case 7: _t->on_tbl_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 8: _t->on_btnPrintTax_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WTaxAttack::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseWidget::staticMetaObject>(),
    qt_meta_stringdata_WTaxAttack.data,
    qt_meta_data_WTaxAttack,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WTaxAttack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WTaxAttack::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WTaxAttack.stringdata0))
        return static_cast<void*>(this);
    return BaseWidget::qt_metacast(_clname);
}

int WTaxAttack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
