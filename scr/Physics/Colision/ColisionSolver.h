#pragma once
#include"Rendererpch.h"
#include"Physics/Colision/Colider.h"
namespace SpriteRenderer {
	class ColisionSolver
	{
	public:
		std::vector<Colision> colisions;
	public:
		void SolveColision(Colision colision);
		glm::vec2 FindColisionNormal(Colider colider1, Colider colider2);
	};
}
