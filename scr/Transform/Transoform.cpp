#include"Rendererpch.h"
#include "Transoform.h"
#include"Metric/MetricHelper.h"
SpriteRenderer::Transform::Transform()
{
	this->m_modelMatrix = glm::mat4(1);
	this->m_Position = glm::vec3(0);
	this->m_Rotate = glm::vec3(0);
	this->m_Scale = glm::vec3(1);
}

const glm::mat4& SpriteRenderer::Transform::GetModelMatrix()
{
	this->m_modelMatrix = glm::mat4(1);
	this->m_modelMatrix = glm::translate(this->m_modelMatrix, glm::vec3(this->m_Position,0));

	this->m_modelMatrix = glm::rotate(this->m_modelMatrix, this->m_Rotate.x, glm::vec3(1.0f, 0, 0));
	this->m_modelMatrix = glm::rotate(this->m_modelMatrix, this->m_Rotate.y, glm::vec3(0, 1.0f, 0));

	this->m_modelMatrix = glm::scale(this->m_modelMatrix, glm::vec3(this->m_Scale, 0));
	return this->m_modelMatrix;
}

