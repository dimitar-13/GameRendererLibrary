#pragma once
#include"../../scr/Transform/Transoform.h"
#include"../../scr/Sprite/Sprite.h"
#include<string>

class GameObject;
class SceneManager;
//Can be named scene object
class ScriptableObject {

public:
	ScriptableObject() { };


protected:
	Transform* transform = 0;
	std::string name;
	Sprite* GetSprite() { return sprite; }
private:
	Sprite* sprite = 0;

private:
	friend class SceneManager;
	void AttachValuesFromGameObject(const GameObject& gameObj_to_attach);
	void DetachValuesFromGameObject();
};