/****************************************************************************
** Meta object code from reading C++ file 'wquickreservationsguests.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/wquickreservationsguests.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wquickreservationsguests.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WQuickReservationsGuests_t {
    QByteArrayData data[6];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WQuickReservationsGuests_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WQuickReservationsGuests_t qt_meta_stringdata_WQuickReservationsGuests = {
    {
QT_MOC_LITERAL(0, 0, 24), // "WQuickReservationsGuests"
QT_MOC_LITERAL(1, 25, 22), // "on_btnAddGuest_clicked"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 25), // "on_btnRemoveGuest_clicked"
QT_MOC_LITERAL(4, 75, 22), // "on_btnFullInfo_clicked"
QT_MOC_LITERAL(5, 98, 25) // "on_btnChangeGuest_clicked"

    },
    "WQuickReservationsGuests\0"
    "on_btnAddGuest_clicked\0\0"
    "on_btnRemoveGuest_clicked\0"
    "on_btnFullInfo_clicked\0on_btnChangeGuest_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WQuickReservationsGuests[] = {

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
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WQuickReservationsGuests::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WQuickReservationsGuests *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnAddGuest_clicked(); break;
        case 1: _t->on_btnRemoveGuest_clicked(); break;
        case 2: _t->on_btnFullInfo_clicked(); break;
        case 3: _t->on_btnChangeGuest_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject WQuickReservationsGuests::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseDialog::staticMetaObject>(),
    qt_meta_stringdata_WQuickReservationsGuests.data,
    qt_meta_data_WQuickReservationsGuests,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WQuickReservationsGuests::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WQuickReservationsGuests::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WQuickReservationsGuests.stringdata0))
        return static_cast<void*>(this);
    return BaseDialog::qt_metacast(_clname);
}

int WQuickReservationsGuests::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseDialog::qt_metacall(_c, _id, _a);
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
