#pragma once
#include"Rendererpch.h"
#include"ECS/ECSManager.h"
namespace SpriteRenderer
{
	class ScriptableObject;
	struct Component;

	class GameObject
	{
	public:		
		/// <summary>
		/// Returns the ID of the caller object.
		/// </summary>
		/// <returns>ID of the entity.</returns>
		ECSTypes::Entity GetEntity()const { return this->m_entity; }
	public:
		/// <summary>
		/// Creates a entity and attach a transform component to it.
		/// The lifetime of the entity is managed by a Entity manager!
		/// </summary>
		GameObject();
		/// <summary>
		/// Destroys the caller object and every component attached to it.
		/// </summary>
		void DestroyGameObject() { ECSManager::RemoveEntity(this->m_entity); }
	public:
		/// <summary>
		/// Attaches a component to the caller object and returns a handle of the component.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns>Handle(pointer) of the created component.</returns>
		template <typename T>
		T* AttachComponent();
		/// <summary>
		/// Removes the specified component type from the caller object.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		template <typename T>
		void RemoveComponent();
		/// <summary>
		/// Returns a handle of the specified component to be worked on.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns>Handle(pointer) of the created component.</returns>
		template <typename T>
		T* GetComponent();
		/// <summary>
		/// Checks if the caller game object has component of type T.
		/// </summary>
		/// <typeparam name="T">Can be any component.</typeparam>
		/// <returns>Returns true if it has and false if it doesnt.</returns>
		template <typename T>
		bool HasComponent();

	private:
		friend class ScriptableObject;
		friend struct Component;
		GameObject(ECSTypes::Entity Entity) { m_entity = Entity; }
		ECSTypes::Entity m_entity;
	};
	template<typename T>
	inline T* GameObject::AttachComponent()
	{
		ECSManager::AddComponent<T>(this->m_entity);
		return ECSManager::GetComponent<T>(this->m_entity);
	}
	template <typename T>
	inline void GameObject::RemoveComponent() {
		ECSManager::RemoveComponent<T>(this->m_entity);
	}
	template <typename T>
	inline T* GameObject::GetComponent()
	{
		return ECSManager::GetComponent<T>(this->m_entity);
	}
	template<typename T>
	inline bool GameObject::HasComponent()
	{
		return ECSManager::HasComponent<T>(this->m_entity);
	}
}