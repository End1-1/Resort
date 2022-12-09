/****************************************************************************
** Meta object code from reading C++ file 'fnoshowcancelationfee.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Filter/fnoshowcancelationfee.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fnoshowcancelationfee.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FNoShowCancelationFee_t {
    QByteArrayData data[6];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FNoShowCancelationFee_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FNoShowCancelationFee_t qt_meta_stringdata_FNoShowCancelationFee = {
    {
QT_MOC_LITERAL(0, 0, 21), // "FNoShowCancelationFee"
QT_MOC_LITERAL(1, 22, 16), // "doubleClickOnRow"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 3), // "row"
QT_MOC_LITERAL(4, 44, 18), // "on_btnBack_clicked"
QT_MOC_LITERAL(5, 63, 21) // "on_btnForward_clicked"

    },
    "FNoShowCancelationFee\0doubleClickOnRow\0"
    "\0row\0on_btnBack_clicked\0on_btnForward_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FNoShowCancelationFee[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariantList,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FNoShowCancelationFee::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FNoShowCancelationFee *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doubleClickOnRow((*reinterpret_cast< const QList<QVariant>(*)>(_a[1]))); break;
        case 1: _t->on_btnBack_clicked(); break;
        case 2: _t->on_btnForward_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FNoShowCancelationFee::staticMetaObject = { {
    QMetaObject::SuperData::link<WFilterBase::staticMetaObject>(),
    qt_meta_stringdata_FNoShowCancelationFee.data,
    qt_meta_data_FNoShowCancelationFee,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FNoShowCancelationFee::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FNoShowCancelationFee::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FNoShowCancelationFee.stringdata0))
        return static_cast<void*>(this);
    return WFilterBase::qt_metacast(_clname);
}

int FNoShowCancelationFee::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WFilterBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
