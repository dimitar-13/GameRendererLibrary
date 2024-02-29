#pragma once
#include"Rendererpch.h"
#include"../../Core/Global.h"
#include"ECS/ECSManager.h"
//TODO: Add an GameObject idenifier like an ID 
//Instead of iterating throu each game object in the rendering stage we can pack every component in one continus array of bytes and each component will have the id of the gameobj
//in this way we dont need when rendering to say "Well do you have a script or maybe u have a sprite" because in this way we dont care that much about the class rather then
//we care of the component and the idenifier of the class that we need

//Another benefit instead of going throu 1m game obj to querry for let say sprites and audio we can store em in a vecotr of sprites and submit them to the renderer
//because at the end of the day renderer care about the rendering

//The ECS-entity component system means we can devide our entinies or game objects into components and the system parts mean we can have systems for dealing with 
//certian components like draw,playaudio,simPhysics and so on
namespace SpriteRenderer
{
	class ScriptableObject;
	class GameObject
	{
	public:
		//std::string name;
		Entity GetEntity() { return this->m_entity; }
	public:
		GameObject();
		void DestroyGameObject() { ECSManager::RemoveEntity(this->m_entity); }
	public:
		template <class T>
		T* AttachComponent();
		template <class T>
		void RemoveComponent();
		template <class T>
		T* GetComponent();
	private:
		friend class ScriptableObject;
		Entity m_entity;
	};
	template<class T>
	inline T* GameObject::AttachComponent()
	{
		ECSManager::AddComponent<T>(this->m_entity);
		return ECSManager::GetComponent<T>(this->m_entity);
	}
	template <class T>
	inline void GameObject::RemoveComponent() {
		//SceneManager::RemoveComponent<T>(this->objectID);
	}
	template <class T>
	inline T* GameObject::GetComponent()
	{
		return ECSManager::GetComponent<T>(this->m_entity);
	}
}