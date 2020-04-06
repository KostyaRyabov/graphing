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
    QByteArrayData data[16];
    char stringdata0[117];
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
QT_MOC_LITERAL(6, 49, 7), // "updated"
QT_MOC_LITERAL(7, 57, 4), // "node"
QT_MOC_LITERAL(8, 62, 5), // "bindA"
QT_MOC_LITERAL(9, 68, 9), // "nodeIndex"
QT_MOC_LITERAL(10, 78, 5), // "bindB"
QT_MOC_LITERAL(11, 84, 6), // "remove"
QT_MOC_LITERAL(12, 91, 1), // "A"
QT_MOC_LITERAL(13, 93, 1), // "B"
QT_MOC_LITERAL(14, 95, 7), // "showMap"
QT_MOC_LITERAL(15, 103, 13) // "showArrowList"

    },
    "arrowListModel\0getNode\0Node*\0\0index\0"
    "checkExisted\0updated\0node\0bindA\0"
    "nodeIndex\0bindB\0remove\0A\0B\0showMap\0"
    "showArrowList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_arrowListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    3, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   54,    3, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       8,    1,   57,    3, 0x02 /* Public */,
      10,    1,   60,    3, 0x02 /* Public */,
      11,    2,   63,    3, 0x02 /* Public */,
      14,    0,   68,    3, 0x02 /* Public */,
      15,    0,   69,    3, 0x02 /* Public */,

 // signals: parameters
    0x80000000 | 2, QMetaType::Int, QMetaType::Bool,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 2,    7,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
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
        case 1: _t->updated((*reinterpret_cast< Node*(*)>(_a[1]))); break;
        case 2: _t->bindA((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->bindB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->remove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->showMap(); break;
        case 6: _t->showArrowList(); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
