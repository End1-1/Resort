/****************************************************************************
** Meta object code from reading C++ file 'dlghouseitem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/dlghouseitem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlghouseitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DlgHouseItem_t {
    QByteArrayData data[13];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlgHouseItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlgHouseItem_t qt_meta_stringdata_DlgHouseItem = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DlgHouseItem"
QT_MOC_LITERAL(1, 13, 12), // "onOffClicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 29), // "comboStateCurrentIndexChanged"
QT_MOC_LITERAL(4, 57, 5), // "index"
QT_MOC_LITERAL(5, 63, 21), // "on_btnAddItem_clicked"
QT_MOC_LITERAL(6, 85, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(7, 104, 24), // "on_btnRemoveItem_clicked"
QT_MOC_LITERAL(8, 129, 24), // "on_btnSaveStates_clicked"
QT_MOC_LITERAL(9, 154, 18), // "on_btnCopy_clicked"
QT_MOC_LITERAL(10, 173, 19), // "on_btnPaste_clicked"
QT_MOC_LITERAL(11, 193, 26), // "on_btnDontDisturbe_clicked"
QT_MOC_LITERAL(12, 220, 7) // "checked"

    },
    "DlgHouseItem\0onOffClicked\0\0"
    "comboStateCurrentIndexChanged\0index\0"
    "on_btnAddItem_clicked\0on_btnSave_clicked\0"
    "on_btnRemoveItem_clicked\0"
    "on_btnSaveStates_clicked\0on_btnCopy_clicked\0"
    "on_btnPaste_clicked\0on_btnDontDisturbe_clicked\0"
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlgHouseItem[] = {

 // content:
       8,       // revision
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
       3,    1,   60,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    1,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,

       0        // eod
};

void DlgHouseItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DlgHouseItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onOffClicked(); break;
        case 1: _t->comboStateCurrentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_btnAddItem_clicked(); break;
        case 3: _t->on_btnSave_clicked(); break;
        case 4: _t->on_btnRemoveItem_clicked(); break;
        case 5: _t->on_btnSaveStates_clicked(); break;
        case 6: _t->on_btnCopy_clicked(); break;
        case 7: _t->on_btnPaste_clicked(); break;
        case 8: _t->on_btnDontDisturbe_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DlgHouseItem::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseExtendedDialog::staticMetaObject>(),
    qt_meta_stringdata_DlgHouseItem.data,
    qt_meta_data_DlgHouseItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DlgHouseItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlgHouseItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DlgHouseItem.stringdata0))
        return static_cast<void*>(this);
    return BaseExtendedDialog::qt_metacast(_clname);
}

int DlgHouseItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
