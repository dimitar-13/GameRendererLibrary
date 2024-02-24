#pragma once
#include"ECS/ComponentArray.h"
#include"ECS/ComponentManager.h"
#include"ECS/EntityManager.h"

namespace SpriteRenderer {
	class ECSManager {
	public:
		void Init();
		void RemoveEntity(Entity ent);
		template<typename T>
		void AddComponent(Entity ent);
		template<typename T>
		T* GetComponent(Entity ent);
		static ECSManager& GetInstance() { return Instance; }
	public:
		static ECSManager Instance;
	private:
		ComponentManager m_componentManager;
		EntityManager m_EntityManager;
	};
	template<typename T>
	inline void ECSManager::AddComponent(Entity ent)
	{
		m_componentManager.AddComponent<T>(ent,T {});
	}
	template<typename T>
	inline T* ECSManager::GetComponent(Entity ent)
	{
		return m_componentManager.GetComponent<T>(ent);
	}
	ECSManager ECSManager::Instance;
}