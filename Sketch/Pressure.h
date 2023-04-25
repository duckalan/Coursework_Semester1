#pragma once
using namespace System;

namespace Sketch 
{
	/// <summary>
	/// �������� ��������.
	/// </summary>
	public value class Pressure
	{
	private:
		/// <summary>
		/// ������� �����, ��� ������������� ������������ �������� � �� ��. ��.
		/// </summary>
		UInt16 _systolic;

		/// <summary>
		/// ������ �����, ��� �������������� ������������ �������� � �� ��. ��.
		/// </summary>
		UInt16 _diastolic;

	public:
		Pressure(UInt16 systolic, UInt16 diastolic);

		property UInt16 Systolic {
			UInt16 get();
		}

		property UInt16 Diastolic {
			UInt16 get();
		}

		virtual String^ ToString() override;
	};
}