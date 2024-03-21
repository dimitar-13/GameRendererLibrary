#pragma once
#include"ECS/ComponentArray.h"
#include"ECS/ComponentManager.h"
#include"ECS/EntityManager.h"
#include"ECS/EventSystem/EntityEventSystem.h"
#include"ECS/SystemManager.h"
#include"Log/Log.h"
namespace SpriteRenderer {
	class ECSManager {
	public:
		static ECSTypes::Entity AddEntity() {return GetInstance().m_EntityManager.CreateEntity(); }
		static void RemoveEntity(ECSTypes::Entity ent);
		template<typename T>
		static void AddComponent(ECSTypes::Entity ent);
		template<typename T>
		static void RemoveComponent(ECSTypes::Entity ent);
		template<typename T>
		static T* GetComponent(ECSTypes::Entity ent);
		template<typename T>
		static bool HasComponent(ECSTypes::Entity ent);
		template<typename T>
		static inline ComponentArrayWrapper<T>& GetComponentArray() { return GetInstance().m_componentManager.GetComponentArray<T>().GetArray(); }
		template<typename T>
		static const std::vector<ECSTypes::Entity> GetComponentEntities();
		static ECSManager& GetInstance() { return Instance; }
		template<typename T,typename... Ts>
		static void RegisterSystem(Ts ...components);
		static SystemManager& GetSystemManager() { return GetInstance().m_systemManager; }
		static void DestroyECSManager();
		static ComponentManager& GetComponentManager() { return GetInstance().m_componentManager; }
	public:
		static ECSManager Instance;
	private:
		ComponentManager m_componentManager;
		EntityManager m_EntityManager;
		SystemManager m_systemManager;
	};
	template<typename T>
	inline void ECSManager::AddComponent(ECSTypes::Entity ent)
	{
		GetInstance().m_componentManager.AddComponent<T>(ent);
	}
	template<typename T>
	inline void ECSManager::RemoveComponent(ECSTypes::Entity ent) {
		GetInstance().m_componentManager.RemoveComponent<T>(ent);
	}
	template<typename T>
	inline T* ECSManager::GetComponent(ECSTypes::Entity ent)
	{
		return GetInstance().m_componentManager.GetComponent<T>(ent);
	}
	template<typename T>
	inline const std::vector<ECSTypes::Entity> ECSManager::GetComponentEntities()
	{
		return GetInstance().m_componentManager.GetComponentEntities<T>();
	}
	template<typename T>
	inline bool ECSManager::HasComponent(ECSTypes::Entity ent)
	{
		return GetInstance().m_componentManager.HasComponent<T>(ent);
	}
	template<typename T, typename... Ts>
	inline void ECSManager::RegisterSystem(Ts ...components)
	{
		GetInstance().m_systemManager.RegisterSystem<T>(components...);
		RENDER_LOG_MESSAGE_INFO("System of type {0} was initialized successfully.",typeid(T).name());
	}
	inline ECSManager ECSManager::Instance;
}