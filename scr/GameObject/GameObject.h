#pragma once
#include"../../scr/Transform/Transoform.h"
#include"../../scr/Sprite/Sprite.h"
#include"../../scr/Script/Script.h"
#include<string>
#include<vector>
#include"../../Core/Global.h"

class SceneManager;


class GameObject
{
public:
	GameObject(std::string objectName,  Sprite* sprite = 0);
	~GameObject();
	std::string name;
	std::vector<Script*> attachedScripts;

protected:
	friend class ScriptableObject;
	Transform* transform = 0;
	Sprite* sprite = 0;

private:
	friend class SceneManager;
	
};