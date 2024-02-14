#pragma once
#include"Physics/Collision/Colider.h"
namespace SpriteRenderer {
	namespace CollisionDetectionFuncs {

		    Collision TestForCollision(CircleCollider& collider1,
			 Transform& transform,
			 CircleCollider& collider2,
			 Transform& CircleTransform);

		    Collision TestForCollision(SquareCollider& collider1,
			 Transform& transform,
			 SquareCollider& collider2,
			 Transform& CircleTransform);

		    Collision TestForCollision(SquareCollider& collider1,
			 Transform& transform,
			 CircleCollider& collider2,
			 Transform& CircleTransform);
	}
}

