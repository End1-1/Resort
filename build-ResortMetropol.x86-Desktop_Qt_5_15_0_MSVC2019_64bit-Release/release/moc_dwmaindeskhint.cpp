/****************************************************************************
** Meta object code from reading C++ file 'dwmaindeskhint.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/dwmaindeskhint.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dwmaindeskhint.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DWMainDeskHint_t {
    QByteArrayData data[10];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DWMainDeskHint_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DWMainDeskHint_t qt_meta_stringdata_DWMainDeskHint = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DWMainDeskHint"
QT_MOC_LITERAL(1, 15, 23), // "tblHeaderSectionClicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 12), // "logicalIndex"
QT_MOC_LITERAL(4, 53, 21), // "thisVisibilityChanged"
QT_MOC_LITERAL(5, 75, 1), // "v"
QT_MOC_LITERAL(6, 77, 21), // "on_btnCheckIn_clicked"
QT_MOC_LITERAL(7, 99, 14), // "on_tbl_clicked"
QT_MOC_LITERAL(8, 114, 11), // "QModelIndex"
QT_MOC_LITERAL(9, 126, 5) // "index"

    },
    "DWMainDeskHint\0tblHeaderSectionClicked\0"
    "\0logicalIndex\0thisVisibilityChanged\0"
    "v\0on_btnCheckIn_clicked\0on_tbl_clicked\0"
    "QModelIndex\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DWMainDeskHint[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    1,   37,    2, 0x08 /* Private */,
       6,    0,   40,    2, 0x08 /* Private */,
       7,    1,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void DWMainDeskHint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DWMainDeskHint *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tblHeaderSectionClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->thisVisibilityChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_btnCheckIn_clicked(); break;
        case 3: _t->on_tbl_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DWMainDeskHint::staticMetaObject = { {
    QMetaObject::SuperData::link<QDockWidget::staticMetaObject>(),
    qt_meta_stringdata_DWMainDeskHint.data,
    qt_meta_data_DWMainDeskHint,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DWMainDeskHint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DWMainDeskHint::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DWMainDeskHint.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Base"))
        return static_cast< Base*>(this);
    return QDockWidget::qt_metacast(_clname);
}

int DWMainDeskHint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
