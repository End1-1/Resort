/****************************************************************************
** Meta object code from reading C++ file 'recarclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RowEditor/recarclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recarclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RECarClient_t {
    QByteArrayData data[6];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RECarClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RECarClient_t qt_meta_stringdata_RECarClient = {
    {
QT_MOC_LITERAL(0, 0, 11), // "RECarClient"
QT_MOC_LITERAL(1, 12, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 20), // "on_btnReject_clicked"
QT_MOC_LITERAL(4, 53, 16), // "doubleClickOnRow"
QT_MOC_LITERAL(5, 70, 1) // "v"

    },
    "RECarClient\0on_btnSave_clicked\0\0"
    "on_btnReject_clicked\0doubleClickOnRow\0"
    "v"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RECarClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    1,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantList,    5,

       0        // eod
};

void RECarClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RECarClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnSave_clicked(); break;
        case 1: _t->on_btnReject_clicked(); break;
        case 2: _t->doubleClickOnRow((*reinterpret_cast< const QList<QVariant>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RECarClient::staticMetaObject = { {
    QMetaObject::SuperData::link<RowEditorDialog::staticMetaObject>(),
    qt_meta_stringdata_RECarClient.data,
    qt_meta_data_RECarClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RECarClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RECarClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RECarClient.stringdata0))
        return static_cast<void*>(this);
    return RowEditorDialog::qt_metacast(_clname);
}

int RECarClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RowEditorDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
