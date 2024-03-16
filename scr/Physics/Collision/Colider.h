#pragma once
#include "Rendererpch.h"
#include "Components/Transoform.h"

namespace SpriteRenderer {
	enum CollisionState {
		COLLISION_STATE_COLLISION_NONE,
		COLLISION_STATE_COLLISION_ENTER,
		COLLISION_STATE_COLLISION_EXIT,
		COLLISION_STATE_TRIGGER_ENTER,
		COLLISION_STATE_TRIGGER_EXIT
	};

	struct Collider;
	struct Collision
	{
		float isOverlap= false;
		float distance = 0.0;
		glm::vec2 CollisionNormal;
		//glm::vec2 PointA, PointB;
		Transform* transformObj1;
		Transform* transformObj2;
		Collider* collider1;
		Collider* collider2;
	};
	struct CircleCollider;
	struct SquareCollider;
	struct Collider
	{
		glm::vec2 m_Position;
		CollisionState collisionState = COLLISION_STATE_COLLISION_NONE;
		bool m_isTrigger = false;
		virtual Collision TestForCollision(Collider* collider, Transform* callerTransform,
			Transform* toBeTestedTransform) = 0;
		virtual Collision TestForCollision(CircleCollider* collider, Transform* callerTransform,
			Transform* toBeTestedTransform) = 0;
		virtual Collision TestForCollision(SquareCollider* collider, Transform* callerTransform,
			Transform* toBeTestedTransform) = 0;
	};
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