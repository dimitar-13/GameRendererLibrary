#pragma once
#include"../../scr/Transform/Transoform.h"
#include"../../scr/Sprite/Sprite.h"
#include<string>
#include"vector"
class GameObject
{
public:
	GameObject(std::string objectName);
	~GameObject();
	std::string name;
protected:
	friend class ScriptableObject;
	Transform* transform = 0;
	Sprite* sprite = 0;


};