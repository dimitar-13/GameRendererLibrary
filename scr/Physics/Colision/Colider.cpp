#include "Rendererpch.h"
#include "Colider.h"
SpriteRenderer::Colider::Colider(Transform& objectTransform)
{
	this->originPosition = objectTransform.t_Position;
	this->width = objectTransform.t_Scale.x;
	this->height = objectTransform.t_Scale.y;

	//this->t = objectTransform.t_Scale;
	this->transform = &objectTransform;
}

void SpriteRenderer::Colider::UpdateTransfrom()
{
	this->originPosition = this->transform->t_Position;
	this->width = transform->t_Scale.x;
	this->height = transform->t_Scale.y;
	//this->scale = this->transform->t_Scale;
}