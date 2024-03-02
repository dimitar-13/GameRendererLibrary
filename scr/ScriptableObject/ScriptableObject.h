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
			GameObject gameObject;
			void BindScriptToEntity(Entity entity) { gameObject.m_entity = entity; }
	};

	

}