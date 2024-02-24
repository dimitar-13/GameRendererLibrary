#include "Rendererpch.h"
#include "EntityManager.h"

SpriteRenderer::EntityManager::EntityManager()
{
    for (uint32_t i = 0; i < MAX_ENTITIES; i++)
    {
        m_entitites.push(i);
    }

}

Entity SpriteRenderer::EntityManager::CreateEntity()
{
    Entity id = m_entitites.front();
    m_entitites.pop();
    ++m_entityCount;
    return id;
}

void SpriteRenderer::EntityManager::DestroyEntity(Entity ent)
{
    m_entitites.push(ent);
    --m_entityCount;
}
