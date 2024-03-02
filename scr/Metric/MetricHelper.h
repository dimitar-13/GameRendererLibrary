#pragma once
#include"Rendererpch.h"
namespace SpriteRenderer {

	const float METER_SCALE_FACTOR = 100.0f; //1unit:100float

	class MetricHelper
	{
	public:
		static float GetUnitInMeters(float unitSize) { return unitSize * METER_SCALE_FACTOR; }
	};
}

