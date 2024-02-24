#pragma once
#include"Rendererpch.h"
#include<array>
namespace SpriteRenderer {
	using ComponentType = std::uint8_t;
	const ComponentType MAX_COMPONENTS = 32;
	using Entity = std::uint32_t;

	class IComponentArray
	{
	public:
		void virtual OnEntityDestroyed(Entity ent) = 0;
	};


	template<typename T>
	class ComponentArray:public IComponentArray
	{
	public:
		void RemoveComponent(Entity ent);
		void AddComponent(Entity ent, T component);
		T* GetComponent(Entity ent);
		void OnEntityDestroyed(Entity ent) override
		{
			if (m_entityToIndex.find(ent) != m_entityToIndex.end())
			{
				RemoveComponent(ent);
			}
		}
	private:
		std::array<T, MAX_COMPONENTS> m_componentArray;

		std::unordered_map< Entity, uint32_t> m_entityToIndex{};
		std::unordered_map<  uint32_t ,Entity> m_indexToEntity{};
		uint32_t m_ComponentCount = 0;
	};
	template<typename T>
	inline void ComponentArray<T>::RemoveComponent(Entity ent)
	{
		uint32_t entityToRemoveIndex = m_entityToIndex[ent];
		uint32_t lastArrayComponentIndex = m_ComponentCount - 1;
		m_componentArray[entityToRemoveIndex] = m_componentArray[lastArrayComponentIndex];

		m_indexToEntity[entityToRemoveIndex] = m_entityToIndex[lastArrayComponentIndex];
		m_entityToIndex[lastArrayComponentIndex] = entityToRemoveIndex;

		m_entityToIndex.erase(ent);
		m_indexToEntity.erase(lastArrayComponentIndex);
		--m_ComponentCount;
	}

	template<typename T>
	inline void ComponentArray<T>::AddComponent(Entity ent,T component)
	{
		uint32_t index = m_ComponentCount;
		m_entityToIndex[ent] = index;
		m_indexToEntity[index] = ent;
		m_componentArray[index] = component;
		++m_ComponentCount;
	}

	template<typename T>
	inline T* ComponentArray<T>::GetComponent(Entity ent)
	{
		return &m_componentArray[m_entityToIndex[ent]];
	}

}
