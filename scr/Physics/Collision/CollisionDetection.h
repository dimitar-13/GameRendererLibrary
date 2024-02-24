#pragma once
#include"Physics/Collision/Colider.h"
namespace SpriteRenderer {
	namespace CollisionDetectionFuncs {

		    Collision TestForCollision(CircleCollider* collider1,
			 CircleCollider* collider2);

		    Collision TestForCollision(SquareCollider* collider1,
			 SquareCollider* collider2);

		    Collision TestForCollision(SquareCollider* collider1,
		    CircleCollider* collider2);
	}
}

