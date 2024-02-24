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

SpriteRenderer::Collision SpriteRenderer::CircleCollider::TestForCollision(Collider* collider)
{
	return collider->TestForCollision(this);
}

SpriteRenderer::Collision SpriteRenderer::CircleCollider::TestForCollision(CircleCollider* CircleCollider2)
{
	return CollisionDetectionFuncs::TestForCollision(this,
											CircleCollider2);
}

SpriteRenderer::Collision SpriteRenderer::CircleCollider::TestForCollision(SquareCollider* SquareCollider)
{
	return CollisionDetectionFuncs::TestForCollision(SquareCollider,this);
}

SpriteRenderer::Collision SpriteRenderer::SquareCollider::TestForCollision(Collider* collider)
{
	return collider->TestForCollision(this);
}

SpriteRenderer::Collision SpriteRenderer::SquareCollider::TestForCollision(SquareCollider* SquareCollider2)
{
	return CollisionDetectionFuncs::TestForCollision(this,SquareCollider2);
}
