/****************************************************************************
** Meta object code from reading C++ file 'printtax.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Resort2/Print/printtax.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'printtax.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PrintTax_t {
    QByteArrayData data[14];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PrintTax_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PrintTax_t qt_meta_stringdata_PrintTax = {
    {
QT_MOC_LITERAL(0, 0, 8), // "PrintTax"
QT_MOC_LITERAL(1, 9, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 19), // "on_btnPrint_clicked"
QT_MOC_LITERAL(4, 51, 18), // "on_tblData_clicked"
QT_MOC_LITERAL(5, 70, 5), // "index"
QT_MOC_LITERAL(6, 76, 20), // "on_leCard_textEdited"
QT_MOC_LITERAL(7, 97, 4), // "arg1"
QT_MOC_LITERAL(8, 102, 20), // "on_leCash_textEdited"
QT_MOC_LITERAL(9, 123, 19), // "on_lePre_textEdited"
QT_MOC_LITERAL(10, 143, 28), // "on_chCheckUncheckAll_clicked"
QT_MOC_LITERAL(11, 172, 7), // "checked"
QT_MOC_LITERAL(12, 180, 20), // "on_tblFilter_clicked"
QT_MOC_LITERAL(13, 201, 25) // "on_btnClearFilter_clicked"

    },
    "PrintTax\0on_btnCancel_clicked\0\0"
    "on_btnPrint_clicked\0on_tblData_clicked\0"
    "index\0on_leCard_textEdited\0arg1\0"
    "on_leCash_textEdited\0on_lePre_textEdited\0"
    "on_chCheckUncheckAll_clicked\0checked\0"
    "on_tblFilter_clicked\0on_btnClearFilter_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrintTax[] = {

 // content:
       7,       // revision
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
       4,    1,   61,    2, 0x08 /* Private */,
       6,    1,   64,    2, 0x08 /* Private */,
       8,    1,   67,    2, 0x08 /* Private */,
       9,    1,   70,    2, 0x08 /* Private */,
      10,    1,   73,    2, 0x08 /* Private */,
      12,    1,   76,    2, 0x08 /* Private */,
      13,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void,

       0        // eod
};

void PrintTax::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PrintTax *_t = static_cast<PrintTax *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnCancel_clicked(); break;
        case 1: _t->on_btnPrint_clicked(); break;
        case 2: _t->on_tblData_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_leCard_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_leCash_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_lePre_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_chCheckUncheckAll_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_tblFilter_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_btnClearFilter_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject PrintTax::staticMetaObject = {
    { &BaseExtendedDialog::staticMetaObject, qt_meta_stringdata_PrintTax.data,
      qt_meta_data_PrintTax,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PrintTax::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrintTax::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PrintTax.stringdata0))
        return static_cast<void*>(this);
    return BaseExtendedDialog::qt_metacast(_clname);
}

int PrintTax::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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