#pragma once
#include"Rendererpch.h"
#include"Component.h"
namespace SpriteRenderer {
	//Component that describtes the obect position,rotation and scale in the world.
	struct Transform:public Component
	{
		//Adds the degrees to the overall degrees 
		void Rotate(float angle_in_degrees) { this->m_RotationAngle += angle_in_degrees; }
		void Translate(glm::vec2 position) { m_Position += position; }
		void Scale(glm::vec2 scale) { m_Scale += scale; }

		//Specifies the position of an object on the X and Y axies.
		glm::vec2 m_Position = glm::vec2(0);

		//glm::vec2 m_Rotate = glm::vec2(0);

		//Specifies the rotation of an object around the Z axies in degrees.
		float m_RotationAngle = 0.0f;

		//Specifies the scale of an object on the X and Y axies.
		glm::vec2 m_Scale = glm::vec2(1);
	};
#define Vector(x,y) glm::vec2(x,y)
}