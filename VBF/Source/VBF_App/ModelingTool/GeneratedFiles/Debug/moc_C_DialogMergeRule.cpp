/****************************************************************************
** Meta object code from reading C++ file 'C_DialogMergeRule.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../C_DialogMergeRule.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'C_DialogMergeRule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_C_DialogMergeRule[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      29,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_C_DialogMergeRule[] = {
    "C_DialogMergeRule\0\0onBtnOK()\0onBtnCancel()\0"
};

void C_DialogMergeRule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        C_DialogMergeRule *_t = static_cast<C_DialogMergeRule *>(_o);
        switch (_id) {
        case 0: _t->onBtnOK(); break;
        case 1: _t->onBtnCancel(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData C_DialogMergeRule::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject C_DialogMergeRule::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_C_DialogMergeRule,
      qt_meta_data_C_DialogMergeRule, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &C_DialogMergeRule::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *C_DialogMergeRule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *C_DialogMergeRule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_C_DialogMergeRule))
        return static_cast<void*>(const_cast< C_DialogMergeRule*>(this));
    if (!strcmp(_clname, "Ui::C_DialogMergeRule"))
        return static_cast< Ui::C_DialogMergeRule*>(const_cast< C_DialogMergeRule*>(this));
    return QDialog::qt_metacast(_clname);
}

int C_DialogMergeRule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE