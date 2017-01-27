/****************************************************************************
** Meta object code from reading C++ file 'NGLScene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/NGLScene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NGLScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NGLScene_t {
    QByteArrayData data[28];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NGLScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NGLScene_t qt_meta_stringdata_NGLScene = {
    {
QT_MOC_LITERAL(0, 0, 8), // "NGLScene"
QT_MOC_LITERAL(1, 9, 11), // "matrixDirty"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "ngl::Mat4"
QT_MOC_LITERAL(4, 32, 2), // "_m"
QT_MOC_LITERAL(5, 35, 10), // "vboChanged"
QT_MOC_LITERAL(6, 46, 6), // "_index"
QT_MOC_LITERAL(7, 53, 13), // "toggleNormals"
QT_MOC_LITERAL(8, 67, 6), // "_value"
QT_MOC_LITERAL(9, 74, 13), // "showSkeletons"
QT_MOC_LITERAL(10, 88, 14), // "resetanimation"
QT_MOC_LITERAL(11, 103, 11), // "elimination"
QT_MOC_LITERAL(12, 115, 15), // "toggleWireframe"
QT_MOC_LITERAL(13, 131, 13), // "setNormalSize"
QT_MOC_LITERAL(14, 145, 8), // "setScale"
QT_MOC_LITERAL(15, 154, 2), // "_x"
QT_MOC_LITERAL(16, 157, 2), // "_y"
QT_MOC_LITERAL(17, 160, 2), // "_z"
QT_MOC_LITERAL(18, 163, 12), // "setTranslate"
QT_MOC_LITERAL(19, 176, 9), // "setRotate"
QT_MOC_LITERAL(20, 186, 7), // "setPace"
QT_MOC_LITERAL(21, 194, 9), // "setColour"
QT_MOC_LITERAL(22, 204, 2), // "_r"
QT_MOC_LITERAL(23, 207, 2), // "_g"
QT_MOC_LITERAL(24, 210, 2), // "_b"
QT_MOC_LITERAL(25, 213, 14), // "setMatrixOrder"
QT_MOC_LITERAL(26, 228, 8), // "setEuler"
QT_MOC_LITERAL(27, 237, 6) // "_angle"

    },
    "NGLScene\0matrixDirty\0\0ngl::Mat4\0_m\0"
    "vboChanged\0_index\0toggleNormals\0_value\0"
    "showSkeletons\0resetanimation\0elimination\0"
    "toggleWireframe\0setNormalSize\0setScale\0"
    "_x\0_y\0_z\0setTranslate\0setRotate\0setPace\0"
    "setColour\0_r\0_g\0_b\0setMatrixOrder\0"
    "setEuler\0_angle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NGLScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   92,    2, 0x0a /* Public */,
       7,    1,   95,    2, 0x0a /* Public */,
       9,    1,   98,    2, 0x0a /* Public */,
      10,    1,  101,    2, 0x0a /* Public */,
      11,    1,  104,    2, 0x0a /* Public */,
      12,    1,  107,    2, 0x0a /* Public */,
      13,    1,  110,    2, 0x0a /* Public */,
      14,    3,  113,    2, 0x0a /* Public */,
      18,    3,  120,    2, 0x0a /* Public */,
      19,    3,  127,    2, 0x0a /* Public */,
      20,    3,  134,    2, 0x0a /* Public */,
      21,    3,  141,    2, 0x0a /* Public */,
      25,    1,  148,    2, 0x0a /* Public */,
      26,    4,  151,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,   15,   16,   17,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,   15,   16,   17,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,   15,   16,   17,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,   15,   16,   17,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,   22,   23,   24,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,   27,   15,   16,   17,

       0        // eod
};

void NGLScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NGLScene *_t = static_cast<NGLScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->matrixDirty((*reinterpret_cast< ngl::Mat4(*)>(_a[1]))); break;
        case 1: _t->vboChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->toggleNormals((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->showSkeletons((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->resetanimation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->elimination((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->toggleWireframe((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setNormalSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setScale((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 9: _t->setTranslate((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 10: _t->setRotate((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 11: _t->setPace((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 12: _t->setColour((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 13: _t->setMatrixOrder((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setEuler((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NGLScene::*_t)(ngl::Mat4 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NGLScene::matrixDirty)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject NGLScene::staticMetaObject = {
    { &QOpenGLWidget::staticMetaObject, qt_meta_stringdata_NGLScene.data,
      qt_meta_data_NGLScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NGLScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NGLScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NGLScene.stringdata0))
        return static_cast<void*>(const_cast< NGLScene*>(this));
    return QOpenGLWidget::qt_metacast(_clname);
}

int NGLScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void NGLScene::matrixDirty(ngl::Mat4 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
