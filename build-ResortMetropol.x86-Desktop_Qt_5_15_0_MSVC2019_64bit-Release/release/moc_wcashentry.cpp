/****************************************************************************
** Meta object code from reading C++ file 'wcashentry.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Widgets/wcashentry.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wcashentry.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WCashEntry_t {
    QByteArrayData data[13];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WCashEntry_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WCashEntry_t qt_meta_stringdata_WCashEntry = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WCashEntry"
QT_MOC_LITERAL(1, 11, 8), // "rejected"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "accepted"
QT_MOC_LITERAL(4, 30, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(5, 51, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(6, 70, 24), // "on_chEnable_stateChanged"
QT_MOC_LITERAL(7, 95, 4), // "arg1"
QT_MOC_LITERAL(8, 100, 19), // "on_chEnable_clicked"
QT_MOC_LITERAL(9, 120, 7), // "checked"
QT_MOC_LITERAL(10, 128, 19), // "on_rbCashIn_clicked"
QT_MOC_LITERAL(11, 148, 20), // "on_rbCashOut_clicked"
QT_MOC_LITERAL(12, 169, 21) // "on_rbCashMove_clicked"

    },
    "WCashEntry\0rejected\0\0accepted\0"
    "on_btnCancel_clicked\0on_btnSave_clicked\0"
    "on_chEnable_stateChanged\0arg1\0"
    "on_chEnable_clicked\0checked\0"
    "on_rbCashIn_clicked\0on_rbCashOut_clicked\0"
    "on_rbCashMove_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WCashEntry[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    1,   63,    2, 0x08 /* Private */,
       8,    1,   66,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WCashEntry::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WCashEntry *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rejected(); break;
        case 1: _t->accepted(); break;
        case 2: _t->on_btnCancel_clicked(); break;
        case 3: _t->on_btnSave_clicked(); break;
        case 4: _t->on_chEnable_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_chEnable_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_rbCashIn_clicked(); break;
        case 7: _t->on_rbCashOut_clicked(); break;
        case 8: _t->on_rbCashMove_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WCashEntry::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WCashEntry::rejected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WCashEntry::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WCashEntry::accepted)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WCashEntry::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseWidget::staticMetaObject>(),
    qt_meta_stringdata_WCashEntry.data,
    qt_meta_data_WCashEntry,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WCashEntry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WCashEntry::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WCashEntry.stringdata0))
        return static_cast<void*>(this);
    return BaseWidget::qt_metacast(_clname);
}

int WCashEntry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void WCashEntry::rejected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WCashEntry::accepted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
