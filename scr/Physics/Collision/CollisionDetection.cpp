#include "Rendererpch.h"
#include "CollisionDetection.h"
#include"Log/Log.h"
#include"Metric/MetricHelper.h"

SpriteRenderer::Collision SpriteRenderer::CollisionDetectionFuncs::TestForCollision(CircleCollider* circleCollider1, CircleCollider* CircleCollider2, Transform* transformCollider1,
	Transform* transformCollider2)
{
	Collision result{};

	glm::vec2 CollisionNormal = transformCollider1->m_Position - transformCollider2->m_Position;
	if (glm::length(CollisionNormal) < MetricHelper::GetUnitInMeters(circleCollider1->m_radius) + MetricHelper::GetUnitInMeters(CircleCollider2->m_radius))
	{
		result.isColliding = true;
		result.PointA = (glm::normalize(CollisionNormal) * MetricHelper::GetUnitInMeters(circleCollider1->m_radius))-glm::vec2(0);
		result.PointB = (glm::normalize(transformCollider2->m_Position - transformCollider1->m_Position) * MetricHelper::GetUnitInMeters(CircleCollider2->m_radius)) - glm::vec2(0);
		float distance = glm::length(result.PointA - result.PointB)/100.0f;
		result.distance = distance;
		result.CollisionNormal = glm::normalize(CollisionNormal);
		result.collider1 = circleCollider1;
		result.collider2 = CircleCollider2;
		result.transformObj1 = transformCollider1;
		result.transformObj2 = transformCollider2;
		return result;
	}
	return result;
}

SpriteRenderer::Collision SpriteRenderer::CollisionDetectionFuncs::TestForCollision(SquareCollider* SquareCollider1,SquareCollider* SquareCollider2, Transform* transformCollider1,
	Transform* transformCollider2)
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

SpriteRenderer::Collision SpriteRenderer::CollisionDetectionFuncs::TestForCollision(SquareCollider* SquareCollider1,CircleCollider* CircleCollider2, Transform* transformCollider1,
	Transform* transformCollider2)
{
	return Collision{};
}
