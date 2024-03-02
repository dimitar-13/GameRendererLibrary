#pragma once
#include"Rendererpch.h"
namespace SpriteRenderer
{
	class PhysicBody
	{
	public:
		const  glm::vec2 GRAVITY_FORCE = glm::vec2(0,-9.81f);
		void AddForce(glm::vec2 force) { m_externalForce += force; }
		void UpdatePhysics(glm::vec2* position,float delta);
	public:
		float m_mass;
		bool m_useGravity = true;
	private:
		glm::vec2 m_velocity = glm::vec2(0);
		glm::vec2 m_acceleration = glm::vec2(0);
		glm::vec2 m_totalForce = glm::vec2(0);
		glm::vec2 m_externalForce = glm::vec2(0);
	};
}