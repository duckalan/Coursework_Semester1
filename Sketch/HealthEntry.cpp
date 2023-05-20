#include "pch.h"
#include "HealthEntry.h"
using namespace Sketch;

HealthEntry::HealthEntry(DateTime recordDate,
                         Sketch::TimePeriod recordTimePeriod, 
                         Sketch::Pressure pressure,
                         Byte pulse,
                         Sketch::HealthState healthState,
                         String^ remark)
{
    RecordDate = recordDate;
    RecordTimePeriod = recordTimePeriod;
    Pressure = pressure;
    Pulse = pulse;
    HealthState = healthState;
    Remark = remark;
}