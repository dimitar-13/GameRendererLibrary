#pragma once
#include"Transform/Transoform.h"
#include"Sprite/Sprite.h"
#include<string>


//Can be named scene object
namespace SpriteRenderer {

	class GameObject;
	class SceneManager;

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
}