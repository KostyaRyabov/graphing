/****************************************************************************
** Meta object code from reading C++ file 'nodelistmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../graphing/nodelistmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nodelistmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_nodeListModel_t {
    QByteArrayData data[42];
    char stringdata0[350];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nodeListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nodeListModel_t qt_meta_stringdata_nodeListModel = {
    {
QT_MOC_LITERAL(0, 0, 13), // "nodeListModel"
QT_MOC_LITERAL(1, 14, 10), // "mergeNodes"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "Node*"
QT_MOC_LITERAL(4, 32, 4), // "From"
QT_MOC_LITERAL(5, 37, 2), // "To"
QT_MOC_LITERAL(6, 40, 14), // "removeBindings"
QT_MOC_LITERAL(7, 55, 4), // "int&"
QT_MOC_LITERAL(8, 60, 5), // "nodeA"
QT_MOC_LITERAL(9, 66, 14), // "updateBindings"
QT_MOC_LITERAL(10, 81, 7), // "addItem"
QT_MOC_LITERAL(11, 89, 10), // "removeItem"
QT_MOC_LITERAL(12, 100, 5), // "index"
QT_MOC_LITERAL(13, 106, 17), // "removeArrowsWidth"
QT_MOC_LITERAL(14, 124, 14), // "QVector<Node*>"
QT_MOC_LITERAL(15, 139, 4), // "list"
QT_MOC_LITERAL(16, 144, 6), // "update"
QT_MOC_LITERAL(17, 151, 1), // "i"
QT_MOC_LITERAL(18, 153, 5), // "value"
QT_MOC_LITERAL(19, 159, 4), // "role"
QT_MOC_LITERAL(20, 164, 5), // "multi"
QT_MOC_LITERAL(21, 170, 7), // "getNode"
QT_MOC_LITERAL(22, 178, 12), // "checkExisted"
QT_MOC_LITERAL(23, 191, 7), // "addNode"
QT_MOC_LITERAL(24, 199, 1), // "x"
QT_MOC_LITERAL(25, 201, 1), // "y"
QT_MOC_LITERAL(26, 203, 10), // "removeNode"
QT_MOC_LITERAL(27, 214, 9), // "relations"
QT_MOC_LITERAL(28, 224, 6), // "remove"
QT_MOC_LITERAL(29, 231, 18), // "checkNodeCollision"
QT_MOC_LITERAL(30, 250, 10), // "selectNode"
QT_MOC_LITERAL(31, 261, 6), // "nodeID"
QT_MOC_LITERAL(32, 268, 6), // "append"
QT_MOC_LITERAL(33, 275, 12), // "showNodeList"
QT_MOC_LITERAL(34, 288, 17), // "selectNodesOnRect"
QT_MOC_LITERAL(35, 306, 4), // "left"
QT_MOC_LITERAL(36, 311, 3), // "top"
QT_MOC_LITERAL(37, 315, 5), // "right"
QT_MOC_LITERAL(38, 321, 6), // "bottom"
QT_MOC_LITERAL(39, 328, 7), // "offsetX"
QT_MOC_LITERAL(40, 336, 7), // "offsetY"
QT_MOC_LITERAL(41, 344, 5) // "scale"

    },
    "nodeListModel\0mergeNodes\0\0Node*\0From\0"
    "To\0removeBindings\0int&\0nodeA\0"
    "updateBindings\0addItem\0removeItem\0"
    "index\0removeArrowsWidth\0QVector<Node*>\0"
    "list\0update\0i\0value\0role\0multi\0getNode\0"
    "checkExisted\0addNode\0x\0y\0removeNode\0"
    "relations\0remove\0checkNodeCollision\0"
    "selectNode\0nodeID\0append\0showNodeList\0"
    "selectNodesOnRect\0left\0top\0right\0"
    "bottom\0offsetX\0offsetY\0scale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nodeListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   94,    2, 0x06 /* Public */,
       6,    1,   99,    2, 0x06 /* Public */,
       9,    1,  102,    2, 0x06 /* Public */,
      10,    0,  105,    2, 0x06 /* Public */,
      11,    1,  106,    2, 0x06 /* Public */,
      13,    1,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    4,  112,    2, 0x0a /* Public */,
      16,    3,  121,    2, 0x2a /* Public | MethodCloned */,
      21,    2,  128,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      23,    2,  133,    2, 0x02 /* Public */,
      26,    2,  138,    2, 0x02 /* Public */,
      28,    0,  143,    2, 0x02 /* Public */,
      29,    0,  144,    2, 0x02 /* Public */,
      30,    2,  145,    2, 0x02 /* Public */,
      33,    0,  150,    2, 0x02 /* Public */,
      34,    7,  151,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, 0x80000000 | 14,   15,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   17,   18,   19,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   17,   18,   19,
    0x80000000 | 3, QMetaType::Int, QMetaType::Bool,   12,   22,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   24,   25,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   17,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   31,   32,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Float,   35,   36,   37,   38,   39,   40,   41,

       0        // eod
};

void nodeListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<nodeListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mergeNodes((*reinterpret_cast< Node*(*)>(_a[1])),(*reinterpret_cast< Node*(*)>(_a[2]))); break;
        case 1: _t->removeBindings((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updateBindings((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->addItem(); break;
        case 4: _t->removeItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->removeArrowsWidth((*reinterpret_cast< QVector<Node*>(*)>(_a[1]))); break;
        case 6: _t->update((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 7: _t->update((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: { Node* _r = _t->getNode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Node**>(_a[0]) = std::move(_r); }  break;
        case 9: _t->addNode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->removeNode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 11: _t->remove(); break;
        case 12: _t->checkNodeCollision(); break;
        case 13: _t->selectNode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 14: _t->showNodeList(); break;
        case 15: _t->selectNodesOnRect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< float(*)>(_a[7]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (nodeListModel::*)(Node * , Node * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nodeListModel::mergeNodes)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (nodeListModel::*)(int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nodeListModel::removeBindings)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (nodeListModel::*)(int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nodeListModel::updateBindings)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (nodeListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nodeListModel::addItem)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (nodeListModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nodeListModel::removeItem)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (nodeListModel::*)(QVector<Node*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nodeListModel::removeArrowsWidth)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject nodeListModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_nodeListModel.data,
    qt_meta_data_nodeListModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *nodeListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nodeListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_nodeListModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int nodeListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void nodeListModel::mergeNodes(Node * _t1, Node * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void nodeListModel::removeBindings(int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void nodeListModel::updateBindings(int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void nodeListModel::addItem()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void nodeListModel::removeItem(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void nodeListModel::removeArrowsWidth(QVector<Node*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
