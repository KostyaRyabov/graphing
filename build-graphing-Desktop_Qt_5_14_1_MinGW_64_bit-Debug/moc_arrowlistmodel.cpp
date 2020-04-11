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
    QByteArrayData data[29];
    char stringdata0[260];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_arrowListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_arrowListModel_t qt_meta_stringdata_arrowListModel = {
    {
QT_MOC_LITERAL(0, 0, 14), // "arrowListModel"
QT_MOC_LITERAL(1, 15, 10), // "showMatrix"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 20), // "getArrowListWithNode"
QT_MOC_LITERAL(4, 48, 15), // "QVector<Arrow*>"
QT_MOC_LITERAL(5, 64, 5), // "nodeA"
QT_MOC_LITERAL(6, 70, 7), // "getNode"
QT_MOC_LITERAL(7, 78, 5), // "Node*"
QT_MOC_LITERAL(8, 84, 5), // "index"
QT_MOC_LITERAL(9, 90, 12), // "checkExisted"
QT_MOC_LITERAL(10, 103, 13), // "checkExisting"
QT_MOC_LITERAL(11, 117, 1), // "A"
QT_MOC_LITERAL(12, 119, 1), // "B"
QT_MOC_LITERAL(13, 121, 12), // "updateMatrix"
QT_MOC_LITERAL(14, 134, 5), // "NodeA"
QT_MOC_LITERAL(15, 140, 5), // "NodeB"
QT_MOC_LITERAL(16, 146, 6), // "Arrow*"
QT_MOC_LITERAL(17, 153, 7), // "p_arrow"
QT_MOC_LITERAL(18, 161, 8), // "getArrow"
QT_MOC_LITERAL(19, 170, 10), // "createLoop"
QT_MOC_LITERAL(20, 181, 9), // "nodeIndex"
QT_MOC_LITERAL(21, 191, 5), // "bindA"
QT_MOC_LITERAL(22, 197, 5), // "bindB"
QT_MOC_LITERAL(23, 203, 6), // "remove"
QT_MOC_LITERAL(24, 210, 7), // "arrowID"
QT_MOC_LITERAL(25, 218, 8), // "animated"
QT_MOC_LITERAL(26, 227, 13), // "removeCurrent"
QT_MOC_LITERAL(27, 241, 13), // "showArrowList"
QT_MOC_LITERAL(28, 255, 4) // "kill"

    },
    "arrowListModel\0showMatrix\0\0"
    "getArrowListWithNode\0QVector<Arrow*>\0"
    "nodeA\0getNode\0Node*\0index\0checkExisted\0"
    "checkExisting\0A\0B\0updateMatrix\0NodeA\0"
    "NodeB\0Arrow*\0p_arrow\0getArrow\0createLoop\0"
    "nodeIndex\0bindA\0bindB\0remove\0arrowID\0"
    "animated\0removeCurrent\0showArrowList\0"
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
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    1,   80,    2, 0x06 /* Public */,
       6,    2,   83,    2, 0x06 /* Public */,
      10,    2,   88,    2, 0x06 /* Public */,
      13,    3,   93,    2, 0x06 /* Public */,
      18,    2,  100,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      19,    1,  105,    2, 0x02 /* Public */,
      21,    1,  108,    2, 0x02 /* Public */,
      22,    1,  111,    2, 0x02 /* Public */,
      23,    2,  114,    2, 0x02 /* Public */,
      26,    0,  119,    2, 0x02 /* Public */,
      27,    0,  120,    2, 0x02 /* Public */,
      28,    0,  121,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    0x80000000 | 4, QMetaType::Int,    5,
    0x80000000 | 7, QMetaType::Int, QMetaType::Bool,    8,    9,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 16,   14,   15,   17,
    0x80000000 | 16, QMetaType::Int, QMetaType::Int,   14,   15,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   24,   25,
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
        case 0: _t->showMatrix(); break;
        case 1: { QVector<Arrow*> _r = _t->getArrowListWithNode((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector<Arrow*>*>(_a[0]) = std::move(_r); }  break;
        case 2: { Node* _r = _t->getNode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Node**>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->checkExisting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->updateMatrix((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Arrow*(*)>(_a[3]))); break;
        case 5: { Arrow* _r = _t->getArrow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Arrow**>(_a[0]) = std::move(_r); }  break;
        case 6: _t->createLoop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->bindA((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->bindB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->remove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->removeCurrent(); break;
        case 11: _t->showArrowList(); break;
        case 12: _t->kill(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (arrowListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::showMatrix)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = QVector<Arrow*> (arrowListModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::getArrowListWithNode)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = Node * (arrowListModel::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::getNode)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = int (arrowListModel::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::checkExisting)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (arrowListModel::*)(int , int , Arrow * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::updateMatrix)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = Arrow * (arrowListModel::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&arrowListModel::getArrow)) {
                *result = 5;
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
void arrowListModel::showMatrix()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
QVector<Arrow*> arrowListModel::getArrowListWithNode(int _t1)
{
    QVector<Arrow*> _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
Node * arrowListModel::getNode(int _t1, bool _t2)
{
    Node* _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}

// SIGNAL 3
int arrowListModel::checkExisting(int _t1, int _t2)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
    return _t0;
}

// SIGNAL 4
void arrowListModel::updateMatrix(int _t1, int _t2, Arrow * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
Arrow * arrowListModel::getArrow(int _t1, int _t2)
{
    Arrow* _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
