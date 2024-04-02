#pragma once
#include"ComponentArray.h"
#include"ComponentManager.h"
#include"EntityManager.h"
#include"EventSystem.h"
#include"SystemManager.h"
#include"Log.h"
namespace SpriteRenderer {
	//Class that communicates with the ECS parts.
	class ECSManager {
	public:
		static ECSTypes::Entity AddEntity() {return Instance.m_EntityManager.CreateEntity(); }
		static void RemoveEntity(ECSTypes::Entity ent);
		template<typename T>
		static void AddComponent(ECSTypes::Entity ent);
		template<typename T>
		static void RemoveComponent(ECSTypes::Entity ent);
		template<typename T>
		static T *const GetComponent(ECSTypes::Entity ent);
		template<typename T>
		static bool HasComponent(ECSTypes::Entity ent);
		template<typename T>
		static inline ComponentArrayWrapper<T>& GetComponentArray() { return Instance.m_componentManager.GetComponentArray<T>().GetArray(); }
		template<typename T>
		static const std::vector<ECSTypes::Entity> GetComponentEntities();
		template<typename T>
		static void RegisterSystem();
		static SystemManager& GetSystemManager() { return Instance.m_systemManager; }
		static void DestroyECSManager();
		static ComponentManager& GetComponentManager() { return Instance.m_componentManager; }
		template<typename T>
		static void AddEventListenerOnComponentArrayChange(const std::function<void()>& listener) { Instance.m_componentManager.GetComponentArray<T>().AddEventListener(listener); }
		static void AddEventListenerOnEntityDeletion(const std::function<void()>&listener) { Instance.m_OnEntityDeletedEvent += listener; }
		static void Destroy() { Instance.destroy(); }
		void destroy();
	private:
		ComponentManager m_componentManager;
		EntityManager m_EntityManager;
		SystemManager m_systemManager;
		Event<void> m_OnEntityDeletedEvent;
		static ECSManager Instance;

	};
#pragma region Templated methods
	template<typename T>
	inline void ECSManager::AddComponent(ECSTypes::Entity ent)
	{
		Instance.m_componentManager.AddComponent<T>(ent);
	}
	template<typename T>
	inline void ECSManager::RemoveComponent(ECSTypes::Entity ent) {
		Instance.m_componentManager.RemoveComponent<T>(ent);
	}
	template<typename T>
	inline T *const ECSManager::GetComponent(ECSTypes::Entity ent)
	{
		return Instance.m_componentManager.GetComponent<T>(ent);
	}
	template<typename T>
	inline const std::vector<ECSTypes::Entity> ECSManager::GetComponentEntities()
	{
		return Instance.m_componentManager.GetComponentEntities<T>();
	}
	template<typename T>
	inline bool ECSManager::HasComponent(ECSTypes::Entity ent)
	{
		return Instance.m_componentManager.HasComponent<T>(ent);
	}
	template<typename T>
	inline void ECSManager::RegisterSystem()
	{
		Instance.m_systemManager.RegisterSystem<T>();
		RENDER_LOG_MESSAGE_INFO("System of type {0} was initialized successfully.",typeid(T).name());
	}
	inline ECSManager ECSManager::Instance;
#pragma endregion

}