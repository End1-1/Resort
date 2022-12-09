/****************************************************************************
** Meta object code from reading C++ file 'dlgcheckadvancebeforecancel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/dlgcheckadvancebeforecancel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgcheckadvancebeforecancel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DlgCheckAdvanceBeforeCancel_t {
    QByteArrayData data[7];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlgCheckAdvanceBeforeCancel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlgCheckAdvanceBeforeCancel_t qt_meta_stringdata_DlgCheckAdvanceBeforeCancel = {
    {
QT_MOC_LITERAL(0, 0, 27), // "DlgCheckAdvanceBeforeCancel"
QT_MOC_LITERAL(1, 28, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 20), // "on_btnNoShow_clicked"
QT_MOC_LITERAL(4, 71, 20), // "on_btnRefund_clicked"
QT_MOC_LITERAL(5, 92, 31), // "on_btnCancelreservation_clicked"
QT_MOC_LITERAL(6, 124, 26) // "on_btnTransferToCL_clicked"

    },
    "DlgCheckAdvanceBeforeCancel\0"
    "on_btnCancel_clicked\0\0on_btnNoShow_clicked\0"
    "on_btnRefund_clicked\0"
    "on_btnCancelreservation_clicked\0"
    "on_btnTransferToCL_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlgCheckAdvanceBeforeCancel[] = {

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
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DlgCheckAdvanceBeforeCancel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DlgCheckAdvanceBeforeCancel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnCancel_clicked(); break;
        case 1: _t->on_btnNoShow_clicked(); break;
        case 2: _t->on_btnRefund_clicked(); break;
        case 3: _t->on_btnCancelreservation_clicked(); break;
        case 4: _t->on_btnTransferToCL_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DlgCheckAdvanceBeforeCancel::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseDialog::staticMetaObject>(),
    qt_meta_stringdata_DlgCheckAdvanceBeforeCancel.data,
    qt_meta_data_DlgCheckAdvanceBeforeCancel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DlgCheckAdvanceBeforeCancel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlgCheckAdvanceBeforeCancel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DlgCheckAdvanceBeforeCancel.stringdata0))
        return static_cast<void*>(this);
    return BaseDialog::qt_metacast(_clname);
}

int DlgCheckAdvanceBeforeCancel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
