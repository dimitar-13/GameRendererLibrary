#pragma once
#include"Rendererpch.h"
#include"ECS/ECSTypes.h"
#include"Log.h"
namespace SpriteRenderer {
#define MAX_GAME_OBJECTS 15
	class GameObject;
	class GameObjectRegister {
	public:
		static void RegisterGameObject(GameObject *gameObj);
		static void UnRegisterGameObject(ECSTypes::Entity entity);
		static GameObject* GetGameObjRef(ECSTypes::Entity entity) { return m_instance.m_gameObjectHash.at(entity).get(); }
	private:
		static GameObjectRegister m_instance;
	private:
		std::unordered_map < ECSTypes::Entity, std::shared_ptr<GameObject>> m_gameObjectHash;
	};
	inline GameObjectRegister GameObjectRegister::m_instance;
}