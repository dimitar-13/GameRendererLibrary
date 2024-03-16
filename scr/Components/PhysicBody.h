#pragma once
#include"Rendererpch.h"
namespace SpriteRenderer
{
	class PhysicWorld;
	class PhysicBody: public Component
	{
	public:
		float m_mass =.2f;
		bool m_useGravity = true;
		void AddForce(glm::vec2 force) { m_totalForce += force; }
	private:
		friend class PhysicWorld;
		glm::vec2 m_velocity = glm::vec2(0);
		glm::vec2 m_acceleration = glm::vec2(0);
		glm::vec2 m_totalForce = glm::vec2(0);
	};
}