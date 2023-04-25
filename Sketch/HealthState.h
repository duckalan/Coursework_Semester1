#pragma once

namespace Sketch
{
	/// <summary>
	/// Самочувствие пациента.
	/// </summary>
	public enum class HealthState {
		/// <summary>
		/// Хорошо.
		/// </summary>
		Good = 2,

		/// <summary>
		/// Удовлетворительно.
		/// </summary>
		Satisfactorily = 1,

		/// <summary>
		/// Неудовлетворительно.
		/// </summary>
		Unsatisfactorily = 0
	};
}