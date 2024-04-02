#include "Rendererpch.h"
#include "CollisionDetection.h"
#include"Log.h"
#include"MetricHelper.h"

SpriteRenderer::Collision SpriteRenderer::CollisionDetectionFuncs::TestForCollision(CircleCollider* circleCollider1, CircleCollider* circleCollider2, Transform* transformCollider1,
	Transform* transformCollider2)
{
	Collision result{};

	// This vector points from the center of Collider 1 to the center of Collider 2.
	const glm::vec2 CollisionNormal = transformCollider1->m_Position - transformCollider2->m_Position;
	if (glm::length(CollisionNormal) < MetricHelper::GetUnitInMeters(circleCollider1->m_radius) + MetricHelper::GetUnitInMeters(circleCollider2->m_radius))
	{
		result.CollisionNormal = glm::normalize(CollisionNormal);

		//Scaling the normal collider we can get a point A that is lying on the collision normal.
		const glm::vec2 PointA = result.CollisionNormal * MetricHelper::GetUnitInMeters(circleCollider1->m_radius);
		//Scaling the normal collider we can get a point B that is lying on the collision normal.
		const glm::vec2 PointB = -result.CollisionNormal * MetricHelper::GetUnitInMeters(circleCollider2->m_radius);
		result.distance = glm::length(PointA - PointB) / METER_SCALE_FACTOR;

		result.collider1 = circleCollider1;
		result.collider2 = circleCollider2;
		result.transformObj1 = transformCollider1;
		result.transformObj2 = transformCollider2;
		result.isOverlap = true;
		circleCollider1->collisionState = (circleCollider1->m_isTrigger || circleCollider2->m_isTrigger)
		? COLLISION_STATE_TRIGGER_ENTER :
			COLLISION_STATE_COLLISION_ENTER;
		circleCollider2->collisionState = (circleCollider1->m_isTrigger || circleCollider2->m_isTrigger)
			? COLLISION_STATE_TRIGGER_ENTER :
			COLLISION_STATE_COLLISION_ENTER;

		return result;
	}
	circleCollider1->collisionState = (circleCollider1->m_isTrigger || circleCollider2->m_isTrigger)
		? COLLISION_STATE_TRIGGER_EXIT :
		COLLISION_STATE_COLLISION_EXIT;
	circleCollider2->collisionState = (circleCollider1->m_isTrigger || circleCollider2->m_isTrigger)
		? COLLISION_STATE_TRIGGER_EXIT :
		COLLISION_STATE_COLLISION_EXIT;
	return result;
}

SpriteRenderer::Collision SpriteRenderer::CollisionDetectionFuncs::TestForCollision(SquareCollider* SquareCollider1,SquareCollider* SquareCollider2, Transform* transformCollider1,
	Transform* transformCollider2)
{
	Collision result{};
	const glm::vec2 collider1Max = (transformCollider1->m_Position +
		(METER_SCALE_FACTOR * transformCollider1->m_Scale / glm::vec2(2)));

	const glm::vec2 collider2Max = (transformCollider2->m_Position +
		(METER_SCALE_FACTOR * transformCollider2->m_Scale / glm::vec2(2)));

	const glm::vec2 collider1Min = (transformCollider1->m_Position -
		(METER_SCALE_FACTOR * transformCollider1->m_Scale / glm::vec2(2)));

	const glm::vec2 collider2Min = (transformCollider2->m_Position -
		(METER_SCALE_FACTOR * transformCollider2->m_Scale / glm::vec2(2)));


	//Using AABB way to see if there is collision.

	const bool collisionX = (collider1Max.x> collider2Min.x) && (collider2Max.x > collider1Min.x);
	const bool collisionY = (collider1Max.y > collider2Min.y) && (collider2Max.y > collider1Min.y);

	if (collisionX && collisionY)
	{
		result.collider1 = SquareCollider1;
		result.collider2 = SquareCollider2;
		result.transformObj1 = transformCollider1;
		result.transformObj2 = transformCollider2;
		const glm::vec2 CollisionNormal = glm::normalize(transformCollider1->m_Position - transformCollider2->m_Position);
		result.CollisionNormal = CollisionNormal;
		//If we consider a collider 1 to be a static collider we can generalize  2 cases for either
		//working with the max value of the colliders or the min value of the colliders
		//kind of like if the collider is closer the max value or the min
		//using this knowledge we can sort of deduce points A and B.
		if (collider1Max.x > collider2Min.x || collider1Max.y < collider2Max.y)
		{
			glm::vec2 PointA(collider1Max * CollisionNormal);
			glm::vec2 PointB(collider2Max * CollisionNormal);

			result.distance = glm::length(PointA - PointB) / METER_SCALE_FACTOR;
		}
		else if (collider1Min.x < collider2Min.x || collider1Min.y > collider2Min.y)
		{	
			glm::vec2 PointA(collider2Min* CollisionNormal);

			glm::vec2 PointB(collider1Min* CollisionNormal);

			result.distance = (glm::length(PointA - PointB) / METER_SCALE_FACTOR);
		}

		
		//Small correction for the collision offset.
		constexpr float bias = 0.63;

		//Instead of getting the length which might be slower we can get
		//each component absolute values and compare the distance between the collision
		//normal axis (You could use the dot product but this wont work if normal 
		//vector is not in 1st quadrant since one of its component will be <0
		//leading to a negative value.
		if(std::abs(CollisionNormal.x) > std::abs(CollisionNormal.y))
			result.CollisionNormal = glm::vec2(CollisionNormal.x+ bias,0);
		else
			result.CollisionNormal = glm::vec2(0,CollisionNormal.y+ bias);

		SquareCollider1->collisionState = (SquareCollider1->m_isTrigger || SquareCollider2->m_isTrigger)
			? COLLISION_STATE_TRIGGER_ENTER :
			COLLISION_STATE_COLLISION_ENTER;
		SquareCollider2->collisionState = (SquareCollider1->m_isTrigger || SquareCollider2->m_isTrigger)
			? COLLISION_STATE_TRIGGER_ENTER :
			COLLISION_STATE_COLLISION_ENTER;

		result.isOverlap = true;

		return  result;
	}
	SquareCollider1->collisionState = (SquareCollider1->m_isTrigger || SquareCollider2->m_isTrigger)
		? COLLISION_STATE_TRIGGER_EXIT :
		COLLISION_STATE_COLLISION_EXIT;
	SquareCollider2->collisionState = (SquareCollider1->m_isTrigger || SquareCollider2->m_isTrigger)
		? COLLISION_STATE_TRIGGER_EXIT :
		COLLISION_STATE_COLLISION_EXIT;
	return Collision{};
}

SpriteRenderer::Collision SpriteRenderer::CollisionDetectionFuncs::TestForCollision(SquareCollider* SquareCollider1,CircleCollider* CircleCollider2, Transform* transformCollider1,
	Transform* transformCollider2)
{
	//TODO:Implement circle square collision check

	return Collision{};
}
