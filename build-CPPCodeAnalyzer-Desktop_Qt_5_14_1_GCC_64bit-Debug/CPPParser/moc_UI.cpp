/****************************************************************************
** Meta object code from reading C++ file 'UI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CPPCodeAnalyzer/CPPParser/UI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UI_t {
    QByteArrayData data[62];
    char stringdata0[802];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UI_t qt_meta_stringdata_UI = {
    {
QT_MOC_LITERAL(0, 0, 2), // "UI"
QT_MOC_LITERAL(1, 3, 23), // "ChuteStartButtonClicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 2), // "id"
QT_MOC_LITERAL(4, 31, 21), // "SystemShutDownRequest"
QT_MOC_LITERAL(5, 53, 19), // "SystemRebootRequest"
QT_MOC_LITERAL(6, 73, 22), // "sendSortingTypeRequest"
QT_MOC_LITERAL(7, 96, 7), // "chuteID"
QT_MOC_LITERAL(8, 104, 14), // "QList<QString>"
QT_MOC_LITERAL(9, 119, 6), // "labels"
QT_MOC_LITERAL(10, 126, 14), // "SetFeederSpeed"
QT_MOC_LITERAL(11, 141, 11), // "feederSpeed"
QT_MOC_LITERAL(12, 153, 14), // "SetElapsedTime"
QT_MOC_LITERAL(13, 168, 4), // "hour"
QT_MOC_LITERAL(14, 173, 6), // "minute"
QT_MOC_LITERAL(15, 180, 13), // "ChuteShutdown"
QT_MOC_LITERAL(16, 194, 11), // "ChuteReboot"
QT_MOC_LITERAL(17, 206, 8), // "AddChute"
QT_MOC_LITERAL(18, 215, 11), // "DeleteChute"
QT_MOC_LITERAL(19, 227, 11), // "UpdateChart"
QT_MOC_LITERAL(20, 239, 7), // "int64_t"
QT_MOC_LITERAL(21, 247, 11), // "totalAccept"
QT_MOC_LITERAL(22, 259, 10), // "totalEject"
QT_MOC_LITERAL(23, 270, 14), // "ADDSortingType"
QT_MOC_LITERAL(24, 285, 20), // "ClearAllSortingTypes"
QT_MOC_LITERAL(25, 306, 17), // "UpdateElapsedTime"
QT_MOC_LITERAL(26, 324, 11), // "elapsedTime"
QT_MOC_LITERAL(27, 336, 17), // "UpdateTotalValues"
QT_MOC_LITERAL(28, 354, 11), // "totalUpTime"
QT_MOC_LITERAL(29, 366, 11), // "totalObject"
QT_MOC_LITERAL(30, 378, 10), // "totalValve"
QT_MOC_LITERAL(31, 389, 19), // "SetTemperatureTable"
QT_MOC_LITERAL(32, 409, 12), // "frontCamTemp"
QT_MOC_LITERAL(33, 422, 11), // "rearCamTemp"
QT_MOC_LITERAL(34, 434, 13), // "processorTemp"
QT_MOC_LITERAL(35, 448, 19), // "SetAirPressureTable"
QT_MOC_LITERAL(36, 468, 8), // "pressure"
QT_MOC_LITERAL(37, 477, 18), // "UpdateCameraStatus"
QT_MOC_LITERAL(38, 496, 5), // "error"
QT_MOC_LITERAL(39, 502, 22), // "UpdateSerialPortStatus"
QT_MOC_LITERAL(40, 525, 23), // "UpdateAirPressureStatus"
QT_MOC_LITERAL(41, 549, 18), // "UpdateModBusStatus"
QT_MOC_LITERAL(42, 568, 14), // "DisplayMessage"
QT_MOC_LITERAL(43, 583, 7), // "message"
QT_MOC_LITERAL(44, 591, 19), // "SetStartButtonState"
QT_MOC_LITERAL(45, 611, 4), // "stat"
QT_MOC_LITERAL(46, 616, 18), // "DisplayProgressBar"
QT_MOC_LITERAL(47, 635, 6), // "status"
QT_MOC_LITERAL(48, 642, 10), // "visibility"
QT_MOC_LITERAL(49, 653, 15), // "startBtnClicked"
QT_MOC_LITERAL(50, 669, 10), // "shutdownUI"
QT_MOC_LITERAL(51, 680, 8), // "rebootUI"
QT_MOC_LITERAL(52, 689, 8), // "closeApp"
QT_MOC_LITERAL(53, 698, 15), // "sendSortingType"
QT_MOC_LITERAL(54, 714, 14), // "setFeederSpeed"
QT_MOC_LITERAL(55, 729, 5), // "speed"
QT_MOC_LITERAL(56, 735, 13), // "setChuteTimer"
QT_MOC_LITERAL(57, 749, 13), // "shutDownChute"
QT_MOC_LITERAL(58, 763, 11), // "rebootChute"
QT_MOC_LITERAL(59, 775, 4), // "name"
QT_MOC_LITERAL(60, 780, 9), // "hourTimer"
QT_MOC_LITERAL(61, 790, 11) // "minuteTimer"

    },
    "UI\0ChuteStartButtonClicked\0\0id\0"
    "SystemShutDownRequest\0SystemRebootRequest\0"
    "sendSortingTypeRequest\0chuteID\0"
    "QList<QString>\0labels\0SetFeederSpeed\0"
    "feederSpeed\0SetElapsedTime\0hour\0minute\0"
    "ChuteShutdown\0ChuteReboot\0AddChute\0"
    "DeleteChute\0UpdateChart\0int64_t\0"
    "totalAccept\0totalEject\0ADDSortingType\0"
    "ClearAllSortingTypes\0UpdateElapsedTime\0"
    "elapsedTime\0UpdateTotalValues\0totalUpTime\0"
    "totalObject\0totalValve\0SetTemperatureTable\0"
    "frontCamTemp\0rearCamTemp\0processorTemp\0"
    "SetAirPressureTable\0pressure\0"
    "UpdateCameraStatus\0error\0"
    "UpdateSerialPortStatus\0UpdateAirPressureStatus\0"
    "UpdateModBusStatus\0DisplayMessage\0"
    "message\0SetStartButtonState\0stat\0"
    "DisplayProgressBar\0status\0visibility\0"
    "startBtnClicked\0shutdownUI\0rebootUI\0"
    "closeApp\0sendSortingType\0setFeederSpeed\0"
    "speed\0setChuteTimer\0shutDownChute\0"
    "rebootChute\0name\0hourTimer\0minuteTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       3,  308, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  179,    2, 0x06 /* Public */,
       4,    0,  182,    2, 0x06 /* Public */,
       5,    0,  183,    2, 0x06 /* Public */,
       6,    2,  184,    2, 0x06 /* Public */,
      10,    2,  189,    2, 0x06 /* Public */,
      12,    3,  194,    2, 0x06 /* Public */,
      15,    1,  201,    2, 0x06 /* Public */,
      16,    1,  204,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    1,  207,    2, 0x0a /* Public */,
      18,    1,  210,    2, 0x0a /* Public */,
      19,    2,  213,    2, 0x0a /* Public */,
      23,    2,  218,    2, 0x0a /* Public */,
      24,    0,  223,    2, 0x0a /* Public */,
      25,    2,  224,    2, 0x0a /* Public */,
      27,    3,  229,    2, 0x0a /* Public */,
      31,    4,  236,    2, 0x0a /* Public */,
      35,    1,  245,    2, 0x0a /* Public */,
      37,    2,  248,    2, 0x0a /* Public */,
      39,    2,  253,    2, 0x0a /* Public */,
      40,    2,  258,    2, 0x0a /* Public */,
      41,    1,  263,    2, 0x0a /* Public */,
      42,    1,  266,    2, 0x0a /* Public */,
      44,    2,  269,    2, 0x0a /* Public */,
      46,    2,  274,    2, 0x0a /* Public */,
      49,    1,  279,    2, 0x0a /* Public */,
      50,    0,  282,    2, 0x0a /* Public */,
      51,    0,  283,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      52,    0,  284,    2, 0x02 /* Public */,
      53,    2,  285,    2, 0x02 /* Public */,
      54,    2,  290,    2, 0x02 /* Public */,
      56,    3,  295,    2, 0x02 /* Public */,
      57,    1,  302,    2, 0x02 /* Public */,
      58,    1,  305,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    7,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,   13,   14,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 20,   21,   22,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int,    9,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    7,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   28,   29,   30,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,   32,   33,   34,
    QMetaType::Void, QMetaType::Int,   36,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,   38,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,   38,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,   38,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,   45,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   47,   48,
    QMetaType::Int, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    7,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,   55,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,   13,   14,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,

 // properties: name, type, flags
      59, QMetaType::QString, 0x00095103,
      60, QMetaType::QString, 0x00095003,
      61, QMetaType::QString, 0x00095003,

       0        // eod
};

void UI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ChuteStartButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SystemShutDownRequest(); break;
        case 2: _t->SystemRebootRequest(); break;
        case 3: _t->sendSortingTypeRequest((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2]))); break;
        case 4: _t->SetFeederSpeed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->SetElapsedTime((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->ChuteShutdown((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->ChuteReboot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->AddChute((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->DeleteChute((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->UpdateChart((*reinterpret_cast< int64_t(*)>(_a[1])),(*reinterpret_cast< int64_t(*)>(_a[2]))); break;
        case 11: _t->ADDSortingType((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->ClearAllSortingTypes(); break;
        case 13: _t->UpdateElapsedTime((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: _t->UpdateTotalValues((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 15: _t->SetTemperatureTable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 16: _t->SetAirPressureTable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->UpdateCameraStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: _t->UpdateSerialPortStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: _t->UpdateAirPressureStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: _t->UpdateModBusStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->DisplayMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->SetStartButtonState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 23: _t->DisplayProgressBar((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 24: { int _r = _t->startBtnClicked((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->shutdownUI(); break;
        case 26: _t->rebootUI(); break;
        case 27: _t->closeApp(); break;
        case 28: _t->sendSortingType((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2]))); break;
        case 29: _t->setFeederSpeed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 30: _t->setChuteTimer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 31: _t->shutDownChute((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->rebootChute((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UI::ChuteStartButtonClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UI::SystemShutDownRequest)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UI::SystemRebootRequest)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (UI::*)(int , QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UI::sendSortingTypeRequest)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (UI::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UI::SetFeederSpeed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (UI::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UI::SetElapsedTime)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (UI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UI::ChuteShutdown)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (UI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UI::ChuteReboot)) {
                *result = 7;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<UI *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->hourTimer(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->minuteTimer(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<UI *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->sethourTimer(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setminuteTimer(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject UI::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_UI.data,
    qt_meta_data_UI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UI.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void UI::ChuteStartButtonClicked(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UI::SystemShutDownRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void UI::SystemRebootRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void UI::sendSortingTypeRequest(int _t1, QList<QString> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void UI::SetFeederSpeed(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void UI::SetElapsedTime(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void UI::ChuteShutdown(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void UI::ChuteReboot(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
