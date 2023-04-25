#include "pch.h"
#include "Pressure.h"

Sketch::Pressure::Pressure(UInt16 systolic, UInt16 diastolic)
{
	_systolic = systolic;
	_diastolic = diastolic;
}

UInt16 Sketch::Pressure::Systolic::get()
{
	return _systolic;
}

UInt16 Sketch::Pressure::Diastolic::get()
{
	return _diastolic;
}


String^ Sketch::Pressure::ToString()
{
	return String::Format("{0}/{1}", _systolic, _diastolic);
}