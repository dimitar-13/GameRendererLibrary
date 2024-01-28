#pragma once
namespace SpriteRenderer {

	class DeltaTime {
	public:
		DeltaTime(float time = 0.0f) :m_time(time){}

		float GetTimeInSeconds() { return m_time; }
	private:
		float m_time;
	};
};