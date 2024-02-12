#pragma once
#include "Rendererpch.h"
#include "Transform/Transoform.h"
namespace SpriteRenderer {
	struct Collider
	{
		glm::vec2 lastPosition;
		glm::vec2 originPosition;
		glm::vec2 max;
		glm::vec2 min;
		float width, height;
		bool isTrigger = false;
		Transform* transform;
		Collider(Transform& objectTransform);
		void UpdateTransfrom();
	};
	struct CircleCollider
	{
		float radius;
		glm::vec2 originPosition;
		CircleCollider(Transform& transform);
	};
	//struct SquareCollider :public Collider {
	//	glm::vec2 max;
	//	glm::vec2 min;
	//	float width, height;
	//	SquareCollider(Transform& transform);
	//	std::pair<glm::vec2, glm::vec2>GetMinAndMax();
	//};



	struct Collision
	{
		Collider*colider1, *colider2;
		glm::vec2 CollisionNormal;

		void GetCollisionNormal()
		{
		
			CollisionNormal = glm::normalize(colider1->originPosition - colider2->originPosition);
		}

	};
}