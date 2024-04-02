#pragma once
#include"Rendererpch.h"
#include"ECS/ECSManager.h"
namespace SpriteRenderer
{
	//Class representing an entity.
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
		void DestroyGameObject();
	public:
		/// <summary>
		/// Attaches a component to the caller object and returns a handle of the component.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns>Handle(pointer) of the created component.</returns>
		template <typename T>
		T *const AttachComponent()const;
		/// <summary>
		/// Removes the specified component type from the caller object.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		template <typename T>
		void RemoveComponent()const;
		/// <summary>
		/// Returns a handle of the specified component to be worked on.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns>Handle(pointer) of the created component.</returns>
		template <typename T>
		T *const GetComponent()const;
		/// <summary>
		/// Checks if the caller game object has component of type T.
		/// </summary>
		/// <typeparam name="T">Can be any component.</typeparam>
		/// <returns>Returns true if it has and false if it doesnt.</returns>
		template <typename T>
		bool HasComponent()const;

	private:
		ECSTypes::Entity m_entity;
	};
#pragma region Templated methods
	template<typename T>
	inline T *const GameObject::AttachComponent()const
	{
		ECSManager::AddComponent<T>(this->m_entity);
		return ECSManager::GetComponent<T>(this->m_entity);
	}
	template <typename T>
	inline void GameObject::RemoveComponent()const {
		if(this->HasComponent<T>())
			ECSManager::RemoveComponent<T>(this->m_entity);
	}
	template <typename T>
	inline T *const GameObject::GetComponent()const
	{
		return ECSManager::GetComponent<T>(this->m_entity);
	}
	template<typename T>
	inline bool GameObject::HasComponent()const
	{
		return ECSManager::HasComponent<T>(this->m_entity);
	}
#pragma endregion

}