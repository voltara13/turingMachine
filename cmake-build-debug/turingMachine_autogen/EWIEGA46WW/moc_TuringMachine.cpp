/****************************************************************************
** Meta object code from reading C++ file 'TuringMachine.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../TuringMachine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TuringMachine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TuringMachine_t {
    const uint offsetsAndSize[38];
    char stringdata0[288];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TuringMachine_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TuringMachine_t qt_meta_stringdata_TuringMachine = {
    {
QT_MOC_LITERAL(0, 13), // "TuringMachine"
QT_MOC_LITERAL(14, 13), // "endTapeSignal"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 13), // "endWorkSignal"
QT_MOC_LITERAL(43, 25), // "currentIndexChangedSignal"
QT_MOC_LITERAL(69, 5), // "index"
QT_MOC_LITERAL(75, 25), // "currentStateChangedSignal"
QT_MOC_LITERAL(101, 8), // "stateNum"
QT_MOC_LITERAL(110, 17), // "tapeChangedSignal"
QT_MOC_LITERAL(128, 6), // "letter"
QT_MOC_LITERAL(135, 26), // "alphabetStateChangedSignal"
QT_MOC_LITERAL(162, 25), // "matrixStringChangedSignal"
QT_MOC_LITERAL(188, 17), // "AlphabetStateLine"
QT_MOC_LITERAL(206, 11), // "stateString"
QT_MOC_LITERAL(218, 26), // "changeCurrentIndexTapeSlot"
QT_MOC_LITERAL(245, 3), // "row"
QT_MOC_LITERAL(249, 6), // "column"
QT_MOC_LITERAL(256, 22), // "changeCurrentStateSlot"
QT_MOC_LITERAL(279, 8) // "newState"

    },
    "TuringMachine\0endTapeSignal\0\0endWorkSignal\0"
    "currentIndexChangedSignal\0index\0"
    "currentStateChangedSignal\0stateNum\0"
    "tapeChangedSignal\0letter\0"
    "alphabetStateChangedSignal\0"
    "matrixStringChangedSignal\0AlphabetStateLine\0"
    "stateString\0changeCurrentIndexTapeSlot\0"
    "row\0column\0changeCurrentStateSlot\0"
    "newState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TuringMachine[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,
       3,    0,   69,    2, 0x06,    2 /* Public */,
       4,    1,   70,    2, 0x06,    3 /* Public */,
       6,    1,   73,    2, 0x06,    5 /* Public */,
       8,    1,   76,    2, 0x06,    7 /* Public */,
      10,    0,   79,    2, 0x06,    9 /* Public */,
      11,    1,   80,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    2,   83,    2, 0x0a,   12 /* Public */,
      17,    1,   88,    2, 0x0a,   15 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QChar,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void TuringMachine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TuringMachine *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->endTapeSignal(); break;
        case 1: _t->endWorkSignal(); break;
        case 2: _t->currentIndexChangedSignal((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->currentStateChangedSignal((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->tapeChangedSignal((*reinterpret_cast< const QChar(*)>(_a[1]))); break;
        case 5: _t->alphabetStateChangedSignal(); break;
        case 6: _t->matrixStringChangedSignal((*reinterpret_cast< const AlphabetStateLine(*)>(_a[1]))); break;
        case 7: _t->changeCurrentIndexTapeSlot((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 8: _t->changeCurrentStateSlot((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TuringMachine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TuringMachine::endTapeSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TuringMachine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TuringMachine::endWorkSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TuringMachine::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TuringMachine::currentIndexChangedSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TuringMachine::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TuringMachine::currentStateChangedSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TuringMachine::*)(const QChar & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TuringMachine::tapeChangedSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TuringMachine::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TuringMachine::alphabetStateChangedSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TuringMachine::*)(const AlphabetStateLine & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TuringMachine::matrixStringChangedSignal)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject TuringMachine::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TuringMachine.offsetsAndSize,
    qt_meta_data_TuringMachine,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TuringMachine_t
, QtPrivate::TypeAndForceComplete<TuringMachine, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QChar &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const AlphabetStateLine &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>


>,
    nullptr
} };


const QMetaObject *TuringMachine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TuringMachine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TuringMachine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TuringMachine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void TuringMachine::endTapeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TuringMachine::endWorkSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TuringMachine::currentIndexChangedSignal(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TuringMachine::currentStateChangedSignal(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TuringMachine::tapeChangedSignal(const QChar & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TuringMachine::alphabetStateChangedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void TuringMachine::matrixStringChangedSignal(const AlphabetStateLine & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
