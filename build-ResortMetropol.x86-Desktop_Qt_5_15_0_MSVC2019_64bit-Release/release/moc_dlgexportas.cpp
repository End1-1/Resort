/****************************************************************************
** Meta object code from reading C++ file 'dlgexportas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/dlgexportas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgexportas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DlgExportAS_t {
    QByteArrayData data[10];
    char stringdata0[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlgExportAS_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlgExportAS_t qt_meta_stringdata_DlgExportAS = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DlgExportAS"
QT_MOC_LITERAL(1, 12, 31), // "on_btnUploadPostCharges_clicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 28), // "on_btnSaveAsSettings_clicked"
QT_MOC_LITERAL(4, 74, 28), // "on_btnUploadInvoices_clicked"
QT_MOC_LITERAL(5, 103, 28), // "on_btnUploadPayments_clicked"
QT_MOC_LITERAL(6, 132, 34), // "on_btnUploadInvoicesRetail_cl..."
QT_MOC_LITERAL(7, 167, 35), // "on__5lePartnerDebet_editingFi..."
QT_MOC_LITERAL(8, 203, 36), // "on__5lePartnerCredit_editingF..."
QT_MOC_LITERAL(9, 240, 21) // "on__5btnStart_clicked"

    },
    "DlgExportAS\0on_btnUploadPostCharges_clicked\0"
    "\0on_btnSaveAsSettings_clicked\0"
    "on_btnUploadInvoices_clicked\0"
    "on_btnUploadPayments_clicked\0"
    "on_btnUploadInvoicesRetail_clicked\0"
    "on__5lePartnerDebet_editingFinished\0"
    "on__5lePartnerCredit_editingFinished\0"
    "on__5btnStart_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlgExportAS[] = {

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
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
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

void DlgExportAS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DlgExportAS *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnUploadPostCharges_clicked(); break;
        case 1: _t->on_btnSaveAsSettings_clicked(); break;
        case 2: _t->on_btnUploadInvoices_clicked(); break;
        case 3: _t->on_btnUploadPayments_clicked(); break;
        case 4: _t->on_btnUploadInvoicesRetail_clicked(); break;
        case 5: _t->on__5lePartnerDebet_editingFinished(); break;
        case 6: _t->on__5lePartnerCredit_editingFinished(); break;
        case 7: _t->on__5btnStart_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DlgExportAS::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseDialog::staticMetaObject>(),
    qt_meta_stringdata_DlgExportAS.data,
    qt_meta_data_DlgExportAS,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DlgExportAS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlgExportAS::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DlgExportAS.stringdata0))
        return static_cast<void*>(this);
    return BaseDialog::qt_metacast(_clname);
}

int DlgExportAS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseDialog::qt_metacall(_c, _id, _a);
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
