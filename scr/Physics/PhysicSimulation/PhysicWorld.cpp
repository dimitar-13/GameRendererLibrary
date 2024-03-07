#include "Rendererpch.h"
#include "PhysicWorld.h"
#include"Log/Log.h"
#include"SceneManager/SceneManager.h"
#include"ECS/ECSManager.h"
#include"ColliderComponent.h"
void SpriteRenderer::PhysicWorld::Init()
{
	this->m_entities = ECSManager::GetComponentEntities<PhysicBody>();
}

void SpriteRenderer::PhysicWorld::PreUpdate(float dt)
{
	this->m_entities = ECSManager::GetComponentEntities<PhysicBody>();
}

void SpriteRenderer::PhysicWorld::Update(float dt)
{
	for (uint32_t i =0; i< m_entities.size();i++)
	{
		auto* transform = ECSManager::GetComponent<Transform>(m_entities[i]);
		auto* physicBodie = ECSManager::GetComponent<PhysicBody>(m_entities[i]);
		UpdatePhysics(*physicBodie, &transform->m_Position, dt);
	}
}

void SpriteRenderer::PhysicWorld::PostUpdate(float dt)
{
	//Dependencie between collisionSystem and PhysicsSystem
}

void SpriteRenderer::PhysicWorld::DestroySystem()
{
}

void SpriteRenderer::PhysicWorld::UpdatePhysics(PhysicBody& physicBodie,
	glm::vec2* physicBodiePosition, float delta)
{
	glm::vec2 totalForce = physicBodie.m_useGravity ? physicBodie.m_totalForce + GRAVITY_FORCE : physicBodie.m_totalForce;
	physicBodie.m_acceleration = totalForce / physicBodie.m_mass;
	physicBodie.m_velocity += (physicBodie.m_acceleration * delta);
	*physicBodiePosition += delta * physicBodie.m_velocity;
	physicBodie.m_totalForce = glm::vec2(0);
}
