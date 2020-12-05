/****************************************************************************
** Meta object code from reading C++ file 'rface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Restaurant/rface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RFace_t {
    QByteArrayData data[21];
    char stringdata0[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RFace_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RFace_t qt_meta_stringdata_RFace = {
    {
QT_MOC_LITERAL(0, 0, 5), // "RFace"
QT_MOC_LITERAL(1, 6, 11), // "updateCache"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 5), // "cache"
QT_MOC_LITERAL(4, 25, 4), // "code"
QT_MOC_LITERAL(5, 30, 7), // "timeout"
QT_MOC_LITERAL(6, 38, 15), // "socketReadyRead"
QT_MOC_LITERAL(7, 54, 18), // "socketDisconnected"
QT_MOC_LITERAL(8, 73, 12), // "parseCommand"
QT_MOC_LITERAL(9, 86, 7), // "command"
QT_MOC_LITERAL(10, 94, 22), // "on_tableWidget_clicked"
QT_MOC_LITERAL(11, 117, 11), // "QModelIndex"
QT_MOC_LITERAL(12, 129, 5), // "index"
QT_MOC_LITERAL(13, 135, 18), // "on_btnExit_clicked"
QT_MOC_LITERAL(14, 154, 20), // "on_tblTables_clicked"
QT_MOC_LITERAL(15, 175, 16), // "on_btnUp_clicked"
QT_MOC_LITERAL(16, 192, 18), // "on_btnDown_clicked"
QT_MOC_LITERAL(17, 211, 24), // "on_btnChangeHall_clicked"
QT_MOC_LITERAL(18, 236, 23), // "on_btnBreakFast_clicked"
QT_MOC_LITERAL(19, 260, 20), // "on_btnBanket_clicked"
QT_MOC_LITERAL(20, 281, 19) // "on_btnTools_clicked"

    },
    "RFace\0updateCache\0\0cache\0code\0timeout\0"
    "socketReadyRead\0socketDisconnected\0"
    "parseCommand\0command\0on_tableWidget_clicked\0"
    "QModelIndex\0index\0on_btnExit_clicked\0"
    "on_tblTables_clicked\0on_btnUp_clicked\0"
    "on_btnDown_clicked\0on_btnChangeHall_clicked\0"
    "on_btnBreakFast_clicked\0on_btnBanket_clicked\0"
    "on_btnTools_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RFace[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   89,    2, 0x08 /* Private */,
       6,    0,   90,    2, 0x08 /* Private */,
       7,    0,   91,    2, 0x08 /* Private */,
       8,    1,   92,    2, 0x08 /* Private */,
      10,    1,   95,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    1,   99,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,
      17,    0,  104,    2, 0x08 /* Private */,
      18,    0,  105,    2, 0x08 /* Private */,
      19,    0,  106,    2, 0x08 /* Private */,
      20,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RFace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RFace *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateCache((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->timeout(); break;
        case 2: _t->socketReadyRead(); break;
        case 3: _t->socketDisconnected(); break;
        case 4: _t->parseCommand((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_tableWidget_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_btnExit_clicked(); break;
        case 7: _t->on_tblTables_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_btnUp_clicked(); break;
        case 9: _t->on_btnDown_clicked(); break;
        case 10: _t->on_btnChangeHall_clicked(); break;
        case 11: _t->on_btnBreakFast_clicked(); break;
        case 12: _t->on_btnBanket_clicked(); break;
        case 13: _t->on_btnTools_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RFace::*)(int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RFace::updateCache)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RFace::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseExtendedDialog::staticMetaObject>(),
    qt_meta_stringdata_RFace.data,
    qt_meta_data_RFace,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RFace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RFace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RFace.stringdata0))
        return static_cast<void*>(this);
    return BaseExtendedDialog::qt_metacast(_clname);
}

int RFace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseExtendedDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void RFace::updateCache(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
