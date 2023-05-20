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
		/// »ндекс €чейки со значени€ми TimePeriod в DataGridView контрола EntryTableUserControl.
		/// </summary>
		static const int timePeriodCellIndex = 1;

		/// <summary>
		/// »ндекс €чейки со значени€ми HealthState в DataGridView контрола EntryTableUserControl.
		/// </summary>
		static const int healthStateCellIndex = 2;

		/// <summary>
		/// »ндекс €чейки со значени€ми pulse в DataGridView контрола EntryTableUserControl.
		/// </summary>
		static const int pulseCellIndex = 4;

	public:
		/// <returns>true, если значение €чейки TimePeriod в DataGridRow 
		/// не равно TimePeriod::”тро.</returns>
		static bool FilterByMorningPressure(DataGridViewCellCollection^ cells);
		
		/// <returns>true, если значение €чейки TimePeriod в DataGridRow 
		/// не равно TimePeriod::ƒень.</returns>
		static bool FilterByDayPressure(DataGridViewCellCollection^ cells);
		
		/// <returns>true, если значение €чейки TimePeriod в DataGridRow 
		/// не равно TimePeriod::¬ечер.</returns>
		static bool FilterByEveningPressure(DataGridViewCellCollection^ cells);
		
		/// <returns>true, если значение €чейки TimePeriod в DataGridRow 
		/// не равно TimePeriod::Ќочь.</returns>
		static bool FilterByNightPressure(DataGridViewCellCollection^ cells);
		
		/// <returns>true, если значение €чейки HealthState в DataGridRow 
		/// не равно TimePeriod::’орошо.</returns>
		static bool FilterByGoodHealthState(DataGridViewCellCollection^ cells);

		/// <returns>true, если значение €чейки HealthState в DataGridRow 
		/// не равно TimePeriod::”довлетворительно.</returns>
		static bool FilterBySatisfactoryHealthState(DataGridViewCellCollection^ cells);

		/// <returns>true, если значение €чейки HealthState в DataGridRow 
		/// не равно TimePeriod::Ќеудовлетворительно.</returns>
		static bool FilterByUnsatisfactoryHealthState(DataGridViewCellCollection^ cells);

		/// <returns>true, если значение €чейки pulse в DataGridRow меньше 120.</returns>
		static bool FilterByPulseHigher120(DataGridViewCellCollection^ cells);
	};
}