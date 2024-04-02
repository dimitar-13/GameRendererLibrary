#pragma once
#include"Rendererpch.h"
#include"Colider.h"
namespace SpriteRenderer {
	//Helper class for collision resolution.
	class CollisionSolver
	{
	public:
		std::vector<Collision> collisions;
	public:
		/// <summary>
		/// Solves the collision using the 'Collision' struct.
		/// </summary>
		/// <param name="collision">The collision to solve.</param>
		void SolveCollision(Collision collision);
	};
}
