#pragma once
#include"Rendererpch.h"
#include"Component.h"
#include"Log/Log.h"
#include"ECS/ECSTypes.h"
#include"ECS/EventSystem/EventSystem.h"
#include"GameObject/GameObjectRegister.h"
namespace SpriteRenderer {
	class IComponentArray
	{
	public:
		void virtual OnEntityDestroyed(ECSTypes::Entity ent) = 0;
		void virtual DestroyComponentArray() = 0;
	};

	template<typename T>
	struct ComponentArrayWrapper
	{
		std::array<T*, ECSTypes::MAX_COMPONENTS> componentArray;
		uint32_t size = 0;
	};

	template<typename T>
	class ComponentArray:public IComponentArray
	{
	public:
		void RemoveComponent(ECSTypes::Entity ent);
		void AddComponent(ECSTypes::Entity ent);
		T* GetComponent(ECSTypes::Entity ent);
		bool HasComponent(ECSTypes::Entity ent);
		ComponentArrayWrapper<T>& GetArray() { return m_componentArray; }
		void AddEventListener(std::function<void()>listener) { m_componentArrayChangedEvent += listener; }
		const std::vector<ECSTypes::Entity> GetComponentEntities();
		void OnEntityDestroyed(ECSTypes::Entity ent) override;
		void DestroyComponentArray() override;
	private:
		ComponentArrayWrapper<T> m_componentArray;
		std::unordered_map< ECSTypes::Entity, uint32_t> m_entityToIndex{};
		std::unordered_map< uint32_t , ECSTypes::Entity> m_indexToEntity{};
		Event<void> m_componentArrayChangedEvent;
	};
#pragma region Templated methods
	template<typename T>
	inline void ComponentArray<T>::OnEntityDestroyed(ECSTypes::Entity ent)
	{
		if (m_entityToIndex.find(ent) != m_entityToIndex.end())
		{
			RemoveComponent(ent);
			m_componentArrayChangedEvent.Invoke();
		}
	}
	template<typename T>
	inline void ComponentArray<T>::DestroyComponentArray() {
		for (uint32_t i = 0; i < m_componentArray.size; i++)
		{
			delete(m_componentArray.componentArray[i]);
		}
		m_entityToIndex.clear();
		m_indexToEntity.clear();
	}

	template<typename T>
	inline void ComponentArray<T>::RemoveComponent(ECSTypes::Entity ent)
	{
		uint32_t entityToRemoveIndex = m_entityToIndex[ent];
		uint32_t lastArrayComponentIndex = m_componentArray.size - 1;
		uint32_t lastEntity = m_indexToEntity[lastArrayComponentIndex];
		delete(m_componentArray.componentArray[entityToRemoveIndex]);
		if (lastEntity != ent)
		{
			m_componentArray.componentArray[entityToRemoveIndex] = m_componentArray.componentArray[lastArrayComponentIndex];

			m_indexToEntity[entityToRemoveIndex] = lastEntity;
			m_entityToIndex[lastEntity] = entityToRemoveIndex;
			m_componentArray.componentArray[lastArrayComponentIndex] = NULL;

			m_entityToIndex.erase(ent);
			m_indexToEntity.erase(lastArrayComponentIndex);
			--m_componentArray.size;
		}
		else
		{
			m_componentArray.componentArray[lastArrayComponentIndex] = NULL;
			m_entityToIndex.erase(ent);
			m_indexToEntity.erase(lastArrayComponentIndex);
			--m_componentArray.size;
		}

		m_componentArrayChangedEvent.Invoke();
	}

	template<typename T>
	inline void ComponentArray<T>::AddComponent(ECSTypes::Entity ent)
	{
		uint32_t index = m_componentArray.size;
		m_entityToIndex[ent] = index;
		m_indexToEntity[index] = ent;
		m_componentArray.componentArray[index] = new T();
		Component* componentCast = dynamic_cast<Component*> (m_componentArray.componentArray[index]);
		componentCast->SetGameObjectMember(GameObjectRegister::GetGameObjRef(ent));
		m_componentArray.size++;

		m_componentArrayChangedEvent.Invoke();
	}
	template<typename T>
	inline bool ComponentArray<T>::HasComponent(ECSTypes::Entity ent)
	{
		if (m_entityToIndex.find(ent) != m_entityToIndex.end())
			return true;
		return false;
	}
	template<typename T>
	inline T* ComponentArray<T>::GetComponent(ECSTypes::Entity ent)
	{
		if (m_entityToIndex.find(ent) != m_entityToIndex.end())
			return m_componentArray.componentArray[m_entityToIndex[ent]];
		return nullptr;
	}

	template<typename T>
	inline const std::vector<ECSTypes::Entity> ComponentArray<T>::GetComponentEntities()
	{
		std::vector<ECSTypes::Entity> result(m_indexToEntity.size());
		for (uint32_t i = 0; i < result.size(); i++)
		{
			result[i] = m_indexToEntity[i];
		}
		return result;
	}
#pragma endregion
}
