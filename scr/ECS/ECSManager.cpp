#include "Rendererpch.h"
#include "ECSManager.h"

void SpriteRenderer::ECSManager::RemoveEntity(ECSTypes::Entity ent)
{
	Instance.m_OnEntityDeletedEvent.Invoke();

	Instance.m_componentManager.EntityDestroyed(ent);
	Instance.m_EntityManager.DestroyEntity(ent);
}

void SpriteRenderer::ECSManager::DestroyECSManager()
{
	/*Instance.m_componentManager.DestroyComponentArrays();
	Instance.m_systemManager.DestroySystems();
	RENDER_LOG_MESSAGE_SUCCESS("Entity component system was manager destroyed successfully.");*/
}

void SpriteRenderer::ECSManager::destroy()
{
	this->m_componentManager.Destroy();
	this->m_systemManager.Destroy();
	RENDER_LOG_MESSAGE_SUCCESS("Entity component system was manager destroyed successfully.");
}