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
    QByteArrayData data[42];
    char stringdata0[368];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_arrowListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_arrowListModel_t qt_meta_stringdata_arrowListModel = {
    {
QT_MOC_LITERAL(0, 0, 14), // "arrowListModel"
QT_MOC_LITERAL(1, 15, 18), // "checkNodeCollision"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 19), // "updateNodesPosition"
QT_MOC_LITERAL(4, 55, 10), // "selectNode"
QT_MOC_LITERAL(5, 66, 6), // "nodeID"
QT_MOC_LITERAL(6, 73, 6), // "append"
QT_MOC_LITERAL(7, 80, 10), // "updateNode"
QT_MOC_LITERAL(8, 91, 1), // "i"
QT_MOC_LITERAL(9, 93, 5), // "value"
QT_MOC_LITERAL(10, 99, 4), // "role"
QT_MOC_LITERAL(11, 104, 20), // "getArrowListWithNode"
QT_MOC_LITERAL(12, 125, 15), // "QVector<Arrow*>"
QT_MOC_LITERAL(13, 141, 5), // "nodeA"
QT_MOC_LITERAL(14, 147, 7), // "getNode"
QT_MOC_LITERAL(15, 155, 5), // "Node*"
QT_MOC_LITERAL(16, 161, 5), // "index"
QT_MOC_LITERAL(17, 167, 12), // "checkExisted"
QT_MOC_LITERAL(18, 180, 13), // "checkExisting"
QT_MOC_LITERAL(19, 194, 1), // "A"
QT_MOC_LITERAL(20, 196, 1), // "B"
QT_MOC_LITERAL(21, 198, 12), // "updateMatrix"
QT_MOC_LITERAL(22, 211, 5), // "NodeA"
QT_MOC_LITERAL(23, 217, 5), // "NodeB"
QT_MOC_LITERAL(24, 223, 6), // "Arrow*"
QT_MOC_LITERAL(25, 230, 7), // "p_arrow"
QT_MOC_LITERAL(26, 238, 8), // "getArrow"
QT_MOC_LITERAL(27, 247, 10), // "createLoop"
QT_MOC_LITERAL(28, 258, 9), // "nodeIndex"
QT_MOC_LITERAL(29, 268, 5), // "bindA"
QT_MOC_LITERAL(30, 274, 5), // "bindB"
QT_MOC_LITERAL(31, 280, 6), // "remove"
QT_MOC_LITERAL(32, 287, 7), // "arrowID"
QT_MOC_LITERAL(33, 295, 8), // "animated"
QT_MOC_LITERAL(34, 304, 13), // "removeCurrent"
QT_MOC_LITERAL(35, 318, 13), // "showArrowList"
QT_MOC_LITERAL(36, 332, 4), // "kill"
QT_MOC_LITERAL(37, 337, 6), // "moveTo"
QT_MOC_LITERAL(38, 344, 2), // "lX"
QT_MOC_LITERAL(39, 347, 2), // "lY"
QT_MOC_LITERAL(40, 350, 5), // "angle"
QT_MOC_LITERAL(41, 356, 11) // "changeFocus"

    },
    "arrowListModel\0checkNodeCollision\0\0"
    "updateNodesPosition\0selectNode\0nodeID\0"
    "append\0updateNode\0i\0value\0role\0"
    "getArrowListWithNode\0QVector<Arrow*>\0"
    "nodeA\0getNode\0Node*\0index\0checkExisted\0"
    "checkExisting\0A\0B\0updateMatrix\0NodeA\0"
    "NodeB\0Arrow*\0p_arrow\0getArrow\0createLoop\0"
    "nodeIndex\0bindA\0bindB\0remove\0arrowID\0"
    "animated\0removeCurrent\0showArrowList\0"
    "kill\0moveTo\0lX\0lY\0angle\0changeFocus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_arrowListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    2,  106,    2, 0x06 /* Public */,
       7,    3,  111,    2, 0x06 /* Public */,
      11,    1,  118,    2, 0x06 /* Public */,
      14,    2,  121,    2, 0x06 /* Public */,
      18,    2,  126,    2, 0x06 /* Public */,
      21,    3,  131,    2, 0x06 /* Public */,
      26,    2,  138,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      27,    1,  143,    2, 0x02 /* Public */,
      29,    1,  146,    2, 0x02 /* Public */,
      30,    1,  149,    2, 0x02 /* Public */,
      31,    2,  152,    2, 0x02 /* Public */,
      34,    0,  157,    2, 0x02 /* Public */,
      35,    0,  158,    2, 0x02 /* Public */,
      36,    0,  159,    2, 0x02 /* Public */,
      37,    4,  160,    2, 0x02 /* Public */,
      41,    1,  169,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,
    0x80000000 | 12, QMetaType::Int,   13,
    0x80000000 | 15, QMetaType::Int, QMetaType::Bool,   16,   17,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   19,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 24,   22,   23,   25,
    0x80000000 | 24, QMetaType::Int, QMetaType::Int,   22,   23,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   32,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Float,   32,   38,   39,   40,
    QMetaType::Void, QMetaType::Int,   32,

       0        // eod
};

void arrowListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<arrowListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkNodeCollision(); break;
        case 1: _t->updateNodesPosition(); break;
        case 2: _t->selectNode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->updateNode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: { QVector<Arrow*> _r = _t->getArrowListWithNode((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector<Arrow*>*>(_a[0]) = std::move(_r); }  break;
        case 5: { Node* _r = _t->getNode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Node**>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->checkExisting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->updateMatrix((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Arrow*(*)>(_a[3]))); break;
        case 8: { Arrow* _r = _t->getArrow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Arrow**>(_a[0]) = std::move(_r); }  break;
        case 9: _t->createLoop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->bindA((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->bindB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->remove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: _t->removeCurrent(); break;
        case 14: _t->showArrowList(); break;
        case 15: _t->kill(); break;
        case 16: _t->moveTo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 17: _t->changeFocus((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (arrowListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::checkNodeCollision)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (arrowListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::updateNodesPosition)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (arrowListModel::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::selectNode)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (arrowListModel::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::updateNode)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = QVector<Arrow*> (arrowListModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::getArrowListWithNode)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = Node * (arrowListModel::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::getNode)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = int (arrowListModel::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::checkExisting)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (arrowListModel::*)(int , int , Arrow * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::updateMatrix)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = Arrow * (arrowListModel::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::getArrow)) {
                *result = 8;
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void arrowListModel::checkNodeCollision()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void arrowListModel::updateNodesPosition()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void arrowListModel::selectNode(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void arrowListModel::updateNode(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
QVector<Arrow*> arrowListModel::getArrowListWithNode(int _t1)
{
    QVector<Arrow*> _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
    return _t0;
}

// SIGNAL 5
Node * arrowListModel::getNode(int _t1, bool _t2)
{
    Node* _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
    return _t0;
}

// SIGNAL 6
int arrowListModel::checkExisting(int _t1, int _t2)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
    return _t0;
}

// SIGNAL 7
void arrowListModel::updateMatrix(int _t1, int _t2, Arrow * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
Arrow * arrowListModel::getArrow(int _t1, int _t2)
{
    Arrow* _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
