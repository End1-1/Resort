/****************************************************************************
** Meta object code from reading C++ file 'dlgreceiptvaucher.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/dlgreceiptvaucher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgreceiptvaucher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DlgReceiptVaucher_t {
    QByteArrayData data[13];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlgReceiptVaucher_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlgReceiptVaucher_t qt_meta_stringdata_DlgReceiptVaucher = {
    {
QT_MOC_LITERAL(0, 0, 17), // "DlgReceiptVaucher"
QT_MOC_LITERAL(1, 18, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(4, 59, 19), // "on_btnPrint_clicked"
QT_MOC_LITERAL(5, 79, 25), // "on_leAmountAMD_textEdited"
QT_MOC_LITERAL(6, 105, 4), // "arg1"
QT_MOC_LITERAL(7, 110, 17), // "on_btnNew_clicked"
QT_MOC_LITERAL(8, 128, 28), // "on_lePaymentCode_textChanged"
QT_MOC_LITERAL(9, 157, 17), // "on_btnLog_clicked"
QT_MOC_LITERAL(10, 175, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(11, 203, 5), // "index"
QT_MOC_LITERAL(12, 209, 27) // "on_btnSuggestAmount_clicked"

    },
    "DlgReceiptVaucher\0on_btnSave_clicked\0"
    "\0on_btnCancel_clicked\0on_btnPrint_clicked\0"
    "on_leAmountAMD_textEdited\0arg1\0"
    "on_btnNew_clicked\0on_lePaymentCode_textChanged\0"
    "on_btnLog_clicked\0on_tabWidget_currentChanged\0"
    "index\0on_btnSuggestAmount_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlgReceiptVaucher[] = {

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
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    1,   66,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    1,   70,    2, 0x08 /* Private */,
      12,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,

       0        // eod
};

void DlgReceiptVaucher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DlgReceiptVaucher *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnSave_clicked(); break;
        case 1: _t->on_btnCancel_clicked(); break;
        case 2: _t->on_btnPrint_clicked(); break;
        case 3: _t->on_leAmountAMD_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_btnNew_clicked(); break;
        case 5: _t->on_lePaymentCode_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_btnLog_clicked(); break;
        case 7: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_btnSuggestAmount_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DlgReceiptVaucher::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseExtendedDialog::staticMetaObject>(),
    qt_meta_stringdata_DlgReceiptVaucher.data,
    qt_meta_data_DlgReceiptVaucher,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DlgReceiptVaucher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlgReceiptVaucher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DlgReceiptVaucher.stringdata0))
        return static_cast<void*>(this);
    return BaseExtendedDialog::qt_metacast(_clname);
}

int DlgReceiptVaucher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseExtendedDialog::qt_metacall(_c, _id, _a);
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
