/****************************************************************************
** Meta object code from reading C++ file 'fvauchers.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Filter/fvauchers.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fvauchers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FVauchers_t {
    QByteArrayData data[24];
    char stringdata0[309];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FVauchers_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FVauchers_t qt_meta_stringdata_FVauchers = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FVauchers"
QT_MOC_LITERAL(1, 10, 10), // "clickOnRow"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "row"
QT_MOC_LITERAL(4, 26, 16), // "eliminateVoucher"
QT_MOC_LITERAL(5, 43, 11), // "cancelation"
QT_MOC_LITERAL(6, 55, 11), // "openInvoice"
QT_MOC_LITERAL(7, 67, 13), // "reviveVaucher"
QT_MOC_LITERAL(8, 81, 14), // "correctCLNames"
QT_MOC_LITERAL(9, 96, 18), // "correctCLNamesBack"
QT_MOC_LITERAL(10, 115, 11), // "editRawData"
QT_MOC_LITERAL(11, 127, 4), // "edit"
QT_MOC_LITERAL(12, 132, 7), // "recover"
QT_MOC_LITERAL(13, 140, 12), // "printVaucher"
QT_MOC_LITERAL(14, 153, 21), // "printVoucherAsInvoice"
QT_MOC_LITERAL(15, 175, 16), // "doubleClickOnRow"
QT_MOC_LITERAL(16, 192, 6), // "values"
QT_MOC_LITERAL(17, 199, 21), // "on_chCanceled_clicked"
QT_MOC_LITERAL(18, 221, 7), // "checked"
QT_MOC_LITERAL(19, 229, 23), // "on_toolButton_2_clicked"
QT_MOC_LITERAL(20, 253, 21), // "on_toolButton_clicked"
QT_MOC_LITERAL(21, 275, 15), // "tblMainDblClick"
QT_MOC_LITERAL(22, 291, 11), // "QModelIndex"
QT_MOC_LITERAL(23, 303, 5) // "index"

    },
    "FVauchers\0clickOnRow\0\0row\0eliminateVoucher\0"
    "cancelation\0openInvoice\0reviveVaucher\0"
    "correctCLNames\0correctCLNamesBack\0"
    "editRawData\0edit\0recover\0printVaucher\0"
    "printVoucherAsInvoice\0doubleClickOnRow\0"
    "values\0on_chCanceled_clicked\0checked\0"
    "on_toolButton_2_clicked\0on_toolButton_clicked\0"
    "tblMainDblClick\0QModelIndex\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FVauchers[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x08 /* Private */,
       4,    0,  102,    2, 0x08 /* Private */,
       5,    0,  103,    2, 0x08 /* Private */,
       6,    0,  104,    2, 0x08 /* Private */,
       7,    0,  105,    2, 0x08 /* Private */,
       8,    0,  106,    2, 0x08 /* Private */,
       9,    0,  107,    2, 0x08 /* Private */,
      10,    0,  108,    2, 0x08 /* Private */,
      11,    0,  109,    2, 0x08 /* Private */,
      12,    0,  110,    2, 0x08 /* Private */,
      13,    0,  111,    2, 0x08 /* Private */,
      14,    0,  112,    2, 0x08 /* Private */,
      15,    1,  113,    2, 0x08 /* Private */,
      17,    1,  116,    2, 0x08 /* Private */,
      19,    0,  119,    2, 0x08 /* Private */,
      20,    0,  120,    2, 0x08 /* Private */,
      21,    1,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantList,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,

       0        // eod
};

void FVauchers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FVauchers *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clickOnRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->eliminateVoucher(); break;
        case 2: _t->cancelation(); break;
        case 3: _t->openInvoice(); break;
        case 4: _t->reviveVaucher(); break;
        case 5: _t->correctCLNames(); break;
        case 6: _t->correctCLNamesBack(); break;
        case 7: _t->editRawData(); break;
        case 8: _t->edit(); break;
        case 9: _t->recover(); break;
        case 10: _t->printVaucher(); break;
        case 11: _t->printVoucherAsInvoice(); break;
        case 12: _t->doubleClickOnRow((*reinterpret_cast< const QList<QVariant>(*)>(_a[1]))); break;
        case 13: _t->on_chCanceled_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_toolButton_2_clicked(); break;
        case 15: _t->on_toolButton_clicked(); break;
        case 16: _t->tblMainDblClick((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FVauchers::staticMetaObject = { {
    QMetaObject::SuperData::link<WFilterBase::staticMetaObject>(),
    qt_meta_stringdata_FVauchers.data,
    qt_meta_data_FVauchers,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FVauchers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FVauchers::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FVauchers.stringdata0))
        return static_cast<void*>(this);
    return WFilterBase::qt_metacast(_clname);
}

int FVauchers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WFilterBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
