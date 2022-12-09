/****************************************************************************
** Meta object code from reading C++ file 'fdishes.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Filter/fdishes.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fdishes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FDishes_t {
    QByteArrayData data[7];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FDishes_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FDishes_t qt_meta_stringdata_FDishes = {
    {
QT_MOC_LITERAL(0, 0, 7), // "FDishes"
QT_MOC_LITERAL(1, 8, 16), // "doubleClickOnRow"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "row"
QT_MOC_LITERAL(4, 30, 6), // "newBtn"
QT_MOC_LITERAL(5, 37, 25), // "on_btnGetFromCafe_clicked"
QT_MOC_LITERAL(6, 63, 30) // "on_btnUpdateMenuNumber_clicked"

    },
    "FDishes\0doubleClickOnRow\0\0row\0newBtn\0"
    "on_btnGetFromCafe_clicked\0"
    "on_btnUpdateMenuNumber_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FDishes[] = {

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
    QMetaType::Void, QMetaType::QVariantList,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FDishes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FDishes *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doubleClickOnRow((*reinterpret_cast< const QList<QVariant>(*)>(_a[1]))); break;
        case 1: _t->newBtn(); break;
        case 2: _t->on_btnGetFromCafe_clicked(); break;
        case 3: _t->on_btnUpdateMenuNumber_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FDishes::staticMetaObject = { {
    QMetaObject::SuperData::link<WFilterBase::staticMetaObject>(),
    qt_meta_stringdata_FDishes.data,
    qt_meta_data_FDishes,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FDishes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FDishes::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FDishes.stringdata0))
        return static_cast<void*>(this);
    return WFilterBase::qt_metacast(_clname);
}

int FDishes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WFilterBase::qt_metacall(_c, _id, _a);
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
