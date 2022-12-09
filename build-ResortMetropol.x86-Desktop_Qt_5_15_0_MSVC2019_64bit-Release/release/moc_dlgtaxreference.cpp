/****************************************************************************
** Meta object code from reading C++ file 'dlgtaxreference.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/dlgtaxreference.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgtaxreference.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DlgTaxReference_t {
    QByteArrayData data[12];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlgTaxReference_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlgTaxReference_t qt_meta_stringdata_DlgTaxReference = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DlgTaxReference"
QT_MOC_LITERAL(1, 16, 14), // "tblContextMenu"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 1), // "p"
QT_MOC_LITERAL(4, 34, 9), // "deleteRow"
QT_MOC_LITERAL(5, 44, 22), // "on_leSearch_textEdited"
QT_MOC_LITERAL(6, 67, 4), // "arg1"
QT_MOC_LITERAL(7, 72, 24), // "on_tblData_doubleClicked"
QT_MOC_LITERAL(8, 97, 11), // "QModelIndex"
QT_MOC_LITERAL(9, 109, 5), // "index"
QT_MOC_LITERAL(10, 115, 23), // "on_rbAllInvoice_clicked"
QT_MOC_LITERAL(11, 139, 24) // "on_rbThisInvoice_clicked"

    },
    "DlgTaxReference\0tblContextMenu\0\0p\0"
    "deleteRow\0on_leSearch_textEdited\0arg1\0"
    "on_tblData_doubleClicked\0QModelIndex\0"
    "index\0on_rbAllInvoice_clicked\0"
    "on_rbThisInvoice_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlgTaxReference[] = {

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
       1,    1,   44,    2, 0x08 /* Private */,
       4,    0,   47,    2, 0x08 /* Private */,
       5,    1,   48,    2, 0x08 /* Private */,
       7,    1,   51,    2, 0x08 /* Private */,
      10,    0,   54,    2, 0x08 /* Private */,
      11,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DlgTaxReference::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DlgTaxReference *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tblContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->deleteRow(); break;
        case 2: _t->on_leSearch_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_tblData_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_rbAllInvoice_clicked(); break;
        case 5: _t->on_rbThisInvoice_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DlgTaxReference::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseExtendedDialog::staticMetaObject>(),
    qt_meta_stringdata_DlgTaxReference.data,
    qt_meta_data_DlgTaxReference,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DlgTaxReference::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlgTaxReference::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DlgTaxReference.stringdata0))
        return static_cast<void*>(this);
    return BaseExtendedDialog::qt_metacast(_clname);
}

int DlgTaxReference::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
