/****************************************************************************
** Meta object code from reading C++ file 'imageviewerwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/imageviewerwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageviewerwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageViewerWidget_t {
    QByteArrayData data[10];
    char stringdata[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageViewerWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageViewerWidget_t qt_meta_stringdata_ImageViewerWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ImageViewerWidget"
QT_MOC_LITERAL(1, 18, 10), // "onSetImage"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 38, 5), // "image"
QT_MOC_LITERAL(5, 44, 6), // "GLenum"
QT_MOC_LITERAL(6, 51, 9), // "minFilter"
QT_MOC_LITERAL(7, 61, 9), // "magFilter"
QT_MOC_LITERAL(8, 71, 10), // "wrapFilter"
QT_MOC_LITERAL(9, 82, 12) // "onClearImage"

    },
    "ImageViewerWidget\0onSetImage\0\0cv::Mat\0"
    "image\0GLenum\0minFilter\0magFilter\0"
    "wrapFilter\0onClearImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageViewerWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x0a /* Public */,
       9,    0,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,    8,
    QMetaType::Void,

       0        // eod
};

void ImageViewerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageViewerWidget *_t = static_cast<ImageViewerWidget *>(_o);
        switch (_id) {
        case 0: _t->onSetImage((*reinterpret_cast< const cv::Mat(*)>(_a[1])),(*reinterpret_cast< GLenum(*)>(_a[2])),(*reinterpret_cast< GLenum(*)>(_a[3])),(*reinterpret_cast< GLenum(*)>(_a[4]))); break;
        case 1: _t->onClearImage(); break;
        default: ;
        }
    }
}

const QMetaObject ImageViewerWidget::staticMetaObject = {
    { &QOpenGLWidget::staticMetaObject, qt_meta_stringdata_ImageViewerWidget.data,
      qt_meta_data_ImageViewerWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageViewerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageViewerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageViewerWidget.stringdata))
        return static_cast<void*>(const_cast< ImageViewerWidget*>(this));
    if (!strcmp(_clname, "QOpenGLFunctions_2_0"))
        return static_cast< QOpenGLFunctions_2_0*>(const_cast< ImageViewerWidget*>(this));
    return QOpenGLWidget::qt_metacast(_clname);
}

int ImageViewerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
