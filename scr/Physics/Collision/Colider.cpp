#include "Rendererpch.h"
#include "Colider.h"
#include"Metric/MetricHelper.h"
SpriteRenderer::Collider::Collider(Transform& objectTransform)
{
	this->originPosition = objectTransform.m_Position;
	this->transform = &objectTransform;
	this->width = transform->m_Scale.x * METER_SCALE_FACTOR;
	this->height = transform->m_Scale.y * METER_SCALE_FACTOR;
	this->max.x = this->originPosition.x + (this->width / 2);
	this->max.y = this->originPosition.y + (this->height / 2);
	this->min.x = this->originPosition.x - (this->width / 2);
	this->min.y = this->originPosition.y - (this->height / 2);
}

void SpriteRenderer::Collider::UpdateTransfrom()
{
	this->lastPosition = this->originPosition;
	this->originPosition = this->transform->m_Position;
	this->width = transform->m_Scale.x * METER_SCALE_FACTOR;
	this->height = transform->m_Scale.y * METER_SCALE_FACTOR;
	this->max.x = this->originPosition.x + (this->width / 2);
	this->max.y = this->originPosition.y + (this->height / 2);
	this->min.x = this->originPosition.x - (this->width / 2);
	this->min.y = this->originPosition.y - (this->height / 2);
}

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
