#pragma once
#include "Rendererpch.h"
#include "Transform/Transoform.h"

namespace SpriteRenderer {
	struct Collider;
	struct Collision
	{
		bool  isColliding = false;
		float distance = 0.0;
		glm::vec2 CollisionNormal;
		glm::vec2 PointA, PointB;
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