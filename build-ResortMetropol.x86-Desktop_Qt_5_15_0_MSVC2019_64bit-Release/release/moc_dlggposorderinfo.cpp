/****************************************************************************
** Meta object code from reading C++ file 'dlggposorderinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/dlggposorderinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlggposorderinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DlgGPOSOrderInfo_t {
    QByteArrayData data[15];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlgGPOSOrderInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlgGPOSOrderInfo_t qt_meta_stringdata_DlgGPOSOrderInfo = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DlgGPOSOrderInfo"
QT_MOC_LITERAL(1, 17, 17), // "selectPaymentMode"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 1), // "v"
QT_MOC_LITERAL(4, 38, 15), // "showDishHistory"
QT_MOC_LITERAL(5, 54, 3), // "tag"
QT_MOC_LITERAL(6, 58, 16), // "on_btnOk_clicked"
QT_MOC_LITERAL(7, 75, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(8, 94, 29), // "on_tblData_currentItemChanged"
QT_MOC_LITERAL(9, 124, 18), // "C5TableWidgetItem*"
QT_MOC_LITERAL(10, 143, 7), // "current"
QT_MOC_LITERAL(11, 151, 8), // "previous"
QT_MOC_LITERAL(12, 160, 19), // "on_btnPrint_clicked"
QT_MOC_LITERAL(13, 180, 22), // "on_btnPrintTax_clicked"
QT_MOC_LITERAL(14, 203, 22) // "on_btnTracking_clicked"

    },
    "DlgGPOSOrderInfo\0selectPaymentMode\0\0"
    "v\0showDishHistory\0tag\0on_btnOk_clicked\0"
    "on_btnSave_clicked\0on_tblData_currentItemChanged\0"
    "C5TableWidgetItem*\0current\0previous\0"
    "on_btnPrint_clicked\0on_btnPrintTax_clicked\0"
    "on_btnTracking_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlgGPOSOrderInfo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    1,   57,    2, 0x08 /* Private */,
       6,    0,   60,    2, 0x08 /* Private */,
       7,    0,   61,    2, 0x08 /* Private */,
       8,    2,   62,    2, 0x08 /* Private */,
      12,    0,   67,    2, 0x08 /* Private */,
      13,    0,   68,    2, 0x08 /* Private */,
      14,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DlgGPOSOrderInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DlgGPOSOrderInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectPaymentMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->showDishHistory((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_btnOk_clicked(); break;
        case 3: _t->on_btnSave_clicked(); break;
        case 4: _t->on_tblData_currentItemChanged((*reinterpret_cast< C5TableWidgetItem*(*)>(_a[1])),(*reinterpret_cast< C5TableWidgetItem*(*)>(_a[2]))); break;
        case 5: _t->on_btnPrint_clicked(); break;
        case 6: _t->on_btnPrintTax_clicked(); break;
        case 7: _t->on_btnTracking_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DlgGPOSOrderInfo::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseExtendedDialog::staticMetaObject>(),
    qt_meta_stringdata_DlgGPOSOrderInfo.data,
    qt_meta_data_DlgGPOSOrderInfo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DlgGPOSOrderInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlgGPOSOrderInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DlgGPOSOrderInfo.stringdata0))
        return static_cast<void*>(this);
    return BaseExtendedDialog::qt_metacast(_clname);
}

int DlgGPOSOrderInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseExtendedDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
