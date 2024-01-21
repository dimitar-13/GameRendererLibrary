#pragma once
#include"Transform/Transoform.h"
#include"Sprite/Sprite.h"
#include"Script/Script.h"
#include<string>
#include<vector>
#include"../../Core/Global.h"


namespace SpriteRenderer
{
	class SceneManager;

	class GameObject
	{
	public:
		GameObject(std::string objectName, Sprite* sprite = 0);
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
}