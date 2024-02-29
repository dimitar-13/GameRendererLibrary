#include"Rendererpch.h"
#include "GameObject.h"
#include"SceneManager/SceneManager.h"
#include"ECS/ECSManager.h"
SpriteRenderer::GameObject::GameObject()
{
	this->m_entity = ECSManager::AddEntity();
	ECSManager::GetInstance().AddComponent<Transform>(this->m_entity);
}
