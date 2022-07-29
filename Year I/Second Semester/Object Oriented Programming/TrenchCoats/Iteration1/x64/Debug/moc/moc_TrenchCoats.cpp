/****************************************************************************
** Meta object code from reading C++ file 'TrenchCoats.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../TrenchCoats.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TrenchCoats.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrenchCoats_t {
    const uint offsetsAndSize[32];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TrenchCoats_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TrenchCoats_t qt_meta_stringdata_TrenchCoats = {
    {
QT_MOC_LITERAL(0, 11), // "TrenchCoats"
QT_MOC_LITERAL(12, 13), // "handleDisplay"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 24), // "handleShowInternalBasket"
QT_MOC_LITERAL(52, 15), // "handleStartUser"
QT_MOC_LITERAL(68, 15), // "handleAddTrench"
QT_MOC_LITERAL(84, 18), // "handleDeleteTrench"
QT_MOC_LITERAL(103, 18), // "handleUpdateTrench"
QT_MOC_LITERAL(122, 20), // "handleDisplayDeleted"
QT_MOC_LITERAL(143, 12), // "handleFilter"
QT_MOC_LITERAL(156, 14), // "handleSeeImage"
QT_MOC_LITERAL(171, 17), // "handleAddToBasket"
QT_MOC_LITERAL(189, 16), // "handleShowBasket"
QT_MOC_LITERAL(206, 10), // "handleUndo"
QT_MOC_LITERAL(217, 10), // "handleRedo"
QT_MOC_LITERAL(228, 15) // "handleShowTable"

    },
    "TrenchCoats\0handleDisplay\0\0"
    "handleShowInternalBasket\0handleStartUser\0"
    "handleAddTrench\0handleDeleteTrench\0"
    "handleUpdateTrench\0handleDisplayDeleted\0"
    "handleFilter\0handleSeeImage\0"
    "handleAddToBasket\0handleShowBasket\0"
    "handleUndo\0handleRedo\0handleShowTable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrenchCoats[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    0,  103,    2, 0x08,    6 /* Private */,
       8,    0,  104,    2, 0x08,    7 /* Private */,
       9,    0,  105,    2, 0x08,    8 /* Private */,
      10,    0,  106,    2, 0x08,    9 /* Private */,
      11,    0,  107,    2, 0x08,   10 /* Private */,
      12,    0,  108,    2, 0x08,   11 /* Private */,
      13,    0,  109,    2, 0x08,   12 /* Private */,
      14,    0,  110,    2, 0x08,   13 /* Private */,
      15,    0,  111,    2, 0x08,   14 /* Private */,

 // slots: parameters
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TrenchCoats::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrenchCoats *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handleDisplay(); break;
        case 1: _t->handleShowInternalBasket(); break;
        case 2: _t->handleStartUser(); break;
        case 3: _t->handleAddTrench(); break;
        case 4: _t->handleDeleteTrench(); break;
        case 5: _t->handleUpdateTrench(); break;
        case 6: _t->handleDisplayDeleted(); break;
        case 7: _t->handleFilter(); break;
        case 8: _t->handleSeeImage(); break;
        case 9: _t->handleAddToBasket(); break;
        case 10: _t->handleShowBasket(); break;
        case 11: _t->handleUndo(); break;
        case 12: _t->handleRedo(); break;
        case 13: _t->handleShowTable(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject TrenchCoats::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_TrenchCoats.offsetsAndSize,
    qt_meta_data_TrenchCoats,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TrenchCoats_t
, QtPrivate::TypeAndForceComplete<TrenchCoats, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TrenchCoats::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrenchCoats::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrenchCoats.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TrenchCoats::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
