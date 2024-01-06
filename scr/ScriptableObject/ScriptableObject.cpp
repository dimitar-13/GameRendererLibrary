#include "ScriptableObject.h"


ScriptableObject::ScriptableObject(const GameObject& gameObj_to_attach)
{
	this->transform = gameObj_to_attach.transform;
	this->sprite = gameObj_to_attach.sprite;
	this->name = gameObj_to_attach.name;
}
