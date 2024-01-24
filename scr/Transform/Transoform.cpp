#include"Rendererpch.h"
#include "Transoform.h"
SpriteRenderer::Transform::Transform()
{
	this->modelMatrix = glm::mat4(1);
	this->t_Position = glm::vec3(0);
	this->t_Rotate = glm::vec3(0);
	this->t_Scale = glm::vec3(1);
}

const glm::mat4& SpriteRenderer::Transform::GetModelMatrix()
{
	this->modelMatrix = glm::mat4(1);
	this->modelMatrix = glm::translate(this->modelMatrix, this->t_Position);

	this->modelMatrix = glm::rotate(this->modelMatrix, this->t_Rotate.x, glm::vec3(1.0f, 0, 0));
	this->modelMatrix = glm::rotate(this->modelMatrix, this->t_Rotate.y, glm::vec3(0, 1.0f, 0));
	this->modelMatrix = glm::rotate(this->modelMatrix, this->t_Rotate.z, glm::vec3(0, 0, 1.0f));

	this->modelMatrix = glm::scale(this->modelMatrix, this->t_Scale);
	//this->modelMatrix = glm::mat4(1);

	return this->modelMatrix;
}

void SpriteRenderer::Transform::Rotate(float angle_in_degrees, Axies axie_to_roate)
{
	switch (axie_to_roate)
	{
	case AXIE_X:
		this->t_Rotate = glm::vec3(angle_in_degrees, t_Rotate.y, t_Rotate.z);
		break;
	case AXIE_Y:
		this->t_Rotate = glm::vec3(t_Rotate.x, angle_in_degrees, t_Rotate.z);
		break;
	case AXIE_Z:
		this->t_Rotate = glm::vec3(t_Rotate.x, t_Rotate.y, angle_in_degrees);
		break;
	default:
		break;
	}
}

void SpriteRenderer::Transform::Translate(float amount, Axies axie_to_move)
{
	switch (axie_to_move)
	{
	case AXIE_X:
		this->t_Position = glm::vec3(amount, t_Position.y, t_Position.z);
		break;
	case AXIE_Y:
		this->t_Position = glm::vec3(t_Position.x, amount, t_Position.z);
		break;
	case AXIE_Z:
		this->t_Position = glm::vec3(t_Position.x,t_Position.y, amount);
		break;
	default:
		break;
	}
}

void SpriteRenderer::Transform::Scale(float amount, Axies axie_to_scale_along)
{
	switch (axie_to_scale_along)
	{
	case AXIE_X:
		this->t_Scale = glm::vec3(amount, t_Scale.y, t_Scale.z);
		break;
	case AXIE_Y:
		this->t_Scale = glm::vec3(t_Scale.x, amount, t_Scale.z);
		break;
	case AXIE_Z:
		this->t_Scale = glm::vec3(t_Scale.x, t_Scale.y, amount);
		break;
	default:
		break;
	}
}
