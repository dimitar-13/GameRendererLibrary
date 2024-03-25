#pragma once
#include"ECS/ComponentArray.h"
#include"Component.h"
#include"Rendererpch.h"
#include"Log/Log.h"
namespace SpriteRenderer {
	class ComponentManager
	{
	public:
		//TODO:Should the user be able to say wich components they need
		//and is this unnecessary overhead.
	
		template<typename T, typename ...Ts>
		void RegisterComponentTypes();
		template<typename T>
		void AddComponent(ECSTypes::Entity entity);
		template<typename T>
		ComponentArray<T>& GetComponentArray();
		template<typename T>
		void RemoveComponent(ECSTypes::Entity entity);
		template<typename T>
		T* GetComponent(ECSTypes::Entity entity);
		template<typename T>
		bool HasComponent(ECSTypes::Entity ent);
		template<typename T>
		const std::vector<ECSTypes::Entity> GetComponentEntities();
		void EntityDestroyed(ECSTypes::Entity ent);
		void Destroy();
	private:
		std::unordered_map<const char *,std::shared_ptr<IComponentArray>> m_componentHashes{};
		std::uint32_t componentCount{};
	};

#pragma region Methods
	inline void ComponentManager::EntityDestroyed(ECSTypes::Entity ent) {
		for (const auto& pair : m_componentHashes)
		{
			pair.second->OnEntityDestroyed(ent);
		}
	}
	inline void ComponentManager::Destroy()
	{
		for (const auto& array : m_componentHashes)
		{
			array.second->DestroyComponentArray();
		}
		m_componentHashes.clear();
		RENDER_LOG_MESSAGE_SUCCESS("All component arrays were destroyed successfully.");
	}
#pragma endregion

#pragma region TemplatedMethods

	template<typename T, typename ...Ts>
	inline void ComponentManager::RegisterComponentTypes() {
		static_assert(std::is_base_of<Component, T>::value, "Class or struct must inherit from Component");
		m_componentHashes.insert({ typeid(T).name(), std::make_shared<ComponentArray<T>>() });
		if constexpr (sizeof...(Ts) > 0)
		{
			RegisterComponentTypes<Ts...>();
		}
	}

	template<typename T>
	inline void ComponentManager::AddComponent(ECSTypes::Entity entity)
	{
		GetComponentArray<T>().AddComponent(entity);
	}

	template<typename T>
	inline ComponentArray<T>& ComponentManager::GetComponentArray()
	{	
		return *std::static_pointer_cast<ComponentArray<T>>(m_componentHashes[typeid(T).name()]).get();
	}

	template<typename T>
	inline void ComponentManager::RemoveComponent(ECSTypes::Entity entity)
	{
		GetComponentArray<T>().RemoveComponent(entity);
	}

	template<typename T>
	inline T* ComponentManager::GetComponent(ECSTypes::Entity entity)
	{
		return GetComponentArray<T>().GetComponent(entity);
	}
	template<typename T>
	inline const std::vector<ECSTypes::Entity> ComponentManager::GetComponentEntities()
	{
		return GetComponentArray<T>().GetComponentEntities();
	}
	template<typename T>
	inline bool ComponentManager::HasComponent(ECSTypes::Entity ent)
	{
		return GetComponentArray<T>().HasComponent(ent);
	}
#pragma endregion
}

