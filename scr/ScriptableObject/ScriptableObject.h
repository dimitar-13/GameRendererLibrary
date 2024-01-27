#pragma once
#include"Rendererpch.h"
#include"SceneManager/SceneManager.h"
//Can be named scene object
namespace SpriteRenderer {

	class ScriptableObject {

	public:
		ScriptableObject() { };


	protected:
		Transform& GetTransform() { return SceneManager::GetTransformByObjectID(gameObjectID); }
		//Transform* transform = 0;
		
		//std::string name;
		Sprite& GetSprite() { return SceneManager::GetSpriteByObjectID(gameObjectID); }

		GameObject* gameObject;
		void BindScriptToObj(long long ID) { this->gameObjectID = ID; gameObject = &SceneManager::GetGameObjectByID(gameObjectID); }
	private:
		friend class SceneManager;
		long long gameObjectID = -1;
		//void AttachValuesFromGameObject(const GameObject& gameObj_to_attach);
		//void Instanciate(GameObject& gameobj) { this->instance = &gameobj; }
	};
}