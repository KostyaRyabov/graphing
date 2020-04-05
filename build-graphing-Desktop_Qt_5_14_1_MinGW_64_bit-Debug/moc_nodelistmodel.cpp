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
    QByteArrayData data[18];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nodeListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nodeListModel_t qt_meta_stringdata_nodeListModel = {
    {
QT_MOC_LITERAL(0, 0, 13), // "nodeListModel"
QT_MOC_LITERAL(1, 14, 7), // "updated"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "Node*"
QT_MOC_LITERAL(4, 29, 4), // "node"
QT_MOC_LITERAL(5, 34, 7), // "addItem"
QT_MOC_LITERAL(6, 42, 10), // "removeItem"
QT_MOC_LITERAL(7, 53, 5), // "index"
QT_MOC_LITERAL(8, 59, 7), // "getNode"
QT_MOC_LITERAL(9, 67, 7), // "addNode"
QT_MOC_LITERAL(10, 75, 1), // "x"
QT_MOC_LITERAL(11, 77, 1), // "y"
QT_MOC_LITERAL(12, 79, 6), // "update"
QT_MOC_LITERAL(13, 86, 1), // "i"
QT_MOC_LITERAL(14, 88, 5), // "value"
QT_MOC_LITERAL(15, 94, 4), // "role"
QT_MOC_LITERAL(16, 99, 10), // "removeNode"
QT_MOC_LITERAL(17, 110, 12) // "showNodeList"

    },
    "nodeListModel\0updated\0\0Node*\0node\0"
    "addItem\0removeItem\0index\0getNode\0"
    "addNode\0x\0y\0update\0i\0value\0role\0"
    "removeNode\0showNodeList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nodeListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   61,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       9,    2,   64,    2, 0x02 /* Public */,
      12,    3,   69,    2, 0x02 /* Public */,
      16,    1,   76,    2, 0x02 /* Public */,
      17,    0,   79,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    0x80000000 | 3, QMetaType::Int,    7,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   13,   14,   15,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

void nodeListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<nodeListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updated((*reinterpret_cast< Node*(*)>(_a[1]))); break;
        case 1: _t->addItem(); break;
        case 2: _t->removeItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { Node* _r = _t->getNode((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Node**>(_a[0]) = std::move(_r); }  break;
        case 4: _t->addNode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->update((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->removeNode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->showNodeList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (nodeListModel::*)(Node * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nodeListModel::updated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (nodeListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nodeListModel::addItem)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (nodeListModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&nodeListModel::removeItem)) {
                *result = 2;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void nodeListModel::updated(Node * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void nodeListModel::addItem()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void nodeListModel::removeItem(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
