#include "Rendererpch.h"
#include "PhysicBody.h"

void SpriteRenderer::PhysicBody::UpdatePhysics(glm::vec2* position,float delta)
{	
	this->totalForce = useGravity ? externalForce+ mass*GRAVITY_FORCE : externalForce;
	acceleration = totalForce / mass;
	velocity += (acceleration * delta);
	*position += delta * velocity;
	totalForce = glm::vec2(0);
}
