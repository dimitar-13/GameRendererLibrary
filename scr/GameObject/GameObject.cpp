#include"Rendererpch.h"
#include "GameObject.h"
#include"Components/Transoform.h"
SpriteRenderer::GameObject::GameObject()
{
	this->m_entity = ECSManager::AddEntity();
	ECSManager::GetInstance().AddComponent<Transform>(this->m_entity);
}
