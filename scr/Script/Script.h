#pragma once
#include"Rendererpch.h"
#include"ScriptableObject/ScriptableObject.h"

namespace SpriteRenderer {
	class Script : public ScriptableObject
	{
	public:

		Script() { };
		//long long gameObjID = -1;
	protected:

		virtual void OnUpdate() { };
		virtual void OnStart() { };
		virtual void OnDelete() { };

	private:
		friend class SceneManager;
		void BindScript(long long GameObjectID) {this->BindScriptToObj(GameObjectID);}

	};
}