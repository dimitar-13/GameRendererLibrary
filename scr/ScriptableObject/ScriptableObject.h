#pragma once
#include"Rendererpch.h"
#include"SceneManager/SceneManager.h"
//Can be named scene object
namespace SpriteRenderer {

	class ScriptableObject {
	public:
		template<typename T>
		void AttachScript();
	protected:
		virtual void OnUpdate() { };
		virtual void OnStart() { };
		virtual void OnDelete() { };
		template<typename T>
		T* GetComponent() { return SceneManager::GetGameObjectComponent<T>(this->gameObjectID); }
		GameObject* gameObject;
		void BindScriptToObj(long long ID) { this->gameObjectID = ID; gameObject = &SceneManager::GetGameObjectByID(gameObjectID); }
	private:
		friend class SceneManager;
		long long gameObjectID = -1;
	};
}