#include "Rendererpch.h"
#include "CollisionSytstem.h"
#include "ECSManager.h"
void SpriteRenderer::CollisionSystem::Init()
{
	m_entities = ECSManager::GetComponentEntities<ColliderComponent>();
	for (std::uint32_t i = 0; i < m_entities.size(); i++)
	{
		auto* colliderComponent1 = ECSManager::GetComponent<ColliderComponent>(m_entities[i]);
		auto* collider1Transform = ECSManager::GetComponent<Transform>(m_entities[i]);
		colliderComponent1->attachedCollider->m_Position = collider1Transform->m_Position;
	}
	const auto& onColliderArrayChangedFunc = std::bind(&CollisionSystem::OnColliderArrayChanged, this);
	ECSManager::AddEventListenerOnComponentArrayChange<ColliderComponent>(onColliderArrayChangedFunc);

}

void SpriteRenderer::CollisionSystem::PreUpdate(float dt)
{

}

void SpriteRenderer::CollisionSystem::Update(float dt)
{
	for (std::uint32_t i = 0; i < m_entities.size(); i++)
	{
		auto* colliderComponent1 = ECSManager::GetComponent<ColliderComponent>(m_entities[i]);
		auto* collider1Transform = ECSManager::GetComponent<Transform>(m_entities[i]);

		for (std::uint32_t y = i + 1; y < m_entities.size(); y++)
		{
			auto* colliderComponent2 = ECSManager::GetComponent<ColliderComponent>(m_entities[y]);
			auto* collider2Transform = ECSManager::GetComponent<Transform>(m_entities[y]);
			Collision collision = colliderComponent1->attachedCollider->TestForCollision(colliderComponent2->attachedCollider.get(), collider1Transform, collider2Transform);
			
			switch (colliderComponent1->attachedCollider->collisionState)
			{
			case COLLISION_STATE_COLLISION_ENTER:
				if(colliderComponent1->OnCollisionStart != NULL)
				colliderComponent1->OnCollisionStart(colliderComponent2);
				if(collision.isOverlap)
					this->collisions.push_back(collision);
				break;

			case COLLISION_STATE_COLLISION_EXIT:
				 if (colliderComponent1->OnCollisionExit != NULL)
					 colliderComponent1->OnCollisionExit(colliderComponent2);
				 
				 if (colliderComponent2->OnCollisionExit != NULL)
					colliderComponent2->OnCollisionExit(colliderComponent1);
				break;
			case COLLISION_STATE_TRIGGER_ENTER:
				if (colliderComponent1->OnTriggerStart != NULL)
					colliderComponent1->OnTriggerStart(colliderComponent2);

				if (colliderComponent2->OnTriggerStart != NULL)
					colliderComponent2->OnTriggerStart(colliderComponent1);
				break;
			case COLLISION_STATE_TRIGGER_EXIT:
				if (colliderComponent2->OnTriggerExit != NULL)
					colliderComponent2->OnTriggerExit(colliderComponent2);

				if (colliderComponent2->OnTriggerExit != NULL)
					colliderComponent2->OnTriggerExit(colliderComponent1);
				break;
			case COLLISION_STATE_COLLISION_NONE:

				break;
			default:
				break;
			}				
		}
	}
	ResolveCollisions();
}

void SpriteRenderer::CollisionSystem::PostUpdate(float dt)
{
	for (std::uint32_t i = 0; i < m_entities.size(); i++)
	{
		auto* colliderComponent1 = ECSManager::GetComponent<ColliderComponent>(m_entities[i]);
		auto* collider1Transform = ECSManager::GetComponent<Transform>(m_entities[i]);
		colliderComponent1->attachedCollider->m_Position = collider1Transform->m_Position;
	}
}

void SpriteRenderer::CollisionSystem::DestroySystem()
{
}
void SpriteRenderer::CollisionSystem::OnColliderArrayChanged()
{
	m_entities = ECSManager::GetComponentEntities<ColliderComponent>();
}
void SpriteRenderer::CollisionSystem::ResolveCollisions()
{
	for (std::uint32_t i = 0; i < this->collisions.size(); i++)
	{
		solver.SolveCollision(this->collisions[i]);
	}
	this->collisions.clear();
}

