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
	private:
		/// <summary>
		/// Дата создания записи.
		/// </summary>
		DateTime _recordDate;

		/// <summary>
		/// Период времени в момент, когда была сделана запись.
		/// </summary>
		TimePeriod _recordTimePeriod;

		/// <summary>
		/// Давление пациента.
		/// </summary>
		Sketch::Pressure _pressure;

		/// <summary>
		/// Пульс пациента.
		/// </summary>
		UInt16 _pulse;

		/// <summary>
		/// Общее состояние здоровья пациента.
		/// </summary>
		HealthState _healthState;

		/// <summary>
		/// Примечание.
		/// </summary>
		String^ _remark;

	public:
		HealthEntry(DateTime recordDate,
					Sketch::TimePeriod recordTimePeriod,
					Sketch::Pressure pressure,
					UInt16 pulse,
					Sketch::HealthState healthState,
					String^ remark);

		/// <summary>
		/// Получить дату создания записи.
		/// </summary>
		property DateTime RecordDate 
		{
			DateTime get();
		}

		/// <summary>
		/// Получить период времени в момент, когда была сделана запись.
		/// </summary>
		property TimePeriod RecordTimePeriod
		{
			TimePeriod get();
		}

		/// <summary>
		/// Получить давление пациента.
		/// </summary>
		property Sketch::Pressure Pressure
		{
			Sketch::Pressure get();
		}

		/// <summary>
		/// Получить пульс пациента.
		/// </summary>
		property UInt16 Pulse
		{
			UInt16 get();
		}

		/// <summary>
		/// Получить общее состояние здоровья пациента.
		/// </summary>
		property Sketch::HealthState HealthState
		{
			Sketch::HealthState get();
		}

		/// <summary>
		/// Получить примечание.
		/// </summary>
		property String^ Remark
		{
			String^ get();
		}
	};
}