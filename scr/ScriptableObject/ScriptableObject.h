#pragma once
#include"Rendererpch.h"
#include"GameObject/GameObject.h"
//Can be named scene object
namespace SpriteRenderer {
	class ScriptSystem;
	class ScriptComponent;

	class ScriptableObject {
		protected:
			friend class ScriptComponent;
			friend class ScriptSystem;

			virtual void OnUpdate() { };
			virtual void OnStart() { };
			virtual void OnDelete() { };
			//TODO:Fix the callbacks maybe use func pointers
			const GameObject *const GetGameObject() const { return this->gameObject; }
		private:
			friend class ScriptComponent;
			void BindScript(const GameObject * gameObj) { gameObject = gameObj; }
			const GameObject * gameObject;
	};

	

}