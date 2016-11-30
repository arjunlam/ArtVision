/****************************************************************************
** Meta object code from reading C++ file 'edgedetectionwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/edgedetectionwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'edgedetectionwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EdgeDetectionWidget_t {
    QByteArrayData data[12];
    char stringdata[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EdgeDetectionWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EdgeDetectionWidget_t qt_meta_stringdata_EdgeDetectionWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "EdgeDetectionWidget"
QT_MOC_LITERAL(1, 20, 21), // "messageSetSourceImage"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 51, 5), // "image"
QT_MOC_LITERAL(5, 57, 6), // "GLenum"
QT_MOC_LITERAL(6, 64, 9), // "minFilter"
QT_MOC_LITERAL(7, 74, 9), // "magFilter"
QT_MOC_LITERAL(8, 84, 10), // "wrapFilter"
QT_MOC_LITERAL(9, 95, 19), // "messageSetEdgeImage"
QT_MOC_LITERAL(10, 115, 27), // "messageSetIntersectionImage"
QT_MOC_LITERAL(11, 143, 19) // "onLoadButtonClicked"

    },
    "EdgeDetectionWidget\0messageSetSourceImage\0"
    "\0cv::Mat\0image\0GLenum\0minFilter\0"
    "magFilter\0wrapFilter\0messageSetEdgeImage\0"
    "messageSetIntersectionImage\0"
    "onLoadButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EdgeDetectionWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   34,    2, 0x06 /* Public */,
       9,    4,   43,    2, 0x06 /* Public */,
      10,    4,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,    8,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void EdgeDetectionWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EdgeDetectionWidget *_t = static_cast<EdgeDetectionWidget *>(_o);
        switch (_id) {
        case 0: _t->messageSetSourceImage((*reinterpret_cast< const cv::Mat(*)>(_a[1])),(*reinterpret_cast< GLenum(*)>(_a[2])),(*reinterpret_cast< GLenum(*)>(_a[3])),(*reinterpret_cast< GLenum(*)>(_a[4]))); break;
        case 1: _t->messageSetEdgeImage((*reinterpret_cast< const cv::Mat(*)>(_a[1])),(*reinterpret_cast< GLenum(*)>(_a[2])),(*reinterpret_cast< GLenum(*)>(_a[3])),(*reinterpret_cast< GLenum(*)>(_a[4]))); break;
        case 2: _t->messageSetIntersectionImage((*reinterpret_cast< const cv::Mat(*)>(_a[1])),(*reinterpret_cast< GLenum(*)>(_a[2])),(*reinterpret_cast< GLenum(*)>(_a[3])),(*reinterpret_cast< GLenum(*)>(_a[4]))); break;
        case 3: _t->onLoadButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EdgeDetectionWidget::*_t)(const cv::Mat & , GLenum , GLenum , GLenum );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EdgeDetectionWidget::messageSetSourceImage)) {
                *result = 0;
            }
        }
        {
            typedef void (EdgeDetectionWidget::*_t)(const cv::Mat & , GLenum , GLenum , GLenum );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EdgeDetectionWidget::messageSetEdgeImage)) {
                *result = 1;
            }
        }
        {
            typedef void (EdgeDetectionWidget::*_t)(const cv::Mat & , GLenum , GLenum , GLenum );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EdgeDetectionWidget::messageSetIntersectionImage)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject EdgeDetectionWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EdgeDetectionWidget.data,
      qt_meta_data_EdgeDetectionWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EdgeDetectionWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EdgeDetectionWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EdgeDetectionWidget.stringdata))
        return static_cast<void*>(const_cast< EdgeDetectionWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int EdgeDetectionWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void EdgeDetectionWidget::messageSetSourceImage(const cv::Mat & _t1, GLenum _t2, GLenum _t3, GLenum _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EdgeDetectionWidget::messageSetEdgeImage(const cv::Mat & _t1, GLenum _t2, GLenum _t3, GLenum _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EdgeDetectionWidget::messageSetIntersectionImage(const cv::Mat & _t1, GLenum _t2, GLenum _t3, GLenum _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
