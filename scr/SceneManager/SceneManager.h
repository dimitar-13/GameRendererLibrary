#pragma once
#include"Rendererpch.h"
#include"DeltaTime.h"
#include "Transform/Transoform.h"
#include "Sprite/Sprite.h"
#include <type_traits>
#include"Renderer/Renderer.h"
#include"Camera/Camera.h"
namespace SpriteRenderer {
	class ScriptableObject;
	class GameObject;
	class SceneManager {

	public:
		inline static DeltaTime delta;
	public:
		template<typename T>
		static void RegisterComponent(long long objectID) { getInstance().registerComponent<T>(objectID); }
		template<typename T>
		static void RemoveComponent(long long objectID) { getInstance().removeComponent<T>(objectID); }
		template<typename T>
		static T& GetGameObjectComponent(long long ID) { return instance.getGameObjectComponent<T>(ID); }
	public:
		static void Init();
		static void Start();
		static GameObject& GetGameObjectByID(long long ID) { return *getInstance().sceneObjects[ID]; }
		static void SetActiveCamera(OrthographicCamera& camera) { instance.activeCamera = &camera; }
		void Update();
		void UpdateScripts();
		void Draw(const ShaderProgram& shader);
		static void GetGameObjectID(GameObject& gameobject);
		static void Terminate();
	private:
		std::unordered_map <long long, GameObject*> sceneObjects;
		std::unordered_map <long long, Transform*> transforms;
		std::unordered_map <long long, OrthographicCamera*> cameras;
		std::unordered_map <long long, Sprite*> sprites;
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
		T& getGameObjectComponent(long long ID);
		template<typename T>
		void removeComponent(long long ID);
	};
	inline SceneManager SceneManager::instance;
	template<typename T>
	inline T& SceneManager::getGameObjectComponent(long long ID)
	{
		if  constexpr (std::is_same<T, SpriteRenderer::Sprite>::value && std::is_convertible<T, SpriteRenderer::Sprite>::value)
		{
			return *sprites.at(ID);
		}
		else if  constexpr (std::is_same<T, Transform>::value && std::is_convertible<T, Transform>::value)
		{
			return *transforms.at(ID);
		}
		else if  constexpr (std::is_same<T, OrthographicCamera>::value && std::is_convertible<T, OrthographicCamera>::value)
		{
			return *cameras.at(ID);
		}
		else if  constexpr ( std::is_convertible<T, ScriptableObject>::value)
		{
			return *std::dynamic_pointer_cast<T>(scripts.at(ID)[0]);
		}
		// TODO: insert return statement here
	}
	template<typename T>
	inline void SceneManager::registerComponent(long long objectID)
	{
		if  constexpr  (std::is_same<T, SpriteRenderer::Sprite>::value && std::is_convertible<T, SpriteRenderer::Sprite>::value)
		{
			 sprites[objectID] = new T();
		}
		else if  constexpr  (std::is_same<T, Transform>::value && std::is_convertible<T, Transform>::value)
		{
			 transforms[objectID] = new T();
		}	
		else if  constexpr (std::is_same<T, OrthographicCamera>::value && std::is_convertible<T, OrthographicCamera>::value)
		{
			cameras[objectID] = new T();
		}
		else if  constexpr (std::is_convertible<T, ScriptableObject>::value)
		{
			scripts[objectID].push_back(std::make_shared<T>());
		}
		//Check the type of component and then attach it
	}
	template<typename T>
	inline void SceneManager::removeComponent(long long ID)
	{
		if  constexpr (std::is_same<T, SpriteRenderer::Sprite>::value && std::is_convertible<T, SpriteRenderer::Sprite>::value)
		{
			if (sprites.find(ID) != sprites.end())
			{
				sprites.erase(ID);
			}
		}
		else if  constexpr (std::is_same<T, Transform>::value && std::is_convertible<T, Transform>::value)
		{
			if (transforms.find(ID) != transforms.end())
			{
				transforms.erase(ID);
			}
		}
		else if  constexpr (std::is_same<T, OrthographicCamera>::value && std::is_convertible<T, OrthographicCamera>::value)
		{
			if (cameras.find(ID) != cameras.end())
			{
				cameras.erase(ID);
			}
		}

	}
	
}