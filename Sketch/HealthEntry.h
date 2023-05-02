#pragma once
#include "Pressure.h"
#include "HealthState.h"
#include "TimePeriod.h"

using namespace System;
using namespace System::ComponentModel;

namespace Sketch
{
	/// <summary>
	/// Запись сведений о состоянии здоровья пациента.
	/// </summary>
	public ref class HealthEntry
	{
	public:
		HealthEntry(DateTime recordDate,
					Sketch::TimePeriod recordTimePeriod,
					Sketch::Pressure pressure,
					UInt16 pulse,
					Sketch::HealthState healthState,
					String^ remark);

		/// <summary>
		/// Примечание.
		/// </summary>
		[DisplayName("Примечание")]
		property String^ Remark;

		/// <summary>
		/// Пульс пациента.
		/// </summary>
		[DisplayName("Пульс")]
		property UInt16 Pulse;

		/// <summary>
		/// Давление пациента.
		/// </summary>
		[DisplayName("Давление")]
		property Sketch::Pressure Pressure;

		/// <summary>
		/// Общее состояние здоровья пациента.
		/// </summary>
		[DisplayName("Состояние здоровья")]
		property Sketch::HealthState HealthState;

		/// <summary>
		/// Период времени в момент, когда была сделана запись.
		/// </summary>
		[DisplayName("Период записи")]
		property TimePeriod RecordTimePeriod;

		/// <summary>
		/// Дата создания записи.
		/// </summary>
		[DisplayName("Дата записи")]
		property DateTime RecordDate;
	};
}