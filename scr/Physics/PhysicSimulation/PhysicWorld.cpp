#include "Rendererpch.h"
#include "PhysicWorld.h"
#include"Log/Log.h"
#include"SceneManager/SceneManager.h"
#include"ECS/ECSManager.h"
#include"ColliderComponent.h"
void SpriteRenderer::PhysicWorld::ResolveColisions()
{
	for (std::uint32_t i = 0; i < this->collisions.size(); i++)
	{
		solver.SolveColision(this->collisions[i]);
	}
	this->collisions.clear();
}
void SpriteRenderer::PhysicWorld::ColisionCheck()
{

	for (std::uint32_t i = 0; i < m_CollisionEntities.size();i++)
	{
		auto* colliderComponent1 = ECSManager::GetComponent<ColliderComponent>(m_CollisionEntities[i]);
		auto* collider1Transform = ECSManager::GetComponent<Transform>(m_CollisionEntities[i]);

		for (std::uint32_t y = i+1; y < m_CollisionEntities.size(); y++)
		{
			auto* colliderComponent2 = ECSManager::GetComponent<ColliderComponent>(m_CollisionEntities[y]);
			auto* collider2Transform = ECSManager::GetComponent<Transform>(m_CollisionEntities[y]);
			//Get transform
			//I know its slow but cant think of better solution
			Collision collision = colliderComponent1->attachedCollider->TestForCollision(colliderComponent2->attachedCollider.get(), collider1Transform, collider2Transform);
			if (collision.isColliding)
			{
				this->collisions.push_back(collision);
				RENDER_LOG_MESSAGE_INFO("Colision");
			}
		}
	}
	ResolveColisions();
	
}

void SpriteRenderer::PhysicWorld::Init()
{
	this->m_entities = ECSManager::GetComponentEntities<PhysicBody>();
	this->m_CollisionEntities = ECSManager::GetComponentEntities<ColliderComponent>();
	for (std::uint32_t i = 0; i < m_CollisionEntities.size(); i++)
	{
		auto* colliderComponent1 = ECSManager::GetComponent<ColliderComponent>(m_CollisionEntities[i]);
		auto* collider1Transform = ECSManager::GetComponent<Transform>(m_CollisionEntities[i]);
		colliderComponent1->attachedCollider->m_Position = collider1Transform->m_Position;
	}
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
	ColisionCheck();
}

void SpriteRenderer::PhysicWorld::PostUpdate(float dt)
{
	for (std::uint32_t i = 0; i < m_CollisionEntities.size(); i++)
	{
		auto* colliderComponent1 = ECSManager::GetComponent<ColliderComponent>(m_CollisionEntities[i]);
		auto* collider1Transform = ECSManager::GetComponent<Transform>(m_CollisionEntities[i]);
		colliderComponent1->attachedCollider->m_Position = collider1Transform->m_Position;
	}
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
