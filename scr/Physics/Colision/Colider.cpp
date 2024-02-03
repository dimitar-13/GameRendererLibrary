#include "Rendererpch.h"
#include "Colider.h"
#include"Metric/MetricHelper.h"
SpriteRenderer::Colider::Colider(Transform& objectTransform)
{
	this->originPosition = objectTransform.t_Position;
	this->width = objectTransform.t_Scale.x* METER_SCALE_FACTOR;
	this->height = objectTransform.t_Scale.y* METER_SCALE_FACTOR;

	this->max.x = this->originPosition.x +(this->width / 2);
	this->max.y = this->originPosition.y +(this->height/ 2);
	this->min.x = this->originPosition.x -(this->width / 2);
	this->min.y = this->originPosition.y -(this->height/ 2);

	//this->t = objectTransform.t_Scale;
	this->transform = &objectTransform;
}

void SpriteRenderer::Colider::UpdateTransfrom()
{
	this->originPosition = this->transform->t_Position;
	this->width = transform->t_Scale.x* METER_SCALE_FACTOR;
	this->height = transform->t_Scale.y* METER_SCALE_FACTOR;

	this->max.x = this->originPosition.x + (this->width / 2);
	this->max.y = this->originPosition.y + (this->height / 2);
	this->min.x = this->originPosition.x - (this->width / 2);
	this->min.y = this->originPosition.y - (this->height / 2);
	//this->scale = this->transform->t_Scale;
}