#include "Rendererpch.h"
#include "CollisionDetection.h"
#include"Log/Log.h"
#include"Metric/MetricHelper.h"

SpriteRenderer::Collision SpriteRenderer::CollisionDetectionFuncs::TestForCollision(CircleCollider* circleCollider1, CircleCollider* circleCollider2, Transform* transformCollider1,
	Transform* transformCollider2)
{
	Collision result{};

	glm::vec2 CollisionNormal = transformCollider1->m_Position - transformCollider2->m_Position;
	if (glm::length(CollisionNormal) < MetricHelper::GetUnitInMeters(circleCollider1->m_radius) + MetricHelper::GetUnitInMeters(circleCollider2->m_radius))
	{
		result.CollisionNormal = glm::normalize(CollisionNormal);

		glm::vec2 PointA = result.CollisionNormal * MetricHelper::GetUnitInMeters(circleCollider1->m_radius);
		glm::vec2 PointB = -result.CollisionNormal * MetricHelper::GetUnitInMeters(circleCollider2->m_radius);
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
	glm::vec2 colider1Max = (transformCollider1->m_Position + 
		(METER_SCALE_FACTOR * transformCollider1->m_Scale / glm::vec2(2)));

	glm::vec2 colider2Max = (transformCollider2->m_Position + 
		(METER_SCALE_FACTOR * transformCollider2->m_Scale / glm::vec2(2)));

	glm::vec2 colider1Min = (transformCollider1->m_Position - 
		(METER_SCALE_FACTOR * transformCollider1->m_Scale / glm::vec2(2)));

	glm::vec2 colider2Min = (transformCollider2->m_Position - 
		(METER_SCALE_FACTOR * transformCollider2->m_Scale / glm::vec2(2)));


	bool colisionX = (colider1Max.x> colider2Min.x) &&
		(colider2Max.x > colider1Min.x);
	bool colisionY = (colider1Max.y > colider2Min.y) &&
		(colider2Max.y > colider1Min.y);

	if (colisionX && colisionY)
	{
		result.collider1 = SquareCollider1;
		result.collider2 = SquareCollider2;
		result.transformObj1 = transformCollider1;
		result.transformObj2 = transformCollider2;
		glm::vec2 CollisionNormal = glm::normalize(transformCollider1->m_Position - transformCollider2->m_Position);
		result.CollisionNormal = CollisionNormal;
		//If we consider a collider 1 to be a static collider we can generize 2 cases for either
		//working with the max value of the colliders or the min value of the colliders
		//kind of like if the collider is closer the max value or the min
		//using this knowage we can sort of deduce points A and B
		if (colider1Max.x > colider2Min.x || colider1Max.y < colider2Max.y)
		{
			glm::vec2 PointA(colider1Max * CollisionNormal);
			glm::vec2 PointB(colider2Max * CollisionNormal);

			result.distance = glm::length(PointA - PointB) / METER_SCALE_FACTOR;
		}
		else if (colider1Min.x < colider2Min.x || colider1Min.y > colider2Min.y)
		{	
			glm::vec2 PointA(colider2Min* CollisionNormal);

			glm::vec2 PointB(colider1Min* CollisionNormal);

			result.distance = (glm::length(PointA - PointB) / METER_SCALE_FACTOR);
		}

		
		//Small correction if its not present the collisides will be offseted more then they have to
		float bias = 0.63;

		//Instead of getting the lenght wich might be slower we can get
		//each component absolute values and compare the distace between the collision
		//normal axies *(You could use the dot product but this wont work if normal 
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
	//TODO:Implement circle suqare collision check

	return Collision{};
}
