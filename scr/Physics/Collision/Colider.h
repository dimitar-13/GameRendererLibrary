#pragma once
#include "Rendererpch.h"
#include "Transform/Transoform.h"

namespace SpriteRenderer {

	struct Collision
	{
		bool isColliding = false;
		float distance = 0.0;
		glm::vec2 CollisionNormal;
	};

	struct Collider
	{
		glm::vec2 Position;
		bool isTrigger = false;
		virtual Collision TestForCollision(Transform& transform, Collider* collider,
								Transform& transform2) = 0;
		virtual Collision TestForCollision(Transform& transform,CircleCollider collider,
									  Transform& CircleTransform) = 0;
		virtual Collision TestForCollision(Transform& transform,SquareCollider collider,
									  Transform& SquareTransform) = 0;
	};
	struct CircleCollider : public Collider
	{
		float radius =0.5f;
		glm::vec2 originPosition;
		virtual Collision TestForCollision(Transform& transform, Collider* collider,
			Transform& transform2) override;
		Collision TestForCollision(Transform& transform, CircleCollider collider,
			Transform& CircleTransform) override;
		Collision TestForCollision(Transform& transform, SquareCollider collider,
			Transform& SquareTransform) override;
	};
	struct SquareCollider :public Collider {
		glm::vec2 max;
		glm::vec2 min;
		float width, height;
		virtual Collision TestForCollision(Transform& transform, Collider* collider,
			Transform& transform2) override;
		Collision TestForCollision(Transform& transform, CircleCollider collider,
			Transform& CircleTransform) {return{};}
		Collision TestForCollision(Transform& transform, SquareCollider collider,
			Transform& SquareTransform) override;
		std::pair<glm::vec2, glm::vec2>GetMinAndMax();
	};
}