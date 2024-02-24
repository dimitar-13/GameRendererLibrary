#pragma once
#include"Rendererpch.h"
//Can be named scene object
namespace SpriteRenderer {
	class SceneManager;
	class GameObject;
	class ScriptableObject {
	public:
		template<typename T>
		void AttachScript();
	protected:
		virtual void OnUpdate() { };
		virtual void OnStart() { };
		virtual void OnDelete() { };
		GameObject* gameObject;
		void BindScriptToObj(long long ID,GameObject& ref) { this->gameObjectID = ID; gameObject = &ref; }
	private:
		friend class SceneManager;
		long long gameObjectID = -1;
	};
}