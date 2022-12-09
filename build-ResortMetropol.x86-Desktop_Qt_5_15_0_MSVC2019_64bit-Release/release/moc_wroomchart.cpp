/****************************************************************************
** Meta object code from reading C++ file 'wroomchart.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Resort/wroomchart.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wroomchart.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WRoomChart_t {
    QByteArrayData data[15];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WRoomChart_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WRoomChart_t qt_meta_stringdata_WRoomChart = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WRoomChart"
QT_MOC_LITERAL(1, 11, 13), // "createReserve"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "row"
QT_MOC_LITERAL(4, 30, 6), // "column"
QT_MOC_LITERAL(5, 37, 13), // "TempRectItem*"
QT_MOC_LITERAL(6, 51, 1), // "t"
QT_MOC_LITERAL(7, 53, 16), // "catButtonClicked"
QT_MOC_LITERAL(8, 70, 37), // "mainViewVerticalScrollBarValu..."
QT_MOC_LITERAL(9, 108, 5), // "value"
QT_MOC_LITERAL(10, 114, 39), // "mainViewHorizontalScrollBarVa..."
QT_MOC_LITERAL(11, 154, 37), // "roomViewVerticalScrollBarValu..."
QT_MOC_LITERAL(12, 192, 39), // "dateViewHorizontalScrollBarVa..."
QT_MOC_LITERAL(13, 232, 19), // "on_btnReset_clicked"
QT_MOC_LITERAL(14, 252, 28) // "on_btnNewReservation_clicked"

    },
    "WRoomChart\0createReserve\0\0row\0column\0"
    "TempRectItem*\0t\0catButtonClicked\0"
    "mainViewVerticalScrollBarValueChanged\0"
    "value\0mainViewHorizontalScrollBarValueChanged\0"
    "roomViewVerticalScrollBarValueChanged\0"
    "dateViewHorizontalScrollBarValueChanged\0"
    "on_btnReset_clicked\0on_btnNewReservation_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WRoomChart[] = {

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
       1,    3,   54,    2, 0x08 /* Private */,
       7,    0,   61,    2, 0x08 /* Private */,
       8,    1,   62,    2, 0x08 /* Private */,
      10,    1,   65,    2, 0x08 /* Private */,
      11,    1,   68,    2, 0x08 /* Private */,
      12,    1,   71,    2, 0x08 /* Private */,
      13,    0,   74,    2, 0x08 /* Private */,
      14,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 5,    3,    4,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WRoomChart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WRoomChart *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createReserve((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< TempRectItem*(*)>(_a[3]))); break;
        case 1: _t->catButtonClicked(); break;
        case 2: _t->mainViewVerticalScrollBarValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->mainViewHorizontalScrollBarValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->roomViewVerticalScrollBarValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->dateViewHorizontalScrollBarValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_btnReset_clicked(); break;
        case 7: _t->on_btnNewReservation_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WRoomChart::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseWidget::staticMetaObject>(),
    qt_meta_stringdata_WRoomChart.data,
    qt_meta_data_WRoomChart,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WRoomChart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WRoomChart::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WRoomChart.stringdata0))
        return static_cast<void*>(this);
    return BaseWidget::qt_metacast(_clname);
}

int WRoomChart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWidget::qt_metacall(_c, _id, _a);
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
