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
    QByteArrayData data[23];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NodeManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NodeManager_t qt_meta_stringdata_NodeManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NodeManager"
QT_MOC_LITERAL(1, 12, 20), // "getArrowListWithNode"
QT_MOC_LITERAL(2, 33, 15), // "QVector<Arrow*>"
QT_MOC_LITERAL(3, 49, 0), // ""
QT_MOC_LITERAL(4, 50, 5), // "nodeA"
QT_MOC_LITERAL(5, 56, 7), // "addItem"
QT_MOC_LITERAL(6, 64, 10), // "removeNode"
QT_MOC_LITERAL(7, 75, 5), // "index"
QT_MOC_LITERAL(8, 81, 13), // "checkExisting"
QT_MOC_LITERAL(9, 95, 1), // "A"
QT_MOC_LITERAL(10, 97, 1), // "B"
QT_MOC_LITERAL(11, 99, 12), // "updateMatrix"
QT_MOC_LITERAL(12, 112, 5), // "NodeA"
QT_MOC_LITERAL(13, 118, 5), // "NodeB"
QT_MOC_LITERAL(14, 124, 6), // "Arrow*"
QT_MOC_LITERAL(15, 131, 7), // "p_arrow"
QT_MOC_LITERAL(16, 139, 8), // "getArrow"
QT_MOC_LITERAL(17, 148, 7), // "newFile"
QT_MOC_LITERAL(18, 156, 8), // "openFile"
QT_MOC_LITERAL(19, 165, 8), // "saveFile"
QT_MOC_LITERAL(20, 174, 10), // "saveAsFile"
QT_MOC_LITERAL(21, 185, 14), // "filePathExists"
QT_MOC_LITERAL(22, 200, 10) // "showMatrix"

    },
    "NodeManager\0getArrowListWithNode\0"
    "QVector<Arrow*>\0\0nodeA\0addItem\0"
    "removeNode\0index\0checkExisting\0A\0B\0"
    "updateMatrix\0NodeA\0NodeB\0Arrow*\0p_arrow\0"
    "getArrow\0newFile\0openFile\0saveFile\0"
    "saveAsFile\0filePathExists\0showMatrix"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NodeManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    3, 0x08 /* Private */,
       5,    0,   77,    3, 0x08 /* Private */,
       6,    1,   78,    3, 0x08 /* Private */,
       8,    2,   81,    3, 0x08 /* Private */,
      11,    3,   86,    3, 0x08 /* Private */,
      16,    2,   93,    3, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      17,    0,   98,    3, 0x02 /* Public */,
      18,    0,   99,    3, 0x02 /* Public */,
      19,    0,  100,    3, 0x02 /* Public */,
      20,    0,  101,    3, 0x02 /* Public */,
      21,    0,  102,    3, 0x02 /* Public */,
      22,    0,  103,    3, 0x02 /* Public */,

 // slots: parameters
    0x80000000 | 2, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 14,   12,   13,   15,
    0x80000000 | 14, QMetaType::Int, QMetaType::Int,   12,   13,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

void NodeManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NodeManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QVector<Arrow*> _r = _t->getArrowListWithNode((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector<Arrow*>*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->addItem(); break;
        case 2: _t->removeNode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { int _r = _t->checkExisting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->updateMatrix((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Arrow*(*)>(_a[3]))); break;
        case 5: { Arrow* _r = _t->getArrow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Arrow**>(_a[0]) = std::move(_r); }  break;
        case 6: _t->newFile(); break;
        case 7: _t->openFile(); break;
        case 8: _t->saveFile(); break;
        case 9: _t->saveAsFile(); break;
        case 10: { bool _r = _t->filePathExists();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->showMatrix(); break;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
