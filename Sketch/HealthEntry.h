#pragma once
#include "Pressure.h"
#include "HealthState.h"
#include "TimePeriod.h"

using namespace System;

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
		/// Дата создания записи.
		/// </summary>
		property DateTime RecordDate;

		/// <summary>
		/// Период времени в момент, когда была сделана запись.
		/// </summary>
		property TimePeriod RecordTimePeriod;

		/// <summary>
		/// Давление пациента.
		/// </summary>
		property Sketch::Pressure Pressure;

		/// <summary>
		/// Пульс пациента.
		/// </summary>
		property UInt16 Pulse;

		/// <summary>
		/// Общее состояние здоровья пациента.
		/// </summary>
		property Sketch::HealthState HealthState;

		/// <summary>
		/// Примечание.
		/// </summary>
		property String^ Remark;
	};
}