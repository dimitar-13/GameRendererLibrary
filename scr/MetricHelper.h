#pragma once
#include"Rendererpch.h"
namespace SpriteRenderer {

	const float METER_SCALE_FACTOR = 100.0f; //1unit:100float
	//Wrapper for metric related calls.
	class MetricHelper
	{
	public:
		//Gets convers the unitSize into meter size.
		static float GetUnitInMeters(float unitSize) { return unitSize * METER_SCALE_FACTOR; }
	};
}

