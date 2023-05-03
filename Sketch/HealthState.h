#pragma once

namespace Sketch
{
	/// <summary>
	/// Самочувствие пациента.
	/// </summary>
	[Serializable]
	public enum class HealthState 
	{
		// Используются русские названия, потому что
		// парсить и биндить их гораздо проще
		Хорошо,

		Удовлетворительно,

		Неудовлетворительно 
	};
}