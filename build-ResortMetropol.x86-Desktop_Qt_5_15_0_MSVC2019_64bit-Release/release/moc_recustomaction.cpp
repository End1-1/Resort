/****************************************************************************
** Meta object code from reading C++ file 'recustomaction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RowEditor/recustomaction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recustomaction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RECustomAction_t {
    QByteArrayData data[6];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RECustomAction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RECustomAction_t qt_meta_stringdata_RECustomAction = {
    {
QT_MOC_LITERAL(0, 0, 14), // "RECustomAction"
QT_MOC_LITERAL(1, 15, 13), // "processValues"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 3), // "out"
QT_MOC_LITERAL(4, 34, 12), // "handleValues"
QT_MOC_LITERAL(5, 47, 7) // "clicked"

    },
    "RECustomAction\0processValues\0\0out\0"
    "handleValues\0clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RECustomAction[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x09 /* Protected */,
       5,    0,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariantList,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariantList,    3,
    QMetaType::Void,

       0        // eod
};

void RECustomAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RECustomAction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processValues((*reinterpret_cast< const QList<QVariant>(*)>(_a[1]))); break;
        case 1: _t->handleValues((*reinterpret_cast< const QList<QVariant>(*)>(_a[1]))); break;
        case 2: _t->clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RECustomAction::*)(const QList<QVariant> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RECustomAction::processValues)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RECustomAction::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseExtendedDialog::staticMetaObject>(),
    qt_meta_stringdata_RECustomAction.data,
    qt_meta_data_RECustomAction,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RECustomAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RECustomAction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RECustomAction.stringdata0))
        return static_cast<void*>(this);
    return BaseExtendedDialog::qt_metacast(_clname);
}

int RECustomAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseExtendedDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void RECustomAction::processValues(const QList<QVariant> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
