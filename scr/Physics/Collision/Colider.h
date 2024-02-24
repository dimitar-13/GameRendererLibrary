#pragma once
#include "Rendererpch.h"
#include "Transform/Transoform.h"

namespace SpriteRenderer {
	struct Collision
	{
		bool isColliding = false;
		float distance = 0.0;
		glm::vec2 CollisionNormal;
		Transform* transformObj1;
		Transform* transformObj2;
	};
	struct CircleCollider;
	struct SquareCollider;
	struct Collider
	{
		glm::vec2 Position;
		bool isTrigger = false;
		Transform* transform;
		virtual Collision TestForCollision(Collider* collider) = 0;
		virtual Collision TestForCollision(CircleCollider* collider) = 0;
		virtual Collision TestForCollision(SquareCollider* collider) = 0;
		void UpdatePosition() { Position = transform->m_Position; }
	};
	struct CircleCollider : public Collider
	{
		float radius =0.5f;
		Collision TestForCollision(Collider* collider) override;
		Collision TestForCollision(CircleCollider* collider) override;
		Collision TestForCollision(SquareCollider* collider) override;
	};
	struct SquareCollider :public Collider {
		glm::vec2 max;
		glm::vec2 min;
		float width, height;
		Collision TestForCollision(Collider* collider) override;
		Collision TestForCollision(CircleCollider* collider)  {return{};}
		Collision TestForCollision(SquareCollider* collider) override;
		std::pair<glm::vec2, glm::vec2>GetMinAndMax() { std::make_pair(glm::vec2(0), glm::vec2(0)); }
	};
}