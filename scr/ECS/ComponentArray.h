#pragma once
#include"Rendererpch.h"
#include"Component.h"
#include<array>
namespace SpriteRenderer {
	using ComponentType = std::uint8_t;
	const ComponentType MAX_COMPONENTS = 32;
	using Entity = std::uint32_t;

	class IComponentArray
	{
	public:
		void virtual OnEntityDestroyed(Entity ent) = 0;
		void virtual DestroyComponentArray() = 0;
	};

	template<typename T>
	struct ComponentArrayWrapper
	{
		std::array<T*, MAX_COMPONENTS> componentArray;
		uint32_t size = 0;
	};

	template<typename T>
	class ComponentArray:public IComponentArray
	{
	public:
		void RemoveComponent(Entity ent);
		void AddComponent(Entity ent);
		T* GetComponent(Entity ent);
		bool HasComponent(Entity ent);
		ComponentArrayWrapper<T>& GetArray() { return m_componentArray; }
		const std::vector<Entity> GetComponentEntities();
		void OnEntityDestroyed(Entity ent) override
		{
			if (m_entityToIndex.find(ent) != m_entityToIndex.end())
			{
				RemoveComponent(ent);
			}
		}
		void DestroyComponentArray()override {
			for (uint32_t i = 0; i < m_componentArray.size; i++)
			{
				delete(m_componentArray.componentArray[i]);
			}
			m_entityToIndex.clear();
			m_indexToEntity.clear();
		}
	private:
		ComponentArrayWrapper<T> m_componentArray;
		std::unordered_map< Entity, uint32_t> m_entityToIndex{};
		std::unordered_map< uint32_t ,Entity> m_indexToEntity{};
	};
	template<typename T>
	inline void ComponentArray<T>::RemoveComponent(Entity ent)
	{
		if (m_componentArray.size <= 1)
		{
			delete(m_componentArray.componentArray[0]);
			m_entityToIndex.erase(ent);
			m_indexToEntity.erase(m_componentArray.size);
			--m_componentArray.size;
			return;
		}
		uint32_t entityToRemoveIndex = m_entityToIndex[ent];
		uint32_t lastArrayComponentIndex =m_componentArray.size - 1;
		uint32_t lastEntity = m_indexToEntity[lastArrayComponentIndex];
		if (lastEntity == ent)
		{
			delete(m_componentArray.componentArray[entityToRemoveIndex]);
			m_componentArray.componentArray[lastArrayComponentIndex] = NULL;
			m_entityToIndex.erase(ent);
			m_indexToEntity.erase(lastArrayComponentIndex);
			--m_componentArray.size;
			return;
		}
		delete(m_componentArray.componentArray[entityToRemoveIndex]);
		m_componentArray.componentArray[entityToRemoveIndex] = m_componentArray.componentArray[lastArrayComponentIndex];

		m_indexToEntity[entityToRemoveIndex] = lastEntity;
		m_entityToIndex[lastEntity] = entityToRemoveIndex;
		m_componentArray.componentArray[lastArrayComponentIndex] = NULL;

		m_entityToIndex.erase(ent);
		m_indexToEntity.erase(lastArrayComponentIndex);
		--m_componentArray.size;
	}

	template<typename T>
	inline void ComponentArray<T>::AddComponent(Entity ent)
	{
		uint32_t index = m_componentArray.size;
		m_entityToIndex[ent] = index;
		m_indexToEntity[index] = ent;
		m_componentArray.componentArray[index] = new T();
		Component* componentCast = dynamic_cast<Component *> (m_componentArray.componentArray[index]);
		componentCast->entity = ent;
		m_componentArray.size++;
	}
	template<typename T>
	inline bool ComponentArray<T>::HasComponent(Entity ent)
	{
		if (m_entityToIndex.find(ent) != m_entityToIndex.end())
			return true;
		return false;
	}
	template<typename T>
	inline T* ComponentArray<T>::GetComponent(Entity ent)
	{
		if(m_entityToIndex.find(ent) != m_entityToIndex.end())
			return m_componentArray.componentArray[m_entityToIndex[ent]];
		return nullptr;
	}

	template<typename T>
	inline const std::vector<Entity> ComponentArray<T>::GetComponentEntities()
	{
		std::vector<Entity> result(m_indexToEntity.size());
		for (uint32_t i = 0; i < result.size(); i++)
		{
			result[i] = m_indexToEntity[i];
		}
		return result;
	}

}
