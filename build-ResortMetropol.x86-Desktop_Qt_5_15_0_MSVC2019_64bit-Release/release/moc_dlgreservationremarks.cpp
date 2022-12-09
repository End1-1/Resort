/****************************************************************************
** Meta object code from reading C++ file 'dlgreservationremarks.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/dlgreservationremarks.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgreservationremarks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DlgReservationRemarks_t {
    QByteArrayData data[11];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlgReservationRemarks_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlgReservationRemarks_t qt_meta_stringdata_DlgReservationRemarks = {
    {
QT_MOC_LITERAL(0, 0, 21), // "DlgReservationRemarks"
QT_MOC_LITERAL(1, 22, 18), // "on_tblData_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 54, 5), // "index"
QT_MOC_LITERAL(5, 60, 28), // "on_btnRemoveSelected_clicked"
QT_MOC_LITERAL(6, 89, 20), // "on_btnSaveAs_clicked"
QT_MOC_LITERAL(7, 110, 25), // "on_btnSaveCurrent_clicked"
QT_MOC_LITERAL(8, 136, 16), // "on_btnOk_clicked"
QT_MOC_LITERAL(9, 153, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(10, 174, 24) // "on_tblData_doubleClicked"

    },
    "DlgReservationRemarks\0on_tblData_clicked\0"
    "\0QModelIndex\0index\0on_btnRemoveSelected_clicked\0"
    "on_btnSaveAs_clicked\0on_btnSaveCurrent_clicked\0"
    "on_btnOk_clicked\0on_btnCancel_clicked\0"
    "on_tblData_doubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlgReservationRemarks[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,
       9,    0,   56,    2, 0x08 /* Private */,
      10,    1,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void DlgReservationRemarks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DlgReservationRemarks *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tblData_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_btnRemoveSelected_clicked(); break;
        case 2: _t->on_btnSaveAs_clicked(); break;
        case 3: _t->on_btnSaveCurrent_clicked(); break;
        case 4: _t->on_btnOk_clicked(); break;
        case 5: _t->on_btnCancel_clicked(); break;
        case 6: _t->on_tblData_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DlgReservationRemarks::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseExtendedDialog::staticMetaObject>(),
    qt_meta_stringdata_DlgReservationRemarks.data,
    qt_meta_data_DlgReservationRemarks,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DlgReservationRemarks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlgReservationRemarks::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DlgReservationRemarks.stringdata0))
        return static_cast<void*>(this);
    return BaseExtendedDialog::qt_metacast(_clname);
}

int DlgReservationRemarks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseExtendedDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
