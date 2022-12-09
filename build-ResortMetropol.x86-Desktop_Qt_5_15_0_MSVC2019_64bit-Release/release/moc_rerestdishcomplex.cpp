/****************************************************************************
** Meta object code from reading C++ file 'rerestdishcomplex.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RowEditor/rerestdishcomplex.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rerestdishcomplex.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RERestDishComplex_t {
    QByteArrayData data[7];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RERestDishComplex_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RERestDishComplex_t qt_meta_stringdata_RERestDishComplex = {
    {
QT_MOC_LITERAL(0, 0, 17), // "RERestDishComplex"
QT_MOC_LITERAL(1, 18, 9), // "removeRow"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 3), // "row"
QT_MOC_LITERAL(4, 33, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(5, 54, 16), // "on_btnOK_clicked"
QT_MOC_LITERAL(6, 71, 17) // "on_btnAdd_clicked"

    },
    "RERestDishComplex\0removeRow\0\0row\0"
    "on_btnCancel_clicked\0on_btnOK_clicked\0"
    "on_btnAdd_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RERestDishComplex[] = {

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
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RERestDishComplex::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RERestDishComplex *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->removeRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_btnCancel_clicked(); break;
        case 2: _t->on_btnOK_clicked(); break;
        case 3: _t->on_btnAdd_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RERestDishComplex::staticMetaObject = { {
    QMetaObject::SuperData::link<RowEditorDialog::staticMetaObject>(),
    qt_meta_stringdata_RERestDishComplex.data,
    qt_meta_data_RERestDishComplex,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RERestDishComplex::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RERestDishComplex::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RERestDishComplex.stringdata0))
        return static_cast<void*>(this);
    return RowEditorDialog::qt_metacast(_clname);
}

int RERestDishComplex::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RowEditorDialog::qt_metacall(_c, _id, _a);
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
