#pragma once
namespace SpriteRenderer {


		static const float METER_SCALE_FACTOR = 100.0f; //1meter:100float
	class MetricHelper
	{
	public:
		static float GetUnitInMeters(float unitSize) { return unitSize / METER_SCALE_FACTOR; }
	};
}

