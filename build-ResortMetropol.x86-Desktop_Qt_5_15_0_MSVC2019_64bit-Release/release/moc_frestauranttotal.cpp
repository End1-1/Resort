/****************************************************************************
** Meta object code from reading C++ file 'frestauranttotal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Filter/frestauranttotal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frestauranttotal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FRestaurantTotal_t {
    QByteArrayData data[10];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FRestaurantTotal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FRestaurantTotal_t qt_meta_stringdata_FRestaurantTotal = {
    {
QT_MOC_LITERAL(0, 0, 16), // "FRestaurantTotal"
QT_MOC_LITERAL(1, 17, 12), // "printReceipt"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 11), // "removeOrder"
QT_MOC_LITERAL(4, 43, 17), // "removePermanently"
QT_MOC_LITERAL(5, 61, 28), // "on_btnOrdersSubtotal_clicked"
QT_MOC_LITERAL(6, 90, 11), // "doubleClick"
QT_MOC_LITERAL(7, 102, 3), // "row"
QT_MOC_LITERAL(8, 106, 22), // "on_btnPrevDate_clicked"
QT_MOC_LITERAL(9, 129, 22) // "on_btnNextDate_clicked"

    },
    "FRestaurantTotal\0printReceipt\0\0"
    "removeOrder\0removePermanently\0"
    "on_btnOrdersSubtotal_clicked\0doubleClick\0"
    "row\0on_btnPrevDate_clicked\0"
    "on_btnNextDate_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FRestaurantTotal[] = {

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
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantList,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FRestaurantTotal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FRestaurantTotal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->printReceipt(); break;
        case 1: _t->removeOrder(); break;
        case 2: _t->removePermanently(); break;
        case 3: _t->on_btnOrdersSubtotal_clicked(); break;
        case 4: _t->doubleClick((*reinterpret_cast< const QList<QVariant>(*)>(_a[1]))); break;
        case 5: _t->on_btnPrevDate_clicked(); break;
        case 6: _t->on_btnNextDate_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FRestaurantTotal::staticMetaObject = { {
    QMetaObject::SuperData::link<WFilterBase::staticMetaObject>(),
    qt_meta_stringdata_FRestaurantTotal.data,
    qt_meta_data_FRestaurantTotal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FRestaurantTotal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FRestaurantTotal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FRestaurantTotal.stringdata0))
        return static_cast<void*>(this);
    return WFilterBase::qt_metacast(_clname);
}

int FRestaurantTotal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WFilterBase::qt_metacall(_c, _id, _a);
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
