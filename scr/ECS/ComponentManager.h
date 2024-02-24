#pragma once
#include"ECS/ComponentArray.h"
#include"Transform/Transoform.h"
#include"Sprite/Sprite.h"
namespace SpriteRenderer {
	using Entity = std::uint32_t;
	class ComponentManager
	{
	public:
		void FillComponentTypes()
		{
			m_componentHashes.insert({ typeid(Transform).name(), std::make_shared<ComponentArray<Transform>>() });

			m_componentHashes.insert({ typeid(Sprite).name(), std::make_shared<ComponentArray<Sprite>>()});

		}
		template<typename T>
		void AddComponent(Entity entity, T component);
		template<typename T>
		ComponentArray<T>& GetComponentArray();
		template<typename T>
		void RemoveComponent(Entity entity);
		template<typename T>
		T* GetComponent(Entity entity);
		void EntityDestroyed(Entity ent) {
			for (const auto& pair : m_componentHashes)
			{
				pair.second->OnEntityDestroyed(ent);
			}
		}
	private:
		std::unordered_map<const char *,std::shared_ptr<IComponentArray>> m_componentHashes{};
		std::uint32_t componentCount{};
	};

	template<typename T>
	inline void ComponentManager::AddComponent(Entity entity,T component)
	{
		GetComponentArray<T>().AddComponent(entity,component);
	}

	template<typename T>
	inline ComponentArray<T>& ComponentManager::GetComponentArray()
	{
		return std::static_pointer_cast<ComponentArray<T>(m_componentHashes[typeid(T)]);
	}


	template<typename T>
	inline void ComponentManager::RemoveComponent(Entity entity)
	{
		GetComponentArray().RemoveComponent(entity);
	}

	template<typename T>
	inline T* ComponentManager::GetComponent(Entity entity)
	{
		return GetComponentArray<T>().GetComponent(entity);
	}
}

