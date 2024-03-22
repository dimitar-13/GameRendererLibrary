#include "Rendererpch.h"
#include "ECSManager.h"

void SpriteRenderer::ECSManager::RemoveEntity(ECSTypes::Entity ent)
{
	ECSManager insatnce = GetInstance();
	Instance.m_OnEntityDeletedEvent.Invoke();

	insatnce.m_componentManager.EntityDestroyed(ent);
	insatnce.m_EntityManager.DestroyEntity(ent);
}

void SpriteRenderer::ECSManager::DestroyECSManager()
{
	GetInstance().m_componentManager.DestroyComponentArrays();
	GetInstance().m_systemManager.DestroySystems();
	RENDER_LOG_MESSAGE_SUCCESS("Entity component system was manager destroyed successfully.");
}
