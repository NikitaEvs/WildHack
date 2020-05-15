/****************************************************************************
** Meta object code from reading C++ file 'Gui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Interface/Gui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Gui_t {
    QByteArrayData data[27];
    char stringdata0[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Gui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Gui_t qt_meta_stringdata_Gui = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Gui"
QT_MOC_LITERAL(1, 4, 10), // "mapChanged"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 18), // "populationsChanged"
QT_MOC_LITERAL(4, 35, 24), // "currentPopulationChanged"
QT_MOC_LITERAL(5, 60, 18), // "currentCellChanged"
QT_MOC_LITERAL(6, 79, 8), // "xChanged"
QT_MOC_LITERAL(7, 88, 8), // "yChanged"
QT_MOC_LITERAL(8, 97, 9), // "idChanged"
QT_MOC_LITERAL(9, 107, 13), // "requestUpdate"
QT_MOC_LITERAL(10, 121, 7), // "endGame"
QT_MOC_LITERAL(11, 129, 6), // "select"
QT_MOC_LITERAL(12, 136, 7), // "migrate"
QT_MOC_LITERAL(13, 144, 8), // "multiply"
QT_MOC_LITERAL(14, 153, 6), // "mutate"
QT_MOC_LITERAL(15, 160, 4), // "type"
QT_MOC_LITERAL(16, 165, 4), // "stop"
QT_MOC_LITERAL(17, 170, 15), // "checkPopulation"
QT_MOC_LITERAL(18, 186, 4), // "posX"
QT_MOC_LITERAL(19, 191, 4), // "posY"
QT_MOC_LITERAL(20, 196, 3), // "map"
QT_MOC_LITERAL(21, 200, 11), // "populations"
QT_MOC_LITERAL(22, 212, 17), // "currentPopulation"
QT_MOC_LITERAL(23, 230, 11), // "currentCell"
QT_MOC_LITERAL(24, 242, 1), // "x"
QT_MOC_LITERAL(25, 244, 1), // "y"
QT_MOC_LITERAL(26, 246, 2) // "id"

    },
    "Gui\0mapChanged\0\0populationsChanged\0"
    "currentPopulationChanged\0currentCellChanged\0"
    "xChanged\0yChanged\0idChanged\0requestUpdate\0"
    "endGame\0select\0migrate\0multiply\0mutate\0"
    "type\0stop\0checkPopulation\0posX\0posY\0"
    "map\0populations\0currentPopulation\0"
    "currentCell\0x\0y\0id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Gui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       7,  110, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,
       7,    0,   94,    2, 0x06 /* Public */,
       8,    0,   95,    2, 0x06 /* Public */,
       9,    0,   96,    2, 0x06 /* Public */,
      10,    0,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   98,    2, 0x0a /* Public */,
      12,    0,   99,    2, 0x0a /* Public */,
      13,    0,  100,    2, 0x0a /* Public */,
      14,    1,  101,    2, 0x0a /* Public */,
      16,    0,  104,    2, 0x0a /* Public */,
      17,    2,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Int, QMetaType::Int,   18,   19,

 // properties: name, type, flags
      20, QMetaType::QVariantList, 0x00495103,
      21, QMetaType::QVariantList, 0x00495103,
      22, QMetaType::QVariantList, 0x00495103,
      23, QMetaType::QVariantList, 0x00495103,
      24, QMetaType::QVariant, 0x00495103,
      25, QMetaType::QVariant, 0x00495103,
      26, QMetaType::QVariant, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,

       0        // eod
};

void Gui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Gui *_t = static_cast<Gui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mapChanged(); break;
        case 1: _t->populationsChanged(); break;
        case 2: _t->currentPopulationChanged(); break;
        case 3: _t->currentCellChanged(); break;
        case 4: _t->xChanged(); break;
        case 5: _t->yChanged(); break;
        case 6: _t->idChanged(); break;
        case 7: _t->requestUpdate(); break;
        case 8: _t->endGame(); break;
        case 9: _t->select(); break;
        case 10: _t->migrate(); break;
        case 11: _t->multiply(); break;
        case 12: _t->mutate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->stop(); break;
        case 14: { bool _r = _t->checkPopulation((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Gui::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::mapChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Gui::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::populationsChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Gui::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::currentPopulationChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Gui::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::currentCellChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Gui::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::xChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Gui::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::yChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Gui::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::idChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Gui::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::requestUpdate)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Gui::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gui::endGame)) {
                *result = 8;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Gui *_t = static_cast<Gui *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariantList*>(_v) = _t->getMap(); break;
        case 1: *reinterpret_cast< QVariantList*>(_v) = _t->getPopulations(); break;
        case 2: *reinterpret_cast< QVariantList*>(_v) = _t->getCurrentPopulation(); break;
        case 3: *reinterpret_cast< QVariantList*>(_v) = _t->getCurrentCell(); break;
        case 4: *reinterpret_cast< QVariant*>(_v) = _t->getX(); break;
        case 5: *reinterpret_cast< QVariant*>(_v) = _t->getY(); break;
        case 6: *reinterpret_cast< QVariant*>(_v) = _t->getID(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Gui *_t = static_cast<Gui *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMap(*reinterpret_cast< QVariantList*>(_v)); break;
        case 1: _t->setPopulations(*reinterpret_cast< QVariantList*>(_v)); break;
        case 2: _t->setCurrentPopulation(*reinterpret_cast< QVariantList*>(_v)); break;
        case 3: _t->setCurrentCell(*reinterpret_cast< QVariantList*>(_v)); break;
        case 4: _t->setX(*reinterpret_cast< QVariant*>(_v)); break;
        case 5: _t->setY(*reinterpret_cast< QVariant*>(_v)); break;
        case 6: _t->setID(*reinterpret_cast< QVariant*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Gui::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Gui.data,
      qt_meta_data_Gui,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Gui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gui::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Gui.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Subscriber"))
        return static_cast< Subscriber*>(this);
    return QObject::qt_metacast(_clname);
}

int Gui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Gui::mapChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Gui::populationsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Gui::currentPopulationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Gui::currentCellChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Gui::xChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Gui::yChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Gui::idChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Gui::requestUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Gui::endGame()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
