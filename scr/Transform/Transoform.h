#pragma once

#include"Rendererpch.h"
namespace SpriteRenderer {

	class Transform
	{
	public:
		//Model matrix
		Transform();
		const glm::mat4& GetModelMatrix();
		void Rotate(glm::vec2 axie, float angle_in_degrees) { this->m_Rotate += (axie * angle_in_degrees); }
		void Translate(glm::vec2 position) { m_Position += position; }
		void Scale(glm::vec2 scale) { m_Scale += scale; };

		glm::vec2 m_Position;

		glm::vec2 m_Rotate;

		glm::vec2 m_Scale;
	private:
		glm::mat4 m_modelMatrix;
	};
#define Vector(x,y) glm::vec2(x,y)
}