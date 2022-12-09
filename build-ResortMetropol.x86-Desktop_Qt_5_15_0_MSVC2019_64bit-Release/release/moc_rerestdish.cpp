/****************************************************************************
** Meta object code from reading C++ file 'rerestdish.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RowEditor/rerestdish.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rerestdish.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RERestDish_t {
    QByteArrayData data[19];
    char stringdata0[326];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RERestDish_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RERestDish_t qt_meta_stringdata_RERestDish = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RERestDish"
QT_MOC_LITERAL(1, 11, 12), // "checkComplex"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 1), // "v"
QT_MOC_LITERAL(4, 27, 19), // "tabPageIndexChanged"
QT_MOC_LITERAL(5, 47, 5), // "index"
QT_MOC_LITERAL(6, 53, 17), // "btnRemoveModifier"
QT_MOC_LITERAL(7, 71, 3), // "row"
QT_MOC_LITERAL(8, 75, 23), // "on_btnTextColor_clicked"
QT_MOC_LITERAL(9, 99, 21), // "on_btnBgColor_clicked"
QT_MOC_LITERAL(10, 121, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(11, 142, 16), // "on_btnOk_clicked"
QT_MOC_LITERAL(12, 159, 23), // "on_btnLoadImage_clicked"
QT_MOC_LITERAL(13, 183, 29), // "on_btnRemoveRecipeRow_clicked"
QT_MOC_LITERAL(14, 213, 25), // "on_btnClearRecipe_clicked"
QT_MOC_LITERAL(15, 239, 26), // "on_chContainItself_clicked"
QT_MOC_LITERAL(16, 266, 7), // "checked"
QT_MOC_LITERAL(17, 274, 19), // "on_btnTrack_clicked"
QT_MOC_LITERAL(18, 294, 31) // "on_leReadScancode_returnPressed"

    },
    "RERestDish\0checkComplex\0\0v\0"
    "tabPageIndexChanged\0index\0btnRemoveModifier\0"
    "row\0on_btnTextColor_clicked\0"
    "on_btnBgColor_clicked\0on_btnCancel_clicked\0"
    "on_btnOk_clicked\0on_btnLoadImage_clicked\0"
    "on_btnRemoveRecipeRow_clicked\0"
    "on_btnClearRecipe_clicked\0"
    "on_chContainItself_clicked\0checked\0"
    "on_btnTrack_clicked\0on_leReadScancode_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RERestDish[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       4,    1,   82,    2, 0x08 /* Private */,
       6,    1,   85,    2, 0x08 /* Private */,
       8,    0,   88,    2, 0x08 /* Private */,
       9,    0,   89,    2, 0x08 /* Private */,
      10,    0,   90,    2, 0x08 /* Private */,
      11,    0,   91,    2, 0x08 /* Private */,
      12,    0,   92,    2, 0x08 /* Private */,
      13,    0,   93,    2, 0x08 /* Private */,
      14,    0,   94,    2, 0x08 /* Private */,
      15,    1,   95,    2, 0x08 /* Private */,
      17,    0,   98,    2, 0x08 /* Private */,
      18,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RERestDish::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RERestDish *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkComplex((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->tabPageIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->btnRemoveModifier((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_btnTextColor_clicked(); break;
        case 4: _t->on_btnBgColor_clicked(); break;
        case 5: _t->on_btnCancel_clicked(); break;
        case 6: _t->on_btnOk_clicked(); break;
        case 7: _t->on_btnLoadImage_clicked(); break;
        case 8: _t->on_btnRemoveRecipeRow_clicked(); break;
        case 9: _t->on_btnClearRecipe_clicked(); break;
        case 10: _t->on_chContainItself_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_btnTrack_clicked(); break;
        case 12: _t->on_leReadScancode_returnPressed(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RERestDish::staticMetaObject = { {
    QMetaObject::SuperData::link<RowEditorDialog::staticMetaObject>(),
    qt_meta_stringdata_RERestDish.data,
    qt_meta_data_RERestDish,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RERestDish::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RERestDish::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RERestDish.stringdata0))
        return static_cast<void*>(this);
    return RowEditorDialog::qt_metacast(_clname);
}

int RERestDish::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RowEditorDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
