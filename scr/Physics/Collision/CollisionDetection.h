#pragma once
#include"Physics/Collision/Colider.h"
namespace SpriteRenderer {
	class CollisionDetection
	{
	public:
		static bool isCollidingSquare(const Collider& colider1, const Collider& colider2);
		//static bool isCollidingCircleSquare(const CircleCollider& colider1, const SquareCollider& colider2);
		static bool isColidingSAT(const Collider& colider1, const Collider& colider2);

	};
}

