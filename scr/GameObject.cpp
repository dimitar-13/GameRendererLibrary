#include"Rendererpch.h"
#include "GameObject.h"
#include"Components/Transoform.h"
#include"GameObjectRegister.h"
SpriteRenderer::GameObject::GameObject()
{
	this->m_entity = ECSManager::AddEntity();
	GameObjectRegister::RegisterGameObject(this);
	this->AttachComponent<Transform>();
}

void SpriteRenderer::GameObject::DestroyGameObject()
{
	ECSManager::RemoveEntity(this->m_entity);
	GameObjectRegister::UnRegisterGameObject(this->m_entity);
}
