/****************************************************************************
** Meta object code from reading C++ file 'wquickreservations.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/wquickreservations.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wquickreservations.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WQuickReservationsDelegate_t {
    QByteArrayData data[1];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WQuickReservationsDelegate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WQuickReservationsDelegate_t qt_meta_stringdata_WQuickReservationsDelegate = {
    {
QT_MOC_LITERAL(0, 0, 26) // "WQuickReservationsDelegate"

    },
    "WQuickReservationsDelegate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WQuickReservationsDelegate[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void WQuickReservationsDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject WQuickReservationsDelegate::staticMetaObject = { {
    QMetaObject::SuperData::link<QItemDelegate::staticMetaObject>(),
    qt_meta_stringdata_WQuickReservationsDelegate.data,
    qt_meta_data_WQuickReservationsDelegate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WQuickReservationsDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WQuickReservationsDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WQuickReservationsDelegate.stringdata0))
        return static_cast<void*>(this);
    return QItemDelegate::qt_metacast(_clname);
}

int WQuickReservationsDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QItemDelegate::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_WQuickReservations_t {
    QByteArrayData data[17];
    char stringdata0[326];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WQuickReservations_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WQuickReservations_t qt_meta_stringdata_WQuickReservations = {
    {
QT_MOC_LITERAL(0, 0, 18), // "WQuickReservations"
QT_MOC_LITERAL(1, 19, 16), // "totalScrollValue"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 5), // "value"
QT_MOC_LITERAL(4, 43, 11), // "roomUpdated"
QT_MOC_LITERAL(5, 55, 7), // "cacheId"
QT_MOC_LITERAL(6, 63, 4), // "code"
QT_MOC_LITERAL(7, 68, 21), // "on_btnRefresh_clicked"
QT_MOC_LITERAL(8, 90, 26), // "on_btnTrackControl_clicked"
QT_MOC_LITERAL(9, 117, 29), // "on_btnOpenReservation_clicked"
QT_MOC_LITERAL(10, 147, 20), // "on_btnGuests_clicked"
QT_MOC_LITERAL(11, 168, 29), // "on_btnCheckinSelected_clicked"
QT_MOC_LITERAL(12, 198, 32), // "on_btnClearSelectedRooms_clicked"
QT_MOC_LITERAL(13, 231, 22), // "on_btnDateLeft_clicked"
QT_MOC_LITERAL(14, 254, 23), // "on_btnDateRight_clicked"
QT_MOC_LITERAL(15, 278, 24), // "on_btnMassNation_clicked"
QT_MOC_LITERAL(16, 303, 22) // "on_btnRoomRate_clicked"

    },
    "WQuickReservations\0totalScrollValue\0"
    "\0value\0roomUpdated\0cacheId\0code\0"
    "on_btnRefresh_clicked\0on_btnTrackControl_clicked\0"
    "on_btnOpenReservation_clicked\0"
    "on_btnGuests_clicked\0on_btnCheckinSelected_clicked\0"
    "on_btnClearSelectedRooms_clicked\0"
    "on_btnDateLeft_clicked\0on_btnDateRight_clicked\0"
    "on_btnMassNation_clicked\0"
    "on_btnRoomRate_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WQuickReservations[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    2,   77,    2, 0x08 /* Private */,
       7,    0,   82,    2, 0x08 /* Private */,
       8,    0,   83,    2, 0x08 /* Private */,
       9,    0,   84,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,
      13,    0,   88,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,
      15,    0,   90,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WQuickReservations::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WQuickReservations *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->totalScrollValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->roomUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->on_btnRefresh_clicked(); break;
        case 3: _t->on_btnTrackControl_clicked(); break;
        case 4: _t->on_btnOpenReservation_clicked(); break;
        case 5: _t->on_btnGuests_clicked(); break;
        case 6: _t->on_btnCheckinSelected_clicked(); break;
        case 7: _t->on_btnClearSelectedRooms_clicked(); break;
        case 8: _t->on_btnDateLeft_clicked(); break;
        case 9: _t->on_btnDateRight_clicked(); break;
        case 10: _t->on_btnMassNation_clicked(); break;
        case 11: _t->on_btnRoomRate_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WQuickReservations::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseWidget::staticMetaObject>(),
    qt_meta_stringdata_WQuickReservations.data,
    qt_meta_data_WQuickReservations,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WQuickReservations::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WQuickReservations::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WQuickReservations.stringdata0))
        return static_cast<void*>(this);
    return BaseWidget::qt_metacast(_clname);
}

int WQuickReservations::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
