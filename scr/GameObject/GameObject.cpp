#include"Rendererpch.h"
#include "GameObject.h"
#include"SceneManager/SceneManager.h"
SpriteRenderer::GameObject::GameObject(std::string objectName)
{
	SceneManager::GetGameObjectID(*this);
	SceneManager::RegisterComponent<Transform>(this->objectID);

	this->name = objectName;
}

SpriteRenderer::GameObject::~GameObject()
{
}
