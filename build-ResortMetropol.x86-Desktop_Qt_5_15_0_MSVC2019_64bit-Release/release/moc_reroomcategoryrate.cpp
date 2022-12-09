/****************************************************************************
** Meta object code from reading C++ file 'reroomcategoryrate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RowEditor/reroomcategoryrate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reroomcategoryrate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RERoomCategoryRate_t {
    QByteArrayData data[9];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RERoomCategoryRate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RERoomCategoryRate_t qt_meta_stringdata_RERoomCategoryRate = {
    {
QT_MOC_LITERAL(0, 0, 18), // "RERoomCategoryRate"
QT_MOC_LITERAL(1, 19, 12), // "handleValues"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 3), // "out"
QT_MOC_LITERAL(4, 37, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(5, 58, 16), // "on_btnOk_clicked"
QT_MOC_LITERAL(6, 75, 21), // "on_btnAddRate_clicked"
QT_MOC_LITERAL(7, 97, 24), // "on_btnRemoveRate_clicked"
QT_MOC_LITERAL(8, 122, 22) // "on_btnEditRate_clicked"

    },
    "RERoomCategoryRate\0handleValues\0\0out\0"
    "on_btnCancel_clicked\0on_btnOk_clicked\0"
    "on_btnAddRate_clicked\0on_btnRemoveRate_clicked\0"
    "on_btnEditRate_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RERoomCategoryRate[] = {

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
       1,    1,   44,    2, 0x09 /* Protected */,
       4,    0,   47,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariantList,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RERoomCategoryRate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RERoomCategoryRate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleValues((*reinterpret_cast< const QList<QVariant>(*)>(_a[1]))); break;
        case 1: _t->on_btnCancel_clicked(); break;
        case 2: _t->on_btnOk_clicked(); break;
        case 3: _t->on_btnAddRate_clicked(); break;
        case 4: _t->on_btnRemoveRate_clicked(); break;
        case 5: _t->on_btnEditRate_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RERoomCategoryRate::staticMetaObject = { {
    QMetaObject::SuperData::link<RECustomAction::staticMetaObject>(),
    qt_meta_stringdata_RERoomCategoryRate.data,
    qt_meta_data_RERoomCategoryRate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RERoomCategoryRate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RERoomCategoryRate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RERoomCategoryRate.stringdata0))
        return static_cast<void*>(this);
    return RECustomAction::qt_metacast(_clname);
}

int RERoomCategoryRate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RECustomAction::qt_metacall(_c, _id, _a);
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
