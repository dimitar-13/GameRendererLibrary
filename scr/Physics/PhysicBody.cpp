#include "Rendererpch.h"
#include "PhysicBody.h"

void SpriteRenderer::PhysicBody::UpdatePhysics(glm::vec2* position,float delta)
{	
	this->m_totalForce = m_useGravity ? m_externalForce+ m_mass*GRAVITY_FORCE : m_externalForce;
	m_acceleration = m_totalForce / m_mass;
	m_velocity += (m_acceleration * delta);
	*position += delta * m_velocity;
	m_totalForce = glm::vec2(0);
}
