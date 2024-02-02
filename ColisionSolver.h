#pragma once
#include"Rendererpch.h"
#include"Physics/Colision/Colider.h"
namespace SpriteRenderer {
	class ColisionSolver
	{
	public:
		std::vector<Colision> colisions;
	public:
		void SolveForColiders();
	};
}
