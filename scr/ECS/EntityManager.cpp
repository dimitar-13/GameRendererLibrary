#include "Rendererpch.h"
#include "EntityManager.h"

SpriteRenderer::EntityManager::EntityManager()
{
    for (uint32_t i = 0; i < ECSTypes::MAX_ENTITIES; i++)
    {
        m_entities.push(i);
    }
}

ECSTypes::Entity SpriteRenderer::EntityManager::CreateEntity()
{
    ECSTypes::Entity id = m_entities.front();
    m_entities.pop();
    ++m_entityCount;
    return id;
}

void SpriteRenderer::EntityManager::DestroyEntity(ECSTypes::Entity ent)
{
    m_entities.push(ent);
    --m_entityCount;
}

void SpriteRenderer::EntityManager::DestroyEntities()
{
   
    m_entityCount = 0;
}
