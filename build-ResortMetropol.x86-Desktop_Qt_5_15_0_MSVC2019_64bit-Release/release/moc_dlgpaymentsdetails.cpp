/****************************************************************************
** Meta object code from reading C++ file 'dlgpaymentsdetails.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/dlgpaymentsdetails.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgpaymentsdetails.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DlgPaymentsDetails_t {
    QByteArrayData data[16];
    char stringdata0[269];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlgPaymentsDetails_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlgPaymentsDetails_t qt_meta_stringdata_DlgPaymentsDetails = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DlgPaymentsDetails"
QT_MOC_LITERAL(1, 19, 12), // "refundRemove"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 3), // "tag"
QT_MOC_LITERAL(4, 37, 17), // "refundTextChanged"
QT_MOC_LITERAL(5, 55, 4), // "text"
QT_MOC_LITERAL(6, 60, 16), // "removeRowClicked"
QT_MOC_LITERAL(7, 77, 20), // "amountLineEditEdited"
QT_MOC_LITERAL(8, 98, 18), // "on_btnCash_clicked"
QT_MOC_LITERAL(9, 117, 18), // "on_btnCard_clicked"
QT_MOC_LITERAL(10, 136, 24), // "on_btnCityLedger_clicked"
QT_MOC_LITERAL(11, 161, 18), // "on_btnBank_clicked"
QT_MOC_LITERAL(12, 180, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(13, 199, 21), // "on_btnOptions_clicked"
QT_MOC_LITERAL(14, 221, 22), // "on_btnBankPayX_clicked"
QT_MOC_LITERAL(15, 244, 24) // "on_btnBankPayX_2_clicked"

    },
    "DlgPaymentsDetails\0refundRemove\0\0tag\0"
    "refundTextChanged\0text\0removeRowClicked\0"
    "amountLineEditEdited\0on_btnCash_clicked\0"
    "on_btnCard_clicked\0on_btnCityLedger_clicked\0"
    "on_btnBank_clicked\0on_btnSave_clicked\0"
    "on_btnOptions_clicked\0on_btnBankPayX_clicked\0"
    "on_btnBankPayX_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlgPaymentsDetails[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    1,   77,    2, 0x08 /* Private */,
       6,    1,   80,    2, 0x08 /* Private */,
       7,    1,   83,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DlgPaymentsDetails::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DlgPaymentsDetails *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refundRemove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->refundTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->removeRowClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->amountLineEditEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_btnCash_clicked(); break;
        case 5: _t->on_btnCard_clicked(); break;
        case 6: _t->on_btnCityLedger_clicked(); break;
        case 7: _t->on_btnBank_clicked(); break;
        case 8: _t->on_btnSave_clicked(); break;
        case 9: _t->on_btnOptions_clicked(); break;
        case 10: _t->on_btnBankPayX_clicked(); break;
        case 11: _t->on_btnBankPayX_2_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DlgPaymentsDetails::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseExtendedDialog::staticMetaObject>(),
    qt_meta_stringdata_DlgPaymentsDetails.data,
    qt_meta_data_DlgPaymentsDetails,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DlgPaymentsDetails::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlgPaymentsDetails::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DlgPaymentsDetails.stringdata0))
        return static_cast<void*>(this);
    return BaseExtendedDialog::qt_metacast(_clname);
}

int DlgPaymentsDetails::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseExtendedDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
