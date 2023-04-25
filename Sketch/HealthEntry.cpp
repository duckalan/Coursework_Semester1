#include "pch.h"
#include "HealthEntry.h"
using namespace Sketch;

HealthEntry::HealthEntry(DateTime recordDate,
                         Sketch::TimePeriod recordTimePeriod, 
                         Sketch::Pressure pressure,
                         UInt16 pulse,
                         Sketch::HealthState healthState,
                         String^ remark)
{
    _recordDate = recordDate;
    _recordTimePeriod = recordTimePeriod;
    _pressure = pressure;
    _pulse = pulse;
    _healthState = healthState;
    _remark = remark;
}


DateTime HealthEntry::RecordDate::get()
{
    return _recordDate;
}

TimePeriod HealthEntry::RecordTimePeriod::get()
{
    return _recordTimePeriod;
}

Pressure HealthEntry::Pressure::get()
{
    return _pressure;
}

UInt16 HealthEntry::Pulse::get()
{
    return _pulse;
}

HealthState HealthEntry::HealthState::get()
{
    return _healthState;
}

String^ HealthEntry::Remark::get()
{
    return _remark;
}
