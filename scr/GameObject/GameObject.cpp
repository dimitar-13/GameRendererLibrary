#include"Rendererpch.h"
#include "GameObject.h"
#include"SceneManager/SceneManager.h"
SpriteRenderer::GameObject::GameObject(std::string objectName)
{
	SceneManager::GetGameObjectID(*this);
	this->transform = new Transform();
	SceneManager::RegisterComponent<Transform>(*this->transform, this->objectID);

	this->name = objectName;
}

SpriteRenderer::GameObject::~GameObject()
{
	delete(this->transform);
}
