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
    QByteArrayData data[18];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NodeManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NodeManager_t qt_meta_stringdata_NodeManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NodeManager"
QT_MOC_LITERAL(1, 12, 11), // "dataChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "addNode"
QT_MOC_LITERAL(4, 33, 1), // "x"
QT_MOC_LITERAL(5, 35, 1), // "y"
QT_MOC_LITERAL(6, 37, 12), // "updateMatrix"
QT_MOC_LITERAL(7, 50, 5), // "NodeA"
QT_MOC_LITERAL(8, 56, 5), // "NodeB"
QT_MOC_LITERAL(9, 62, 7), // "related"
QT_MOC_LITERAL(10, 70, 10), // "removeNode"
QT_MOC_LITERAL(11, 81, 1), // "i"
QT_MOC_LITERAL(12, 83, 7), // "newFile"
QT_MOC_LITERAL(13, 91, 8), // "openFile"
QT_MOC_LITERAL(14, 100, 8), // "saveFile"
QT_MOC_LITERAL(15, 109, 10), // "saveAsFile"
QT_MOC_LITERAL(16, 120, 14), // "filePathExists"
QT_MOC_LITERAL(17, 135, 6) // "NOTIFY"

    },
    "NodeManager\0dataChanged\0\0addNode\0x\0y\0"
    "updateMatrix\0NodeA\0NodeB\0related\0"
    "removeNode\0i\0newFile\0openFile\0saveFile\0"
    "saveAsFile\0filePathExists\0NOTIFY"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NodeManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       1,   80, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   60,    2, 0x0a /* Public */,
       6,    3,   65,    2, 0x0a /* Public */,
      10,    1,   72,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      12,    0,   75,    2, 0x02 /* Public */,
      13,    0,   76,    2, 0x02 /* Public */,
      14,    0,   77,    2, 0x02 /* Public */,
      15,    0,   78,    2, 0x02 /* Public */,
      16,    0,   79,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    7,    8,    9,
    QMetaType::Void, QMetaType::Int,   11,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

 // properties: name, type, flags
       1, 0x80000000 | 17, 0x00095008,

       0        // eod
};

void NodeManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NodeManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataChanged(); break;
        case 1: _t->addNode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->updateMatrix((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->removeNode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->newFile(); break;
        case 5: _t->openFile(); break;
        case 6: _t->saveFile(); break;
        case 7: _t->saveAsFile(); break;
        case 8: { bool _r = _t->filePathExists();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NodeManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NodeManager::dataChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void NodeManager::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
