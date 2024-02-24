#include "Rendererpch.h"
#include "ECSManager.h"

void SpriteRenderer::ECSManager::RemoveEntity(Entity ent)
{
	m_componentManager.EntityDestroyed(ent);
}
