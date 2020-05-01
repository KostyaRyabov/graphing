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
    QByteArrayData data[34];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NodeManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NodeManager_t qt_meta_stringdata_NodeManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NodeManager"
QT_MOC_LITERAL(1, 12, 5), // "debug"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "text"
QT_MOC_LITERAL(4, 24, 8), // "readFile"
QT_MOC_LITERAL(5, 33, 10), // "mergeNodes"
QT_MOC_LITERAL(6, 44, 5), // "Node*"
QT_MOC_LITERAL(7, 50, 4), // "From"
QT_MOC_LITERAL(8, 55, 2), // "To"
QT_MOC_LITERAL(9, 58, 14), // "updateBindings"
QT_MOC_LITERAL(10, 73, 4), // "int&"
QT_MOC_LITERAL(11, 78, 5), // "nodeA"
QT_MOC_LITERAL(12, 84, 14), // "removeBindings"
QT_MOC_LITERAL(13, 99, 7), // "addItem"
QT_MOC_LITERAL(14, 107, 10), // "removeNode"
QT_MOC_LITERAL(15, 118, 5), // "index"
QT_MOC_LITERAL(16, 124, 13), // "checkExisting"
QT_MOC_LITERAL(17, 138, 1), // "A"
QT_MOC_LITERAL(18, 140, 1), // "B"
QT_MOC_LITERAL(19, 142, 12), // "updateMatrix"
QT_MOC_LITERAL(20, 155, 5), // "NodeA"
QT_MOC_LITERAL(21, 161, 5), // "NodeB"
QT_MOC_LITERAL(22, 167, 6), // "Arrow*"
QT_MOC_LITERAL(23, 174, 7), // "p_arrow"
QT_MOC_LITERAL(24, 182, 8), // "getArrow"
QT_MOC_LITERAL(25, 191, 17), // "checkLoopExisting"
QT_MOC_LITERAL(26, 209, 6), // "nodeID"
QT_MOC_LITERAL(27, 216, 5), // "clear"
QT_MOC_LITERAL(28, 222, 8), // "openFile"
QT_MOC_LITERAL(29, 231, 8), // "saveFile"
QT_MOC_LITERAL(30, 240, 10), // "saveAsFile"
QT_MOC_LITERAL(31, 251, 10), // "showMatrix"
QT_MOC_LITERAL(32, 262, 11), // "removeArrow"
QT_MOC_LITERAL(33, 274, 7) // "arrowID"

    },
    "NodeManager\0debug\0\0text\0readFile\0"
    "mergeNodes\0Node*\0From\0To\0updateBindings\0"
    "int&\0nodeA\0removeBindings\0addItem\0"
    "removeNode\0index\0checkExisting\0A\0B\0"
    "updateMatrix\0NodeA\0NodeB\0Arrow*\0p_arrow\0"
    "getArrow\0checkLoopExisting\0nodeID\0"
    "clear\0openFile\0saveFile\0saveAsFile\0"
    "showMatrix\0removeArrow\0arrowID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NodeManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  102,    2, 0x08 /* Private */,
       5,    2,  103,    2, 0x08 /* Private */,
       9,    1,  108,    2, 0x08 /* Private */,
      12,    1,  111,    2, 0x08 /* Private */,
      13,    0,  114,    2, 0x08 /* Private */,
      14,    1,  115,    2, 0x08 /* Private */,
      16,    2,  118,    2, 0x08 /* Private */,
      19,    3,  123,    2, 0x08 /* Private */,
      24,    2,  130,    2, 0x08 /* Private */,
      25,    1,  135,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      27,    0,  138,    2, 0x02 /* Public */,
      28,    0,  139,    2, 0x02 /* Public */,
      29,    0,  140,    2, 0x02 /* Public */,
      30,    0,  141,    2, 0x02 /* Public */,
      31,    0,  142,    2, 0x02 /* Public */,
      32,    1,  143,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 22,   20,   21,   23,
    0x80000000 | 22, QMetaType::Int, QMetaType::Int,   20,   21,
    QMetaType::Bool, QMetaType::Int,   26,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   33,

       0        // eod
};

void NodeManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NodeManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->debug((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->readFile(); break;
        case 2: _t->mergeNodes((*reinterpret_cast< Node*(*)>(_a[1])),(*reinterpret_cast< Node*(*)>(_a[2]))); break;
        case 3: _t->updateBindings((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->removeBindings((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->addItem(); break;
        case 6: _t->removeNode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: { int _r = _t->checkExisting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->updateMatrix((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Arrow*(*)>(_a[3]))); break;
        case 9: { Arrow* _r = _t->getArrow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Arrow**>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->checkLoopExisting((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->clear(); break;
        case 12: { bool _r = _t->openFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->saveFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->saveAsFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->showMatrix(); break;
        case 16: _t->removeArrow((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NodeManager::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NodeManager::debug)) {
                *result = 0;
                return;
            }
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void NodeManager::debug(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
