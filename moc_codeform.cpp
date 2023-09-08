/****************************************************************************
** Meta object code from reading C++ file 'codeform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "codeform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'codeform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CodeForm_t {
    QByteArrayData data[12];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CodeForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CodeForm_t qt_meta_stringdata_CodeForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CodeForm"
QT_MOC_LITERAL(1, 9, 12), // "start_search"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "stop_search"
QT_MOC_LITERAL(4, 35, 12), // "replace_func"
QT_MOC_LITERAL(5, 48, 9), // "isChanged"
QT_MOC_LITERAL(6, 58, 11), // "search_Next"
QT_MOC_LITERAL(7, 70, 17), // "handleButtonClick"
QT_MOC_LITERAL(8, 88, 10), // "addContent"
QT_MOC_LITERAL(9, 99, 4), // "line"
QT_MOC_LITERAL(10, 104, 7), // "content"
QT_MOC_LITERAL(11, 112, 10) // "changeFold"

    },
    "CodeForm\0start_search\0\0stop_search\0"
    "replace_func\0isChanged\0search_Next\0"
    "handleButtonClick\0addContent\0line\0"
    "content\0changeFold"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CodeForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       3,    1,   57,    2, 0x0a /* Public */,
       4,    2,   60,    2, 0x0a /* Public */,
       5,    0,   65,    2, 0x0a /* Public */,
       6,    1,   66,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    2,   70,    2, 0x0a /* Public */,
      11,    0,   75,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    9,   10,
    QMetaType::Void,

       0        // eod
};

void CodeForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CodeForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->start_search((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->stop_search((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->replace_func((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->isChanged(); break;
        case 4: _t->search_Next((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->handleButtonClick(); break;
        case 6: _t->addContent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->changeFold(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CodeForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CodeForm.data,
    qt_meta_data_CodeForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CodeForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CodeForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CodeForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CodeForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
