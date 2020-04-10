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
    QByteArrayData data[22];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nodeListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nodeListModel_t qt_meta_stringdata_nodeListModel = {
    {
QT_MOC_LITERAL(0, 0, 13), // "nodeListModel"
QT_MOC_LITERAL(1, 14, 14), // "removeBindings"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "Node*"
QT_MOC_LITERAL(4, 36, 4), // "node"
QT_MOC_LITERAL(5, 41, 7), // "updated"
QT_MOC_LITERAL(6, 49, 7), // "addItem"
QT_MOC_LITERAL(7, 57, 10), // "removeItem"
QT_MOC_LITERAL(8, 68, 5), // "index"
QT_MOC_LITERAL(9, 74, 17), // "removeArrowsWidth"
QT_MOC_LITERAL(10, 92, 14), // "QVector<Node*>"
QT_MOC_LITERAL(11, 107, 4), // "list"
QT_MOC_LITERAL(12, 112, 7), // "getNode"
QT_MOC_LITERAL(13, 120, 12), // "checkExisted"
QT_MOC_LITERAL(14, 133, 7), // "addNode"
QT_MOC_LITERAL(15, 141, 1), // "x"
QT_MOC_LITERAL(16, 143, 1), // "y"
QT_MOC_LITERAL(17, 145, 6), // "update"
QT_MOC_LITERAL(18, 152, 1), // "i"
QT_MOC_LITERAL(19, 154, 5), // "value"
QT_MOC_LITERAL(20, 160, 4), // "role"
QT_MOC_LITERAL(21, 165, 10) // "removeNode"

    },
    "nodeListModel\0removeBindings\0\0Node*\0"
    "node\0updated\0addItem\0removeItem\0index\0"
    "removeArrowsWidth\0QVector<Node*>\0list\0"
    "getNode\0checkExisted\0addNode\0x\0y\0"
    "update\0i\0value\0role\0removeNode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nodeListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       6,    0,   65,    2, 0x06 /* Public */,
       7,    1,   66,    2, 0x06 /* Public */,
       9,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    2,   72,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      14,    2,   77,    2, 0x02 /* Public */,
      17,    3,   82,    2, 0x02 /* Public */,
      21,    1,   89,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 10,   11,

 // slots: parameters
    0x80000000 | 3, QMetaType::Int, QMetaType::Bool,    8,   13,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   18,   19,   20,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void nodeListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<nodeListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->removeBindings((*reinterpret_cast< Node*(*)>(_a[1]))); break;
        case 1: _t->updated((*reinterpret_cast< Node*(*)>(_a[1]))); break;
        case 2: _t->addItem(); break;
        case 3: _t->removeItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->removeArrowsWidth((*reinterpret_cast< QVector<Node*>(*)>(_a[1]))); break;
        case 5: { Node* _r = _t->getNode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Node**>(_a[0]) = std::move(_r); }  break;
        case 6: _t->addNode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->update((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->removeNode((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (nodeListModel::*)(Node * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nodeListModel::removeBindings)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (nodeListModel::*)(Node * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nodeListModel::updated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (nodeListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nodeListModel::addItem)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (nodeListModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nodeListModel::removeItem)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (nodeListModel::*)(QVector<Node*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nodeListModel::removeArrowsWidth)) {
                *result = 4;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void nodeListModel::removeBindings(Node * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void nodeListModel::updated(Node * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void nodeListModel::addItem()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void nodeListModel::removeItem(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void nodeListModel::removeArrowsWidth(QVector<Node*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
