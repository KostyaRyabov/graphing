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
    QByteArrayData data[20];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NodeManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NodeManager_t qt_meta_stringdata_NodeManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NodeManager"
QT_MOC_LITERAL(1, 12, 7), // "addItem"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "removeNode"
QT_MOC_LITERAL(4, 32, 5), // "index"
QT_MOC_LITERAL(5, 38, 13), // "checkExisting"
QT_MOC_LITERAL(6, 52, 1), // "A"
QT_MOC_LITERAL(7, 54, 1), // "B"
QT_MOC_LITERAL(8, 56, 12), // "updateMatrix"
QT_MOC_LITERAL(9, 69, 5), // "NodeA"
QT_MOC_LITERAL(10, 75, 5), // "NodeB"
QT_MOC_LITERAL(11, 81, 6), // "Arrow*"
QT_MOC_LITERAL(12, 88, 7), // "p_arrow"
QT_MOC_LITERAL(13, 96, 8), // "getArrow"
QT_MOC_LITERAL(14, 105, 7), // "newFile"
QT_MOC_LITERAL(15, 113, 8), // "openFile"
QT_MOC_LITERAL(16, 122, 8), // "saveFile"
QT_MOC_LITERAL(17, 131, 10), // "saveAsFile"
QT_MOC_LITERAL(18, 142, 14), // "filePathExists"
QT_MOC_LITERAL(19, 157, 10) // "showMatrix"

    },
    "NodeManager\0addItem\0\0removeNode\0index\0"
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
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    1,   70,    2, 0x08 /* Private */,
       5,    2,   73,    2, 0x08 /* Private */,
       8,    3,   78,    2, 0x08 /* Private */,
      13,    2,   85,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      14,    0,   90,    2, 0x02 /* Public */,
      15,    0,   91,    2, 0x02 /* Public */,
      16,    0,   92,    2, 0x02 /* Public */,
      17,    0,   93,    2, 0x02 /* Public */,
      18,    0,   94,    2, 0x02 /* Public */,
      19,    0,   95,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 11,    9,   10,   12,
    0x80000000 | 11, QMetaType::Int, QMetaType::Int,    9,   10,

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
        case 0: _t->addItem(); break;
        case 1: _t->removeNode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { int _r = _t->checkExisting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->updateMatrix((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Arrow*(*)>(_a[3]))); break;
        case 4: { Arrow* _r = _t->getArrow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Arrow**>(_a[0]) = std::move(_r); }  break;
        case 5: _t->newFile(); break;
        case 6: _t->openFile(); break;
        case 7: _t->saveFile(); break;
        case 8: _t->saveAsFile(); break;
        case 9: { bool _r = _t->filePathExists();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->showMatrix(); break;
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
