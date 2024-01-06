#pragma once
#include"../../scr/Transform/Transoform.h"
#include"../../scr/Sprite/Sprite.h"
#include"../../scr/GameObject/GameObject.h"
#include<string>
//Can be named scene object
class ScriptableObject {

public:
	ScriptableObject(const GameObject& gameObj_to_attach);


protected:

	Transform* transform = 0;
	Sprite* sprite = 0;
	std::string name;
};