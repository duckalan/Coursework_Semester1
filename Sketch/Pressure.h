#pragma once
using namespace System;

namespace Sketch 
{
	/// <summary>
	/// Давление пациента.
	/// </summary>
	[Serializable]
	public value class Pressure
	{
	private:
		/// <summary>
		/// Верхнее число, или систолическое артериальное давление в мм рт. ст.
		/// </summary>
		UInt16 _systolic;

		/// <summary>
		/// Нижнее число, или диастолическое артериальное давление в мм рт. ст.
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