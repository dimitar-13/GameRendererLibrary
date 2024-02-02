#pragma once
#include"Rendererpch.h"
#include"DeltaTime.h"
#include "Transform/Transoform.h"
#include "Sprite/Sprite.h"
#include <type_traits>
#include"Renderer/Renderer.h"
#include"Camera/Camera.h"
#include"Log/Log.h"
#include"Physics/Colision/Colider.h"
#include"Physics/PhysicBody.h"
namespace SpriteRenderer {
	class ScriptableObject;
	class GameObject;
	class SceneManager {

	public:
		inline static DeltaTime delta;
	public:
		template<typename T,typename = std::enable_if_t<!std::is_void_v<T>>>
		static void RegisterComponent(long long objectID) { getInstance().registerComponent<T>(objectID); }
		template<typename T, typename = std::enable_if_t<!std::is_void_v<T>>>
		static void RemoveComponent(long long objectID) { getInstance().removeComponent<T>(objectID); }
		template<typename T, typename = std::enable_if_t<!std::is_void_v<T>>>
		static T* GetGameObjectComponent(long long ID) { return instance.getGameObjectComponent<T>(ID); }
	public:
		static void Init();
		static void Start();
		static GameObject& GetGameObjectByID(long long ID) { return *getInstance().sceneObjects[ID]; }
		static void SetActiveCamera(OrthographicCamera& camera) { instance.activeCamera = &camera; }
		void Update();
		void UpdateScripts();
		void UpdateColisions();
		void PhysicsUpdate();
		void Draw(const ShaderProgram& shader);
		static void GetGameObjectID(GameObject& gameobject);
		static void Terminate();
	private:
		std::unordered_map <long long, std::shared_ptr<GameObject>> sceneObjects;
		std::unordered_map <long long, std::shared_ptr<Transform>> transforms;
		std::unordered_map <long long, std::shared_ptr<OrthographicCamera>> cameras;
		std::unordered_map <long long, std::shared_ptr<Sprite>> sprites;
		std::unordered_map <long long, std::shared_ptr<Colider>> coliders;
		std::unordered_map <long long, std::shared_ptr<PhysicBody>> physicBodies;
		std::unordered_map <long long, std::vector<std::shared_ptr<ScriptableObject>>> scripts;

		static SceneManager& getInstance() { return instance; }
		static SceneManager instance;
		OrthographicCamera* activeCamera;
		long long idItterator = 0;
	private:
		void PipelineLoop();	
		template<typename T>
		void registerComponent(long long objectID);
		template<typename T>
		T* getGameObjectComponent(long long ID);
		template<typename T>
		void removeComponent(long long ID);
		template<typename T>
		std::unordered_map <long long, std::shared_ptr<T>>* getComponentHash();
	};
	inline SceneManager SceneManager::instance;
	template<typename T>
	inline T* SceneManager::getGameObjectComponent(long long ID)
	{
		if constexpr (!std::is_convertible<T, ScriptableObject>::value)
		{
			std::unordered_map <long long, std::shared_ptr<T>>* hash = getComponentHash<T>();
			if (!hash)
			{
				RENDER_LOG_MESSAGE_ERROR("Component of type'{0}' doesnt exist.", typeid(T).name());
			}
			else
			{
				if (hash->find(ID) != hash->end())
					return hash->at(ID).get();
				else
				{
					RENDER_LOG_MESSAGE_WARNING("Cant find component.");
					return nullptr;
				}				
			}
		}
		else if  constexpr (std::is_convertible<T, ScriptableObject>::value)
		{
			return dynamic_cast<T*>(scripts.at(ID)[0].get());
		}
	}
	template<typename T>
	inline void SceneManager::registerComponent(long long objectID)
	{
		if constexpr (!std::is_convertible<T, ScriptableObject>::value)
		{
			std::unordered_map <long long, std::shared_ptr<T>>* hash = getComponentHash<T>();
			if (!hash)
			{
				RENDER_LOG_MESSAGE_ERROR("Component of type'{0}' doesnt exist.", typeid(T).name());
			}
			else
			{
				if (hash->find(objectID) == hash->end())
					(*hash)[objectID] = std::make_shared<T>();
				else
					RENDER_LOG_MESSAGE_ERROR("Game object cant have component of type:{0} more then once.", typeid(T).name());
			}
		}
		else if  constexpr (std::is_convertible<T, ScriptableObject>::value)
		{
			scripts[objectID].push_back(std::make_shared<T>());
		}
		//Check the type of component and then attach it
	}
	template<>
	inline void SceneManager::registerComponent<Colider>(long long objectID)
	{	
		this->coliders[objectID] = std::make_shared< Colider>(*transforms.at(objectID).get());
	}
	template<>
	inline void SceneManager::registerComponent<PhysicBody>(long long objectID)
	{
		this->physicBodies[objectID] = std::make_shared< PhysicBody>(&transforms.at(objectID).get()->t_Position);
	}
	template<typename T>
	inline void SceneManager::removeComponent(long long ID)
	{
		if constexpr (!std::is_convertible<T, ScriptableObject>::value)
		{
			std::unordered_map <long long, T*>* hash = getComponentHash<T>();
			if (!hash)
			{
				RENDER_LOG_MESSAGE_ERROR("Component of type'{0}' doesnt exist.", typeid(T).name());
			}
			else
			{
				if (hash->find(ID) != hash->end())
					hash->erase(ID);
				else
					RENDER_LOG_MESSAGE_ERROR("Game object doesnt have component of type '{0}'.", typeid(T).name());
			}
		}
		else if  constexpr (std::is_convertible<T, ScriptableObject>::value)
		{
			 //*std::dynamic_pointer_cast<T>(scripts.erase(ID)[0];
		}
	}
	template<typename T>
	inline std::unordered_map <long long, std::shared_ptr<T>>* SceneManager::getComponentHash()
	{
		if  constexpr (std::is_same<T, Sprite>::value && std::is_convertible<T, Sprite>::value)
		{
			return &this->sprites;
		}
		else if  constexpr (std::is_same<T, Transform>::value && std::is_convertible<T, Transform>::value)
		{
			return &this->transforms;
		}
		else if  constexpr (std::is_same<T, OrthographicCamera>::value && std::is_convertible<T, OrthographicCamera>::value)
		{
			return &this->cameras;
		}
		else if  constexpr (std::is_convertible<T, ScriptableObject>::value)
		{
			return &this->scripts;
		}
		else if  constexpr (std::is_convertible<T, Colider>::value)
		{
			return &this->coliders;
		}
		else if  constexpr (std::is_convertible<T, PhysicBody>::value)
		{
			return &this->physicBodies;
		}
		else
		{
			RENDER_LOG_MESSAGE_ERROR("No such component of type:{0}.", typeid(T).name());
			return nullptr;
		}
	}
	
}