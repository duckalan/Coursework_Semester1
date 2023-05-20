#include "pch.h"
#include "FilterFunctions.h"
#include "FilterFunctions.h"

bool Sketch::FilterFunctions::FilterByMorningPressure(DataGridViewCellCollection^ cells)
{
	return !cells[timePeriodCellIndex]->Value->Equals(TimePeriod::����);
}

bool Sketch::FilterFunctions::FilterByDayPressure(DataGridViewCellCollection^ cells)
{
	return !cells[timePeriodCellIndex]->Value->Equals(TimePeriod::����);
}

bool Sketch::FilterFunctions::FilterByEveningPressure(DataGridViewCellCollection^ cells)
{
	return !cells[timePeriodCellIndex]->Value->Equals(TimePeriod::�����);
}

bool Sketch::FilterFunctions::FilterByNightPressure(DataGridViewCellCollection^ cells)
{
	return !cells[timePeriodCellIndex]->Value->Equals(TimePeriod::����);
}

bool Sketch::FilterFunctions::FilterByGoodHealthState(DataGridViewCellCollection^ cells)
{
	return !cells[healthStateCellIndex]->Value->Equals(HealthState::������);
}

bool Sketch::FilterFunctions::FilterBySatisfactoryHealthState(DataGridViewCellCollection^ cells)
{
	return !cells[healthStateCellIndex]->Value->Equals(HealthState::�����������������);
}

bool Sketch::FilterFunctions::FilterByUnsatisfactoryHealthState(DataGridViewCellCollection^ cells)
{
	return !cells[healthStateCellIndex]->Value->Equals(HealthState::�������������������);
}

bool Sketch::FilterFunctions::FilterByPulseHigher120(DataGridViewCellCollection^ cells)
{
	return (Byte)cells[pulseCellIndex]->Value < 120;
}
