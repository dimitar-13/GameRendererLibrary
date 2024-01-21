#include "ScriptableObject.h"
#include "GameObject/GameObject.h"

void SpriteRenderer::ScriptableObject::AttachValuesFromGameObject(const GameObject& gameObj_to_attach)
{
	this->transform = gameObj_to_attach.transform;
	this->sprite = gameObj_to_attach.sprite;
	this->name = gameObj_to_attach.name;
}

void SpriteRenderer::ScriptableObject::DetachValuesFromGameObject()
{
	this->transform = 0;
	this->sprite = 0;
	this->name = " ";
}
