/****************************************************************************
** Meta object code from reading C++ file 'dlgsimpleselectroom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/dlgsimpleselectroom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgsimpleselectroom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DlgSimpleSelectRoom_t {
    QByteArrayData data[12];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlgSimpleSelectRoom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlgSimpleSelectRoom_t qt_meta_stringdata_DlgSimpleSelectRoom = {
    {
QT_MOC_LITERAL(0, 0, 19), // "DlgSimpleSelectRoom"
QT_MOC_LITERAL(1, 20, 24), // "on_tblData_doubleClicked"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 58, 5), // "index"
QT_MOC_LITERAL(5, 64, 19), // "on_tblSmoke_clicked"
QT_MOC_LITERAL(6, 84, 19), // "on_tblFloor_clicked"
QT_MOC_LITERAL(7, 104, 17), // "on_tblBed_clicked"
QT_MOC_LITERAL(8, 122, 29), // "on_btnClearRoomFilter_clicked"
QT_MOC_LITERAL(9, 152, 25), // "on_btnMultiSelect_clicked"
QT_MOC_LITERAL(10, 178, 18), // "on_tblData_clicked"
QT_MOC_LITERAL(11, 197, 22) // "on_tblCategory_clicked"

    },
    "DlgSimpleSelectRoom\0on_tblData_doubleClicked\0"
    "\0QModelIndex\0index\0on_tblSmoke_clicked\0"
    "on_tblFloor_clicked\0on_tblBed_clicked\0"
    "on_btnClearRoomFilter_clicked\0"
    "on_btnMultiSelect_clicked\0on_tblData_clicked\0"
    "on_tblCategory_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlgSimpleSelectRoom[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       5,    1,   57,    2, 0x08 /* Private */,
       6,    1,   60,    2, 0x08 /* Private */,
       7,    1,   63,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    1,   68,    2, 0x08 /* Private */,
      11,    1,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void DlgSimpleSelectRoom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DlgSimpleSelectRoom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tblData_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_tblSmoke_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_tblFloor_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_tblBed_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_btnClearRoomFilter_clicked(); break;
        case 5: _t->on_btnMultiSelect_clicked(); break;
        case 6: _t->on_tblData_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_tblCategory_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DlgSimpleSelectRoom::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseExtendedDialog::staticMetaObject>(),
    qt_meta_stringdata_DlgSimpleSelectRoom.data,
    qt_meta_data_DlgSimpleSelectRoom,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DlgSimpleSelectRoom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlgSimpleSelectRoom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DlgSimpleSelectRoom.stringdata0))
        return static_cast<void*>(this);
    return BaseExtendedDialog::qt_metacast(_clname);
}

int DlgSimpleSelectRoom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseExtendedDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
