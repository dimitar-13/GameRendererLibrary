#pragma once
#include"Rendererpch.h"
#include"Physics/Collision/Colider.h"
namespace SpriteRenderer {
	class ColisionSolver
	{
	public:
		std::vector<Collision> colisions;
	public:
		void SolveColision(Collision collision);
	};
}
