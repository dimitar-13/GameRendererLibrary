#include "Rendererpch.h"
#include "GameObjectRegister.h"
#include"GameObject/GameObject.h"


void SpriteRenderer::GameObjectRegister::RegisterGameObject(GameObject* gameObj)
{
	auto heapGameObject =std::make_shared<GameObject>(*gameObj);
	m_instance.m_gameObjectHash[gameObj->GetEntity()] = heapGameObject;
}

void SpriteRenderer::GameObjectRegister::UnRegisterGameObject(ECSTypes::Entity entity)
{
	if (m_instance.m_gameObjectHash.find(entity) != m_instance.m_gameObjectHash.end())
		m_instance.m_gameObjectHash.erase(entity);
}

