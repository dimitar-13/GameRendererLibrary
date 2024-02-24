#pragma once
#include"Rendererpch.h"
namespace SpriteRenderer
{
	class PhysicBody
	{
	public:
		PhysicBody(glm::vec2* transformPos) { position = transformPos; }
		const  glm::vec2 GRAVITY_FORCE = glm::vec2(0,-9.81f);
		void AddForce(glm::vec2 force) { externalForce += force; }
		void UpdatePhysics(float delta);
	public:
		float mass;
		glm::vec2* position;
		bool useGravity = true;
	private:
		glm::vec2 velocity = glm::vec2(0);
		glm::vec2 acceleration = glm::vec2(0);
		glm::vec2 totalForce = glm::vec2(0);
		glm::vec2 externalForce = glm::vec2(0);
	};
}