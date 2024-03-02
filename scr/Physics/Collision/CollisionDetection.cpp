#include "Rendererpch.h"
#include "CollisionDetection.h"
#include"Log/Log.h"
#include"Metric/MetricHelper.h"

SpriteRenderer::Collision SpriteRenderer::CollisionDetectionFuncs::TestForCollision(CircleCollider* circleCollider1, CircleCollider* CircleCollider2)											  
{
	Collision result{};

	glm::vec2 CollisionNormal = circleCollider1->m_Position - CircleCollider2->m_Position;
	if (glm::length(CollisionNormal) < circleCollider1->m_radius*METER_SCALE_FACTOR + CircleCollider2->m_radius* METER_SCALE_FACTOR)
	{
		result.isColliding = true;
		float distance = glm::length((CollisionNormal * glm::vec2(1/circleCollider1->m_radius)) + (CollisionNormal * glm::vec2(1/CircleCollider2->m_radius)));
		result.distance = glm::length(CollisionNormal);
		result.CollisionNormal = glm::normalize(CollisionNormal);
		result.transformObj1 = circleCollider1->transform;
		result.transformObj1 = CircleCollider2->transform;
		return result;
	}
	return result;
}

SpriteRenderer::Collision SpriteRenderer::CollisionDetectionFuncs::TestForCollision(SquareCollider* SquareCollider1,SquareCollider* SquareCollider2)
{
	/*if (SquareCollider1->Position == SquareCollider1->transform->m_Position &&
		SquareCollider2->Position == SquareCollider1->transform->m_Position)return Collision{};*/
	Collision result{};
	bool colisionX = (SquareCollider1->m_max.x > SquareCollider2->m_min.x) &&
		(SquareCollider2->m_max.x > SquareCollider1->m_min.x);

	bool colisionY = (SquareCollider1->m_max.y > SquareCollider2->m_min.y) &&
		(SquareCollider2->m_max.y > SquareCollider1->m_min.y);
	if (colisionX && colisionY)
	{
		result.isColliding = true;

		return  result;
	}
	return Collision{};
}

SpriteRenderer::Collision SpriteRenderer::CollisionDetectionFuncs::TestForCollision(SquareCollider* SquareCollider1,CircleCollider* CircleCollider2)																		
{
	return Collision{};
}
