#include "GameObject.h"

GameObject::GameObject(std::string objectName)
{
	this->transform = new Transform();
	this->sprite = new Sprite();
	this->name = objectName;
}

GameObject::~GameObject()
{
	
	delete(this->transform);
	delete(this->sprite);
}
