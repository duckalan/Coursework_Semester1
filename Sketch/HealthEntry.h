#pragma once
#include "Pressure.h"
#include "HealthState.h"
#include "TimePeriod.h"

using namespace System;

namespace Sketch
{
	/// <summary>
	/// ������ �������� � ��������� �������� ��������.
	/// </summary>
	public ref class HealthEntry
	{
	private:
		/// <summary>
		/// ���� �������� ������.
		/// </summary>
		DateTime _recordDate;

		/// <summary>
		/// ������ ������� � ������, ����� ���� ������� ������.
		/// </summary>
		TimePeriod _recordTimePeriod;

		/// <summary>
		/// �������� ��������.
		/// </summary>
		Sketch::Pressure _pressure;

		/// <summary>
		/// ����� ��������.
		/// </summary>
		UInt16 _pulse;

		/// <summary>
		/// ����� ��������� �������� ��������.
		/// </summary>
		HealthState _healthState;

		/// <summary>
		/// ����������.
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
		/// �������� ���� �������� ������.
		/// </summary>
		property DateTime RecordDate 
		{
			DateTime get();
		}

		/// <summary>
		/// �������� ������ ������� � ������, ����� ���� ������� ������.
		/// </summary>
		property TimePeriod RecordTimePeriod
		{
			TimePeriod get();
		}

		/// <summary>
		/// �������� �������� ��������.
		/// </summary>
		property Sketch::Pressure Pressure
		{
			Sketch::Pressure get();
		}

		/// <summary>
		/// �������� ����� ��������.
		/// </summary>
		property UInt16 Pulse
		{
			UInt16 get();
		}

		/// <summary>
		/// �������� ����� ��������� �������� ��������.
		/// </summary>
		property Sketch::HealthState HealthState
		{
			Sketch::HealthState get();
		}

		/// <summary>
		/// �������� ����������.
		/// </summary>
		property String^ Remark
		{
			String^ get();
		}
	};
}