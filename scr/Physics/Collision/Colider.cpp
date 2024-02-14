#include "Rendererpch.h"
#include "Colider.h"
#include"Metric/MetricHelper.h"
#include "Physics/Collision/CollisionDetection.h" 

//SpriteRenderer::SquareCollider::SquareCollider(Transform& transform):Collider(transform)
//{
//	this->width = transform.m_Scale.x * METER_SCALE_FACTOR;
//	this->height = transform.m_Scale.y * METER_SCALE_FACTOR;
//}
//
//std::pair<glm::vec2, glm::vec2> SpriteRenderer::SquareCollider::GetMinAndMax()
//{
//	this->max.x = this->originPosition.x + (this->width / 2);
//	this->max.y = this->originPosition.y + (this->height / 2);
//	this->min.x = this->originPosition.x - (this->width / 2);
//	this->min.y = this->originPosition.y - (this->height / 2);
//
//	return std::pair<glm::vec2, glm::vec2>(max, min);
//}
//
//SpriteRenderer::CircleCollider::CircleCollider(Transform& transform):Collider(transform)
//{
//	this->radius = 1 * METER_SCALE_FACTOR;
//}

SpriteRenderer::Collision SpriteRenderer::CircleCollider::TestForCollision(Transform& transform, Collider* collider, Transform& transform2)
{
	return collider->TestForCollision(transform, this, transform2);
}

SpriteRenderer::Collision SpriteRenderer::CircleCollider::TestForCollision(Transform& CircleCollider1transform,
	CircleCollider CircleCollider2,
	Transform& CircleColliderTransform2)
{
	return CollisionDetectionFuncs::TestForCollision(*this, CircleCollider1transform, 
											CircleCollider2, CircleColliderTransform2);
}

SpriteRenderer::Collision SpriteRenderer::CircleCollider::TestForCollision(Transform& CircleColliderTransform1,
	SquareCollider SquareCollider,
	Transform& SquareColliderTransform)
{
	return CollisionDetectionFuncs::TestForCollision(SquareCollider, SquareColliderTransform,*this, CircleColliderTransform1);
}

SpriteRenderer::Collision SpriteRenderer::SquareCollider::TestForCollision(Transform& transform, Collider* collider, Transform& transform2)
{
	return collider->TestForCollision(transform,this, transform2);
}

SpriteRenderer::Collision SpriteRenderer::SquareCollider::TestForCollision(Transform& SquareCollider1transform,
	SquareCollider SquareCollider2,
	Transform& SquareCollider2Transform)
{
	return CollisionDetectionFuncs::TestForCollision(*this, SquareCollider1transform, SquareCollider2, SquareCollider2Transform);
}
