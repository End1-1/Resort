/****************************************************************************
** Meta object code from reading C++ file 'fcardexsales.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Filter/fcardexsales.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fcardexsales.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FCardexSales_t {
    QByteArrayData data[10];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FCardexSales_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FCardexSales_t qt_meta_stringdata_FCardexSales = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FCardexSales"
QT_MOC_LITERAL(1, 13, 11), // "openInvoice"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 21), // "on_toolButton_clicked"
QT_MOC_LITERAL(4, 48, 23), // "on_toolButton_2_clicked"
QT_MOC_LITERAL(5, 72, 18), // "on_btnHelp_clicked"
QT_MOC_LITERAL(6, 91, 35), // "on_cbReportType_currentIndexC..."
QT_MOC_LITERAL(7, 127, 5), // "index"
QT_MOC_LITERAL(8, 133, 18), // "on_chNoVat_clicked"
QT_MOC_LITERAL(9, 152, 20) // "on_chCheckin_clicked"

    },
    "FCardexSales\0openInvoice\0\0"
    "on_toolButton_clicked\0on_toolButton_2_clicked\0"
    "on_btnHelp_clicked\0"
    "on_cbReportType_currentIndexChanged\0"
    "index\0on_chNoVat_clicked\0on_chCheckin_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FCardexSales[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FCardexSales::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FCardexSales *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openInvoice(); break;
        case 1: _t->on_toolButton_clicked(); break;
        case 2: _t->on_toolButton_2_clicked(); break;
        case 3: _t->on_btnHelp_clicked(); break;
        case 4: _t->on_cbReportType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_chNoVat_clicked(); break;
        case 6: _t->on_chCheckin_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FCardexSales::staticMetaObject = { {
    QMetaObject::SuperData::link<WFilterBase::staticMetaObject>(),
    qt_meta_stringdata_FCardexSales.data,
    qt_meta_data_FCardexSales,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FCardexSales::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FCardexSales::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FCardexSales.stringdata0))
        return static_cast<void*>(this);
    return WFilterBase::qt_metacast(_clname);
}

int FCardexSales::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WFilterBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
