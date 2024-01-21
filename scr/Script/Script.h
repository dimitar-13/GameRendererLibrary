#pragma once
#include"ScriptableObject/ScriptableObject.h"
#include<vector>

namespace SpriteRenderer {
	class SceneManager;

	class Script : public ScriptableObject
	{
	public:

		Script() { };
	protected:

		virtual void OnUpdate() { };
		virtual void OnStart() { };
		virtual void OnDelete() { };
		//void AttachScript(const GameObject& gameObj_to_attach);

		//Get transform	
		//Encapsolate the values ingeneral

	private:
		friend class SceneManager;
		//std::vector<GameObject*> attachedObjects;
		//void AttachScriptToObject(const GameObject& gameObj_to_attach) { this->AttachScriptToObject(gameObj_to_attach); }
		//void DetachScriptFromCurrentObj() { this->DetachValuesFromGameObject(); }

	};
}