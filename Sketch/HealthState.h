#pragma once

namespace Sketch
{
	/// <summary>
	/// ������������ ��������.
	/// </summary>
	public enum class HealthState {
		/// <summary>
		/// ������.
		/// </summary>
		Good = 2,

		/// <summary>
		/// �����������������.
		/// </summary>
		Satisfactorily = 1,

		/// <summary>
		/// �������������������.
		/// </summary>
		Unsatisfactorily = 0
	};
}