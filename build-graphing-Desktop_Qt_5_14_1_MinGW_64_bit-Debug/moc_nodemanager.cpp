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
    QByteArrayData data[27];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NodeManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NodeManager_t qt_meta_stringdata_NodeManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NodeManager"
QT_MOC_LITERAL(1, 12, 10), // "mergeNodes"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "Node*"
QT_MOC_LITERAL(4, 30, 4), // "From"
QT_MOC_LITERAL(5, 35, 2), // "To"
QT_MOC_LITERAL(6, 38, 20), // "getArrowListWithNode"
QT_MOC_LITERAL(7, 59, 15), // "QVector<Arrow*>"
QT_MOC_LITERAL(8, 75, 5), // "nodeA"
QT_MOC_LITERAL(9, 81, 7), // "addItem"
QT_MOC_LITERAL(10, 89, 10), // "removeNode"
QT_MOC_LITERAL(11, 100, 5), // "index"
QT_MOC_LITERAL(12, 106, 13), // "checkExisting"
QT_MOC_LITERAL(13, 120, 1), // "A"
QT_MOC_LITERAL(14, 122, 1), // "B"
QT_MOC_LITERAL(15, 124, 12), // "updateMatrix"
QT_MOC_LITERAL(16, 137, 5), // "NodeA"
QT_MOC_LITERAL(17, 143, 5), // "NodeB"
QT_MOC_LITERAL(18, 149, 6), // "Arrow*"
QT_MOC_LITERAL(19, 156, 7), // "p_arrow"
QT_MOC_LITERAL(20, 164, 8), // "getArrow"
QT_MOC_LITERAL(21, 173, 7), // "newFile"
QT_MOC_LITERAL(22, 181, 8), // "openFile"
QT_MOC_LITERAL(23, 190, 8), // "saveFile"
QT_MOC_LITERAL(24, 199, 10), // "saveAsFile"
QT_MOC_LITERAL(25, 210, 14), // "filePathExists"
QT_MOC_LITERAL(26, 225, 10) // "showMatrix"

    },
    "NodeManager\0mergeNodes\0\0Node*\0From\0"
    "To\0getArrowListWithNode\0QVector<Arrow*>\0"
    "nodeA\0addItem\0removeNode\0index\0"
    "checkExisting\0A\0B\0updateMatrix\0NodeA\0"
    "NodeB\0Arrow*\0p_arrow\0getArrow\0newFile\0"
    "openFile\0saveFile\0saveAsFile\0"
    "filePathExists\0showMatrix"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NodeManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x08 /* Private */,
       6,    1,   84,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    1,   88,    2, 0x08 /* Private */,
      12,    2,   91,    2, 0x08 /* Private */,
      15,    3,   96,    2, 0x08 /* Private */,
      20,    2,  103,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      21,    0,  108,    2, 0x02 /* Public */,
      22,    0,  109,    2, 0x02 /* Public */,
      23,    0,  110,    2, 0x02 /* Public */,
      24,    0,  111,    2, 0x02 /* Public */,
      25,    0,  112,    2, 0x02 /* Public */,
      26,    0,  113,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    0x80000000 | 7, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 18,   16,   17,   19,
    0x80000000 | 18, QMetaType::Int, QMetaType::Int,   16,   17,

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
        case 0: _t->mergeNodes((*reinterpret_cast< Node*(*)>(_a[1])),(*reinterpret_cast< Node*(*)>(_a[2]))); break;
        case 1: { QVector<Arrow*> _r = _t->getArrowListWithNode((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector<Arrow*>*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->addItem(); break;
        case 3: _t->removeNode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: { int _r = _t->checkExisting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->updateMatrix((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Arrow*(*)>(_a[3]))); break;
        case 6: { Arrow* _r = _t->getArrow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Arrow**>(_a[0]) = std::move(_r); }  break;
        case 7: _t->newFile(); break;
        case 8: _t->openFile(); break;
        case 9: _t->saveFile(); break;
        case 10: _t->saveAsFile(); break;
        case 11: { bool _r = _t->filePathExists();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->showMatrix(); break;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
