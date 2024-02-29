#pragma once
#include"ECS/ComponentArray.h"
#include"Transform/Transoform.h"
#include"Sprite/Sprite.h"
#include"ScriptComponent.h"
#include"Physics/Collision/Colider.h"
#include"Physics/PhysicBody.h"
#include"Rendererpch.h"
namespace SpriteRenderer {
	using Entity = std::uint32_t;
	class ComponentManager
	{
	public:
		template<typename T, typename ...Ts>
		void RegisterComponentTypes() {
			m_componentHashes.insert({ typeid(T).name(), std::make_shared<ComponentArray<T>>() });
			if constexpr (sizeof...(Ts) > 0)
			{
				RegisterComponentTypes<Ts...>();
			}
		}

		void FillComponentTypes()
		{
			m_componentHashes.insert({ typeid(Transform).name(), std::make_shared<ComponentArray<Transform>>() });

			m_componentHashes.insert({ typeid(Sprite).name(), std::make_shared<ComponentArray<Sprite>>()});

			m_componentHashes.insert({ typeid(ScriptComponent).name(), std::make_shared<ComponentArray<ScriptComponent>>() });

			m_componentHashes.insert({ typeid(SquareCollider).name(), std::make_shared<ComponentArray<SquareCollider>>() });

			m_componentHashes.insert({ typeid(CircleCollider).name(), std::make_shared<ComponentArray<CircleCollider>>() });

			m_componentHashes.insert({ typeid(PhysicBody).name(), std::make_shared<ComponentArray<PhysicBody>>() });
		}
		template<typename T>
		void AddComponent(Entity entity);
		template<typename T>
		ComponentArray<T>& GetComponentArray();
		template<typename T>
		void RemoveComponent(Entity entity);
		template<typename T>
		T* GetComponent(Entity entity);
		template<typename T>
		const std::vector<Entity> GetComponentEntities();
		void EntityDestroyed(Entity ent) {
			for (const auto& pair : m_componentHashes)
			{
				pair.second->OnEntityDestroyed(ent);
			}
		}
		void DestroyComponentArrays()
		{
			for (const auto& array : m_componentHashes)
			{
				array.second->DestroyComponentArray();
			}
			m_componentHashes.clear();
		}

	private:
		std::unordered_map<const char *,std::shared_ptr<IComponentArray>> m_componentHashes{};
		std::uint32_t componentCount{};
	};

	template<typename T>
	inline void ComponentManager::AddComponent(Entity entity)
	{
		GetComponentArray<T>().AddComponent(entity);
	}

	template<typename T>
	inline ComponentArray<T>& ComponentManager::GetComponentArray()
	{	
		return *std::static_pointer_cast<ComponentArray<T>>(m_componentHashes[typeid(T).name()]).get();
	}

	template<typename T>
	inline void ComponentManager::RemoveComponent(Entity entity)
	{
		GetComponentArray<T>().RemoveComponent(entity);
	}

	template<typename T>
	inline T* ComponentManager::GetComponent(Entity entity)
	{
		return GetComponentArray<T>().GetComponent(entity);
	}
	template<typename T>
	inline const std::vector<Entity> ComponentManager::GetComponentEntities()
	{
		return GetComponentArray<T>().GetComponentEntities();
	}
}

