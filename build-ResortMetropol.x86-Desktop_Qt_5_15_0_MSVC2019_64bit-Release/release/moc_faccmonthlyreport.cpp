/****************************************************************************
** Meta object code from reading C++ file 'faccmonthlyreport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Filter/faccmonthlyreport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'faccmonthlyreport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FAccMonthlyReport_t {
    QByteArrayData data[11];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FAccMonthlyReport_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FAccMonthlyReport_t qt_meta_stringdata_FAccMonthlyReport = {
    {
QT_MOC_LITERAL(0, 0, 17), // "FAccMonthlyReport"
QT_MOC_LITERAL(1, 18, 8), // "dblClick"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 40, 5), // "index"
QT_MOC_LITERAL(5, 46, 22), // "on_deStart_dateChanged"
QT_MOC_LITERAL(6, 69, 4), // "date"
QT_MOC_LITERAL(7, 74, 20), // "on_deEnd_dateChanged"
QT_MOC_LITERAL(8, 95, 29), // "on_cbYear_currentIndexChanged"
QT_MOC_LITERAL(9, 125, 4), // "arg1"
QT_MOC_LITERAL(10, 130, 30) // "on_cbMonth_currentIndexChanged"

    },
    "FAccMonthlyReport\0dblClick\0\0QModelIndex\0"
    "index\0on_deStart_dateChanged\0date\0"
    "on_deEnd_dateChanged\0on_cbYear_currentIndexChanged\0"
    "arg1\0on_cbMonth_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FAccMonthlyReport[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,
       8,    1,   48,    2, 0x08 /* Private */,
      10,    1,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QDate,    6,
    QMetaType::Void, QMetaType::QDate,    6,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void FAccMonthlyReport::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FAccMonthlyReport *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dblClick((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_deStart_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 2: _t->on_deEnd_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 3: _t->on_cbYear_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_cbMonth_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FAccMonthlyReport::staticMetaObject = { {
    QMetaObject::SuperData::link<WFilterBase::staticMetaObject>(),
    qt_meta_stringdata_FAccMonthlyReport.data,
    qt_meta_data_FAccMonthlyReport,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FAccMonthlyReport::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FAccMonthlyReport::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FAccMonthlyReport.stringdata0))
        return static_cast<void*>(this);
    return WFilterBase::qt_metacast(_clname);
}

int FAccMonthlyReport::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WFilterBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
