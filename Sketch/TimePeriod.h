#pragma once

using namespace System;

namespace Sketch
{
	/// <summary>
	/// Период времени, когда была создана запись давления.
	/// </summary>
	[Serializable]
	public enum class TimePeriod
	{
		// Используются русские названия, потому что
		// парсить и биндить их гораздо проще

		Утро,

		День,

		Вечер,

		Ночь
	};
}