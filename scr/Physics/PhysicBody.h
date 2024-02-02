#pragma once
#include"Rendererpch.h"
namespace SpriteRenderer
{
	class PhysicBody
	{
	public:
		PhysicBody(glm::vec3* transformPos) { position = transformPos; };
		const  glm::vec3 GRAVITY_FORCE = glm::vec3(0,-9.81f,0);
		void AddForce(glm::vec3 force) { externalForce += force; }
		void UpdatePhysics(float delta);
	public:
		float mass;
		glm::vec3* position;
		bool useGravity = true;
	private:
		glm::vec3 velocity = glm::vec3(0);
		glm::vec3 acceleration = glm::vec3(0);
		glm::vec3 totalForce = glm::vec3(0);
		glm::vec3 externalForce = glm::vec3(0);
	};
}