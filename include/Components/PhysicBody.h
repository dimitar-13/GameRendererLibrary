#pragma once
#include"Rendererpch.h"
#include"Component.h"
namespace SpriteRenderer
{
	class PhysicWorld;
	/// <summary>
	/// Component representing a physical body.
	/// </summary>
	class PhysicBody: public Component
	{
	public:
		//Mass of the physical body.
		float m_mass =.2f;
		//A way to set if physical body will effected by gravity.
		bool m_useGravity = true;
		//Adds force to the total force.
		void AddForce(glm::vec2 force) { m_totalForce += force; }
	private:
		friend class PhysicWorld;
		glm::vec2 m_velocity = glm::vec2(0);
		glm::vec2 m_acceleration = glm::vec2(0);
		glm::vec2 m_totalForce = glm::vec2(0);
	};
}