#include "pch.h"
#include "FilterFunctions.h"
#include "FilterFunctions.h"

bool Sketch::FilterFunctions::FilterByMorningPressure(DataGridViewCellCollection^ cells)
{
	return !cells[timePeriodCellIndex]->Value->Equals(TimePeriod::Утро);
}

bool Sketch::FilterFunctions::FilterByDayPressure(DataGridViewCellCollection^ cells)
{
	return !cells[timePeriodCellIndex]->Value->Equals(TimePeriod::День);
}

bool Sketch::FilterFunctions::FilterByEveningPressure(DataGridViewCellCollection^ cells)
{
	return !cells[timePeriodCellIndex]->Value->Equals(TimePeriod::Вечер);
}

bool Sketch::FilterFunctions::FilterByNightPressure(DataGridViewCellCollection^ cells)
{
	return !cells[timePeriodCellIndex]->Value->Equals(TimePeriod::Ночь);
}

bool Sketch::FilterFunctions::FilterByGoodHealthState(DataGridViewCellCollection^ cells)
{
	return !cells[healthStateCellIndex]->Value->Equals(HealthState::Хорошо);
}

bool Sketch::FilterFunctions::FilterBySatisfactoryHealthState(DataGridViewCellCollection^ cells)
{
	return !cells[healthStateCellIndex]->Value->Equals(HealthState::Удовлетворительно);
}

bool Sketch::FilterFunctions::FilterByUnsatisfactoryHealthState(DataGridViewCellCollection^ cells)
{
	return !cells[healthStateCellIndex]->Value->Equals(HealthState::Неудовлетворительно);
}

bool Sketch::FilterFunctions::FilterByPulseHigher120(DataGridViewCellCollection^ cells)
{
	return (Byte)cells[pulseCellIndex]->Value < 120;
}
