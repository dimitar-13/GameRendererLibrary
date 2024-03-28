#pragma once
#include "Rendererpch.h"
#include "Components/Transoform.h"

namespace SpriteRenderer {
	//Enumerator representing collision state.
	enum CollisionState {
		COLLISION_STATE_COLLISION_NONE,
		COLLISION_STATE_COLLISION_ENTER,
		COLLISION_STATE_COLLISION_EXIT,
		COLLISION_STATE_TRIGGER_ENTER,
		COLLISION_STATE_TRIGGER_EXIT
	};

	struct Collider;
	//Class representing collision between 2 colliders.
	struct Collision
	{
		//If they overlap.
		float isOverlap= false;
		//The distance between the intersection points A and B, where A is on collider 1 and B is on collider 2.
		float distance = 0.0;
		//The direction of the collision intersection.
		glm::vec2 CollisionNormal;
		Transform* transformObj1;
		Transform* transformObj2;
		Collider* collider1;
		Collider* collider2;
	};
	struct CircleCollider;
	struct SquareCollider;

	//Base collider class representing common collider attributes.
	struct Collider
	{
		// Represents the position of the collider in world space.
		glm::vec2 m_Position;

		// Holds the current collision state of the collider.
		CollisionState collisionState = COLLISION_STATE_COLLISION_NONE;

		// Determines whether collision resolution should be ignored.
		// If true, this collider acts as a trigger and does not resolve collisions.
		bool m_isTrigger = false;

		virtual Collision TestForCollision(Collider* collider, Transform* callerTransform,
			Transform* toBeTestedTransform) = 0;
		virtual Collision TestForCollision(CircleCollider* collider, Transform* callerTransform,
			Transform* toBeTestedTransform) = 0;
		virtual Collision TestForCollision(SquareCollider* collider, Transform* callerTransform,
			Transform* toBeTestedTransform) = 0;
	};
	//Derived collider class representing a circle collider.
	struct CircleCollider : public Collider
	{
		float m_radius =0.5f;
		Collision TestForCollision(Collider* collider, Transform* callerTransform,
			Transform* toBeTestedTransform) override;
		Collision TestForCollision(CircleCollider* collider, Transform* callerTransform,
			Transform* toBeTestedTransform) override;
		Collision TestForCollision(SquareCollider* collider, Transform* callerTransform,
			Transform* toBeTestedTransform) override;
	};
	//Derived collider class representing a square collider.
	struct SquareCollider :public Collider {
		glm::vec2 m_max, m_min;
		float m_width, m_height;
		Collision TestForCollision(Collider* collider, Transform* callerTransform,
			Transform* toBeTestedTransform) override;
		Collision TestForCollision(CircleCollider* collider, Transform* callerTransform,
			Transform* toBeTestedTransform)  {return{};}
		Collision TestForCollision(SquareCollider* collider, Transform* callerTransform,
			Transform* toBeTestedTransform) override;
		std::pair<glm::vec2, glm::vec2>GetMinAndMax() { return std::pair(m_min, m_max); }
	};
}