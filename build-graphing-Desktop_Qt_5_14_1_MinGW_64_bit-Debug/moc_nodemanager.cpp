/****************************************************************************
** Meta object code from reading C++ file 'nodemanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../graphing/nodemanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nodemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NodeManager_t {
    QByteArrayData data[30];
    char stringdata0[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NodeManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NodeManager_t qt_meta_stringdata_NodeManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NodeManager"
QT_MOC_LITERAL(1, 12, 8), // "readFile"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 10), // "mergeNodes"
QT_MOC_LITERAL(4, 33, 5), // "Node*"
QT_MOC_LITERAL(5, 39, 4), // "From"
QT_MOC_LITERAL(6, 44, 2), // "To"
QT_MOC_LITERAL(7, 47, 14), // "updateBindings"
QT_MOC_LITERAL(8, 62, 4), // "int&"
QT_MOC_LITERAL(9, 67, 5), // "nodeA"
QT_MOC_LITERAL(10, 73, 14), // "removeBindings"
QT_MOC_LITERAL(11, 88, 7), // "addItem"
QT_MOC_LITERAL(12, 96, 10), // "removeNode"
QT_MOC_LITERAL(13, 107, 5), // "index"
QT_MOC_LITERAL(14, 113, 13), // "checkExisting"
QT_MOC_LITERAL(15, 127, 1), // "A"
QT_MOC_LITERAL(16, 129, 1), // "B"
QT_MOC_LITERAL(17, 131, 12), // "updateMatrix"
QT_MOC_LITERAL(18, 144, 5), // "NodeA"
QT_MOC_LITERAL(19, 150, 5), // "NodeB"
QT_MOC_LITERAL(20, 156, 6), // "Arrow*"
QT_MOC_LITERAL(21, 163, 7), // "p_arrow"
QT_MOC_LITERAL(22, 171, 8), // "getArrow"
QT_MOC_LITERAL(23, 180, 5), // "clear"
QT_MOC_LITERAL(24, 186, 8), // "openFile"
QT_MOC_LITERAL(25, 195, 8), // "saveFile"
QT_MOC_LITERAL(26, 204, 10), // "saveAsFile"
QT_MOC_LITERAL(27, 215, 10), // "showMatrix"
QT_MOC_LITERAL(28, 226, 11), // "removeArrow"
QT_MOC_LITERAL(29, 238, 7) // "arrowID"

    },
    "NodeManager\0readFile\0\0mergeNodes\0Node*\0"
    "From\0To\0updateBindings\0int&\0nodeA\0"
    "removeBindings\0addItem\0removeNode\0"
    "index\0checkExisting\0A\0B\0updateMatrix\0"
    "NodeA\0NodeB\0Arrow*\0p_arrow\0getArrow\0"
    "clear\0openFile\0saveFile\0saveAsFile\0"
    "showMatrix\0removeArrow\0arrowID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NodeManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    2,   90,    2, 0x08 /* Private */,
       7,    1,   95,    2, 0x08 /* Private */,
      10,    1,   98,    2, 0x08 /* Private */,
      11,    0,  101,    2, 0x08 /* Private */,
      12,    1,  102,    2, 0x08 /* Private */,
      14,    2,  105,    2, 0x08 /* Private */,
      17,    3,  110,    2, 0x08 /* Private */,
      22,    2,  117,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      23,    0,  122,    2, 0x02 /* Public */,
      24,    0,  123,    2, 0x02 /* Public */,
      25,    0,  124,    2, 0x02 /* Public */,
      26,    0,  125,    2, 0x02 /* Public */,
      27,    0,  126,    2, 0x02 /* Public */,
      28,    1,  127,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 20,   18,   19,   21,
    0x80000000 | 20, QMetaType::Int, QMetaType::Int,   18,   19,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   29,

       0        // eod
};

void NodeManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NodeManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readFile(); break;
        case 1: _t->mergeNodes((*reinterpret_cast< Node*(*)>(_a[1])),(*reinterpret_cast< Node*(*)>(_a[2]))); break;
        case 2: _t->updateBindings((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->removeBindings((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->addItem(); break;
        case 5: _t->removeNode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: { int _r = _t->checkExisting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->updateMatrix((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Arrow*(*)>(_a[3]))); break;
        case 8: { Arrow* _r = _t->getArrow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Arrow**>(_a[0]) = std::move(_r); }  break;
        case 9: _t->clear(); break;
        case 10: { bool _r = _t->openFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->saveFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->saveAsFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->showMatrix(); break;
        case 14: _t->removeArrow((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NodeManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NodeManager.data,
    qt_meta_data_NodeManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NodeManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NodeManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NodeManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NodeManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
