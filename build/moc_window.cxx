/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created: Tue Sep 3 14:48:53 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      48,   11,   11,   11, 0x0a,
      75,   11,   11,   11, 0x0a,
      96,   11,   11,   11, 0x0a,
     111,   11,   11,   11, 0x0a,
     138,   11,   11,   11, 0x0a,
     145,   11,   11,   11, 0x0a,
     153,   11,   11,   11, 0x0a,
     160,   11,   11,   11, 0x0a,
     174,   11,   11,   11, 0x0a,
     183,   11,   11,   11, 0x0a,
     193,   11,   11,   11, 0x0a,
     210,   11,   11,   11, 0x0a,
     229,   11,   11,   11, 0x0a,
     238,   11,   11,   11, 0x0a,
     249,   11,   11,   11, 0x0a,
     261,   11,   11,   11, 0x0a,
     277,  272,   11,   11, 0x0a,
     300,   11,  295,   11, 0x0a,
     321,   11,  295,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionRandom_Circles_triggered()\0"
    "on_actionCircles_toggled()\0"
    "activate_obstacles()\0timer_update()\0"
    "setObstacleRadius_window()\0play()\0"
    "pause()\0quit()\0coordinates()\0radius()\0"
    "restart()\0default_values()\0"
    "bin_count_window()\0upWind()\0downWind()\0"
    "rightWind()\0leftWind()\0args\0"
    "run_batch(char**)\0bool\0isMovingParticlesq()\0"
    "isDoneRunq()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actionRandom_Circles_triggered(); break;
        case 1: _t->on_actionCircles_toggled(); break;
        case 2: _t->activate_obstacles(); break;
        case 3: _t->timer_update(); break;
        case 4: _t->setObstacleRadius_window(); break;
        case 5: _t->play(); break;
        case 6: _t->pause(); break;
        case 7: _t->quit(); break;
        case 8: _t->coordinates(); break;
        case 9: _t->radius(); break;
        case 10: _t->restart(); break;
        case 11: _t->default_values(); break;
        case 12: _t->bin_count_window(); break;
        case 13: _t->upWind(); break;
        case 14: _t->downWind(); break;
        case 15: _t->rightWind(); break;
        case 16: _t->leftWind(); break;
        case 17: _t->run_batch((*reinterpret_cast< char**(*)>(_a[1]))); break;
        case 18: { bool _r = _t->isMovingParticlesq();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 19: { bool _r = _t->isDoneRunq();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    if (!strcmp(_clname, "Ui_MainWindow"))
        return static_cast< Ui_MainWindow*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
