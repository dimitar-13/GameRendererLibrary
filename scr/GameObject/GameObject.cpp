#include "GameObject.h"

GameObject::GameObject(std::string objectName, Sprite* sprite)
{
	this->transform = new Transform();
	this->sprite = sprite;
	this->name = objectName;
}

GameObject::~GameObject()
{
	delete(this->transform);
	delete(this->sprite);
}
