/****************************************************************************
** Meta object code from reading C++ file 'dlgreserveconfirmstatus.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/dlgreserveconfirmstatus.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgreserveconfirmstatus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DlgReserveConfirmStatus_t {
    QByteArrayData data[8];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlgReserveConfirmStatus_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlgReserveConfirmStatus_t qt_meta_stringdata_DlgReserveConfirmStatus = {
    {
QT_MOC_LITERAL(0, 0, 23), // "DlgReserveConfirmStatus"
QT_MOC_LITERAL(1, 24, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 23), // "on_btnConfirmed_clicked"
QT_MOC_LITERAL(4, 70, 23), // "on_btnGuaranted_clicked"
QT_MOC_LITERAL(5, 94, 23), // "on_btnTentative_clicked"
QT_MOC_LITERAL(6, 118, 21), // "on_btnWaiting_clicked"
QT_MOC_LITERAL(7, 140, 19) // "on_btnBlock_clicked"

    },
    "DlgReserveConfirmStatus\0on_btnCancel_clicked\0"
    "\0on_btnConfirmed_clicked\0"
    "on_btnGuaranted_clicked\0on_btnTentative_clicked\0"
    "on_btnWaiting_clicked\0on_btnBlock_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlgReserveConfirmStatus[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DlgReserveConfirmStatus::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DlgReserveConfirmStatus *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnCancel_clicked(); break;
        case 1: _t->on_btnConfirmed_clicked(); break;
        case 2: _t->on_btnGuaranted_clicked(); break;
        case 3: _t->on_btnTentative_clicked(); break;
        case 4: _t->on_btnWaiting_clicked(); break;
        case 5: _t->on_btnBlock_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DlgReserveConfirmStatus::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseExtendedDialog::staticMetaObject>(),
    qt_meta_stringdata_DlgReserveConfirmStatus.data,
    qt_meta_data_DlgReserveConfirmStatus,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DlgReserveConfirmStatus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlgReserveConfirmStatus::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DlgReserveConfirmStatus.stringdata0))
        return static_cast<void*>(this);
    return BaseExtendedDialog::qt_metacast(_clname);
}

int DlgReserveConfirmStatus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseExtendedDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
