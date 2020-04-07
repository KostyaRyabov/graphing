/****************************************************************************
** Meta object code from reading C++ file 'arrowlistmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../graphing/arrowlistmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'arrowlistmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_arrowListModel_t {
    QByteArrayData data[27];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_arrowListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_arrowListModel_t qt_meta_stringdata_arrowListModel = {
    {
QT_MOC_LITERAL(0, 0, 14), // "arrowListModel"
QT_MOC_LITERAL(1, 15, 7), // "getNode"
QT_MOC_LITERAL(2, 23, 5), // "Node*"
QT_MOC_LITERAL(3, 29, 0), // ""
QT_MOC_LITERAL(4, 30, 5), // "index"
QT_MOC_LITERAL(5, 36, 12), // "checkExisted"
QT_MOC_LITERAL(6, 49, 13), // "checkExisting"
QT_MOC_LITERAL(7, 63, 1), // "A"
QT_MOC_LITERAL(8, 65, 1), // "B"
QT_MOC_LITERAL(9, 67, 12), // "updateMatrix"
QT_MOC_LITERAL(10, 80, 5), // "NodeA"
QT_MOC_LITERAL(11, 86, 5), // "NodeB"
QT_MOC_LITERAL(12, 92, 6), // "Arrow*"
QT_MOC_LITERAL(13, 99, 7), // "p_arrow"
QT_MOC_LITERAL(14, 107, 8), // "getArrow"
QT_MOC_LITERAL(15, 116, 14), // "removeBindings"
QT_MOC_LITERAL(16, 131, 4), // "node"
QT_MOC_LITERAL(17, 136, 7), // "updated"
QT_MOC_LITERAL(18, 144, 5), // "bindA"
QT_MOC_LITERAL(19, 150, 9), // "nodeIndex"
QT_MOC_LITERAL(20, 160, 5), // "bindB"
QT_MOC_LITERAL(21, 166, 6), // "remove"
QT_MOC_LITERAL(22, 173, 5), // "arrow"
QT_MOC_LITERAL(23, 179, 13), // "removeCurrent"
QT_MOC_LITERAL(24, 193, 7), // "showMap"
QT_MOC_LITERAL(25, 201, 13), // "showArrowList"
QT_MOC_LITERAL(26, 215, 4) // "kill"

    },
    "arrowListModel\0getNode\0Node*\0\0index\0"
    "checkExisted\0checkExisting\0A\0B\0"
    "updateMatrix\0NodeA\0NodeB\0Arrow*\0p_arrow\0"
    "getArrow\0removeBindings\0node\0updated\0"
    "bindA\0nodeIndex\0bindB\0remove\0arrow\0"
    "removeCurrent\0showMap\0showArrowList\0"
    "kill"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_arrowListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    3, 0x06 /* Public */,
       6,    2,   84,    3, 0x06 /* Public */,
       9,    3,   89,    3, 0x06 /* Public */,
      14,    2,   96,    3, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  101,    3, 0x08 /* Private */,
      17,    1,  104,    3, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      18,    1,  107,    3, 0x02 /* Public */,
      20,    1,  110,    3, 0x02 /* Public */,
      21,    1,  113,    3, 0x02 /* Public */,
      23,    0,  116,    3, 0x02 /* Public */,
      24,    0,  117,    3, 0x02 /* Public */,
      25,    0,  118,    3, 0x02 /* Public */,
      26,    0,  119,    3, 0x02 /* Public */,

 // signals: parameters
    0x80000000 | 2, QMetaType::Int, QMetaType::Bool,    4,    5,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 12,   10,   11,   13,
    0x80000000 | 12, QMetaType::Int, QMetaType::Int,   10,   11,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 2,   16,
    QMetaType::Void, 0x80000000 | 2,   16,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, 0x80000000 | 12,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void arrowListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<arrowListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { Node* _r = _t->getNode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Node**>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->checkExisting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->updateMatrix((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Arrow*(*)>(_a[3]))); break;
        case 3: { Arrow* _r = _t->getArrow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Arrow**>(_a[0]) = std::move(_r); }  break;
        case 4: _t->removeBindings((*reinterpret_cast< Node*(*)>(_a[1]))); break;
        case 5: _t->updated((*reinterpret_cast< Node*(*)>(_a[1]))); break;
        case 6: _t->bindA((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->bindB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->remove((*reinterpret_cast< Arrow*(*)>(_a[1]))); break;
        case 9: _t->removeCurrent(); break;
        case 10: _t->showMap(); break;
        case 11: _t->showArrowList(); break;
        case 12: _t->kill(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = Node * (arrowListModel::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::getNode)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = int (arrowListModel::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::checkExisting)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (arrowListModel::*)(int , int , Arrow * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::updateMatrix)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = Arrow * (arrowListModel::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::getArrow)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject arrowListModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_arrowListModel.data,
    qt_meta_data_arrowListModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *arrowListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *arrowListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_arrowListModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int arrowListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
Node * arrowListModel::getNode(int _t1, bool _t2)
{
    Node* _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
int arrowListModel::checkExisting(int _t1, int _t2)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
void arrowListModel::updateMatrix(int _t1, int _t2, Arrow * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
Arrow * arrowListModel::getArrow(int _t1, int _t2)
{
    Arrow* _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
