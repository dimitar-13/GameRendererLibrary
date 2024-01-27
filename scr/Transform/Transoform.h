#pragma once

#include"Rendererpch.h"
namespace SpriteRenderer {
	enum Axies
	{
		AXIE_X = 0,
		AXIE_Y = 1,
		AXIE_Z = 2
	};

	class Transform
	{
	public:
		//Model matrix
		Transform();
		const glm::mat4& GetModelMatrix();
		void Rotate(float angle_in_degrees, Axies axie_to_roate);
		void Translate(float amount, Axies axie_to_move);
		void Scale(float amount, Axies axie_to_scale_along);

		glm::vec3 t_Position;

		glm::vec3 t_Rotate;

		glm::vec3 t_Scale;
	private:
		glm::mat4 modelMatrix;
	};
}