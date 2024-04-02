#pragma once
#include"Colider.h"
namespace SpriteRenderer {
	namespace CollisionDetectionFuncs {

		    Collision TestForCollision(CircleCollider* collider1,
			 CircleCollider* collider2, Transform* transformCollider1,
				Transform* transformCollider2);

		    Collision TestForCollision(SquareCollider* collider1,
			 SquareCollider* collider2, Transform* transformCollider1,
				Transform* transformCollider2);

		    Collision TestForCollision(SquareCollider* collider1,
		    CircleCollider* collider2, Transform* transformCollider1,
				Transform* transformCollider2);
	}
}

