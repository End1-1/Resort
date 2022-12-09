/****************************************************************************
** Meta object code from reading C++ file 'storedoc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Widgets/storedoc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'storedoc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StoreDoc_t {
    QByteArrayData data[18];
    char stringdata0[307];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StoreDoc_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StoreDoc_t qt_meta_stringdata_StoreDoc = {
    {
QT_MOC_LITERAL(0, 0, 8), // "StoreDoc"
QT_MOC_LITERAL(1, 9, 9), // "qtyChange"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 4), // "arg1"
QT_MOC_LITERAL(4, 25, 11), // "priceChange"
QT_MOC_LITERAL(5, 37, 11), // "totalChange"
QT_MOC_LITERAL(6, 49, 21), // "on_btnSaveDoc_clicked"
QT_MOC_LITERAL(7, 71, 25), // "on_btnNewMaterial_clicked"
QT_MOC_LITERAL(8, 97, 8), // "newGoods"
QT_MOC_LITERAL(9, 106, 4), // "code"
QT_MOC_LITERAL(10, 111, 25), // "on_btnAddMaterial_clicked"
QT_MOC_LITERAL(11, 137, 22), // "on_btnDraftDoc_clicked"
QT_MOC_LITERAL(12, 160, 23), // "on_btnRemoveDoc_clicked"
QT_MOC_LITERAL(13, 184, 28), // "on_btnRemoveMaterial_clicked"
QT_MOC_LITERAL(14, 213, 21), // "on_deDate_textChanged"
QT_MOC_LITERAL(15, 235, 22), // "on_leTotal_textChanged"
QT_MOC_LITERAL(16, 258, 25), // "on_leComments_textChanged"
QT_MOC_LITERAL(17, 284, 22) // "on_btnPrintDoc_clicked"

    },
    "StoreDoc\0qtyChange\0\0arg1\0priceChange\0"
    "totalChange\0on_btnSaveDoc_clicked\0"
    "on_btnNewMaterial_clicked\0newGoods\0"
    "code\0on_btnAddMaterial_clicked\0"
    "on_btnDraftDoc_clicked\0on_btnRemoveDoc_clicked\0"
    "on_btnRemoveMaterial_clicked\0"
    "on_deDate_textChanged\0on_leTotal_textChanged\0"
    "on_leComments_textChanged\0"
    "on_btnPrintDoc_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StoreDoc[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x08 /* Private */,
       4,    1,   87,    2, 0x08 /* Private */,
       5,    1,   90,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    1,   95,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    0,  101,    2, 0x08 /* Private */,
      14,    1,  102,    2, 0x08 /* Private */,
      15,    1,  105,    2, 0x08 /* Private */,
      16,    1,  108,    2, 0x08 /* Private */,
      17,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

       0        // eod
};

void StoreDoc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StoreDoc *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->qtyChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->priceChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->totalChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_btnSaveDoc_clicked(); break;
        case 4: _t->on_btnNewMaterial_clicked(); break;
        case 5: _t->newGoods((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_btnAddMaterial_clicked(); break;
        case 7: _t->on_btnDraftDoc_clicked(); break;
        case 8: _t->on_btnRemoveDoc_clicked(); break;
        case 9: _t->on_btnRemoveMaterial_clicked(); break;
        case 10: _t->on_deDate_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_leTotal_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_leComments_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->on_btnPrintDoc_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject StoreDoc::staticMetaObject = { {
    QMetaObject::SuperData::link<BaseWidget::staticMetaObject>(),
    qt_meta_stringdata_StoreDoc.data,
    qt_meta_data_StoreDoc,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *StoreDoc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StoreDoc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StoreDoc.stringdata0))
        return static_cast<void*>(this);
    return BaseWidget::qt_metacast(_clname);
}

int StoreDoc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
