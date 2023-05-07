#pragma once
#include "TimePeriod.h"
#include "HealthState.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Sketch;

namespace Sketch 
{
	ref class FilterFunctions
	{
	private:
		/// <summary>
		/// ������ ������ �� ���������� TimePeriod � DataGridView �������� EntryTableUserControl.
		/// </summary>
		static const int timePeriodCellIndex = 1;

		/// <summary>
		/// ������ ������ �� ���������� HealthState � DataGridView �������� EntryTableUserControl.
		/// </summary>
		static const int healthStateCellIndex = 2;

		/// <summary>
		/// ������ ������ �� ���������� pulse � DataGridView �������� EntryTableUserControl.
		/// </summary>
		static const int pulseCellIndex = 4;

	public:
		/// <returns>true, ���� �������� ������ TimePeriod � DataGridRow 
		/// �� ����� TimePeriod::����.</returns>
		static bool FilterByMorningPressure(DataGridViewCellCollection^ cells);
		
		/// <returns>true, ���� �������� ������ TimePeriod � DataGridRow 
		/// �� ����� TimePeriod::����.</returns>
		static bool FilterByDayPressure(DataGridViewCellCollection^ cells);
		
		/// <returns>true, ���� �������� ������ TimePeriod � DataGridRow 
		/// �� ����� TimePeriod::�����.</returns>
		static bool FilterByEveningPressure(DataGridViewCellCollection^ cells);
		
		/// <returns>true, ���� �������� ������ TimePeriod � DataGridRow 
		/// �� ����� TimePeriod::����.</returns>
		static bool FilterByNightPressure(DataGridViewCellCollection^ cells);
		
		/// <returns>true, ���� �������� ������ HealthState � DataGridRow 
		/// �� ����� TimePeriod::������.</returns>
		static bool FilterByGoodHealthState(DataGridViewCellCollection^ cells);

		/// <returns>true, ���� �������� ������ HealthState � DataGridRow 
		/// �� ����� TimePeriod::�����������������.</returns>
		static bool FilterBySatisfactoryHealthState(DataGridViewCellCollection^ cells);

		/// <returns>true, ���� �������� ������ HealthState � DataGridRow 
		/// �� ����� TimePeriod::�������������������.</returns>
		static bool FilterByUnsatisfactoryHealthState(DataGridViewCellCollection^ cells);

		/// <returns>true, ���� �������� ������ pulse � DataGridRow ������ 120.</returns>
		static bool FilterByPulseHigher120(DataGridViewCellCollection^ cells);
	};
}