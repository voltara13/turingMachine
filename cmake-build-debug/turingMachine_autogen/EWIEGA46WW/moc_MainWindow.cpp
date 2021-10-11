/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MainWindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[50];
    char stringdata0[416];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 18), // "changeTapeItemSlot"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 6), // "letter"
QT_MOC_LITERAL(38, 28), // "changeAlphabetStateCountSlot"
QT_MOC_LITERAL(67, 27), // "changeAlphabetStateItemSlot"
QT_MOC_LITERAL(95, 17), // "AlphabetStateLine"
QT_MOC_LITERAL(113, 17), // "alphabetStateLine"
QT_MOC_LITERAL(131, 26), // "changeCurrentIndexTapeSlot"
QT_MOC_LITERAL(158, 5), // "index"
QT_MOC_LITERAL(164, 22), // "changeCurrentStateSlot"
QT_MOC_LITERAL(187, 8), // "newState"
QT_MOC_LITERAL(196, 21), // "changeGUIModelingSlot"
QT_MOC_LITERAL(218, 7), // "isStart"
QT_MOC_LITERAL(226, 20), // "clickButtonStartSlot"
QT_MOC_LITERAL(247, 19), // "clickButtonStepSlot"
QT_MOC_LITERAL(267, 19), // "clickButtonStopSlot"
QT_MOC_LITERAL(287, 31), // "clickButtonChangeCountStateSlot"
QT_MOC_LITERAL(319, 5), // "isAdd"
QT_MOC_LITERAL(325, 19), // "doubleClickTapeSlot"
QT_MOC_LITERAL(345, 28), // "doubleClickAlphabetStateSlot"
QT_MOC_LITERAL(374, 11), // "endTapeSlot"
QT_MOC_LITERAL(386, 11), // "endWorkSlot"
QT_MOC_LITERAL(398, 8), // "helpSlot"
QT_MOC_LITERAL(407, 8) // "exitSlot"

    },
    "MainWindow\0changeTapeItemSlot\0\0letter\0"
    "changeAlphabetStateCountSlot\0"
    "changeAlphabetStateItemSlot\0"
    "AlphabetStateLine\0alphabetStateLine\0"
    "changeCurrentIndexTapeSlot\0index\0"
    "changeCurrentStateSlot\0newState\0"
    "changeGUIModelingSlot\0isStart\0"
    "clickButtonStartSlot\0clickButtonStepSlot\0"
    "clickButtonStopSlot\0clickButtonChangeCountStateSlot\0"
    "isAdd\0doubleClickTapeSlot\0"
    "doubleClickAlphabetStateSlot\0endTapeSlot\0"
    "endWorkSlot\0helpSlot\0exitSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  110,    2, 0x08,    1 /* Private */,
       4,    0,  113,    2, 0x08,    3 /* Private */,
       5,    1,  114,    2, 0x08,    4 /* Private */,
       8,    1,  117,    2, 0x08,    6 /* Private */,
      10,    1,  120,    2, 0x08,    8 /* Private */,
      12,    1,  123,    2, 0x08,   10 /* Private */,
      14,    0,  126,    2, 0x08,   12 /* Private */,
      15,    0,  127,    2, 0x08,   13 /* Private */,
      16,    0,  128,    2, 0x08,   14 /* Private */,
      17,    1,  129,    2, 0x08,   15 /* Private */,
      19,    0,  132,    2, 0x08,   17 /* Private */,
      20,    0,  133,    2, 0x08,   18 /* Private */,
      21,    0,  134,    2, 0x08,   19 /* Private */,
      22,    0,  135,    2, 0x08,   20 /* Private */,
      23,    0,  136,    2, 0x08,   21 /* Private */,
      24,    0,  137,    2, 0x08,   22 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QChar,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->changeTapeItemSlot((*reinterpret_cast< const QChar(*)>(_a[1]))); break;
        case 1: _t->changeAlphabetStateCountSlot(); break;
        case 2: _t->changeAlphabetStateItemSlot((*reinterpret_cast< const AlphabetStateLine(*)>(_a[1]))); break;
        case 3: _t->changeCurrentIndexTapeSlot((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->changeCurrentStateSlot((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 5: _t->changeGUIModelingSlot((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 6: _t->clickButtonStartSlot(); break;
        case 7: _t->clickButtonStepSlot(); break;
        case 8: _t->clickButtonStopSlot(); break;
        case 9: _t->clickButtonChangeCountStateSlot((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 10: _t->doubleClickTapeSlot(); break;
        case 11: _t->doubleClickAlphabetStateSlot(); break;
        case 12: _t->endTapeSlot(); break;
        case 13: _t->endWorkSlot(); break;
        case 14: _t->helpSlot(); break;
        case 15: _t->exitSlot(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QChar &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const AlphabetStateLine &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const bool &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const bool &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
