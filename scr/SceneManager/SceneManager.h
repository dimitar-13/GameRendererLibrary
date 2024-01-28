#pragma once
#include"Rendererpch.h"
#include"DeltaTime.h"
#include "Transform/Transoform.h"
#include "Sprite/Sprite.h"
#include"Renderer/Renderer.h"
#include <type_traits>
namespace SpriteRenderer {
	class Script;
	class GameObject;
	class SceneManager {

	public:
		static void Init();

		static void Start();

		//static void AttachScriptToObject(GameObject& obj,Script& script){ instance.sceneObjects}
		template<typename T>
		static void RegisterComponent(T& component, long long objectID) { getInstance().registerComponent(component, objectID); }
		static Transform& GetTransformByObjectID(long long ID) { return *getInstance().transforms[ID]; }
		static Sprite& GetSpriteByObjectID(long long ID) { return *getInstance().sprites[ID]; }
		static GameObject& GetGameObjectByID(long long ID) { return *getInstance().sceneObjects[ID]; }

		void Update();

		void UpdateTransform();
		void UpdateScripts();

		void Draw(const ShaderProgram& shader);

		static void GetGameObjectID(GameObject& gameobject);

		static void Terminate();
	public:
		inline static DeltaTime delta;
	private:
		std::unordered_map <long long, GameObject*> sceneObjects;
		std::unordered_map <long long, Transform*> transforms;
		std::unordered_map <long long, Sprite*> sprites;
		std::unordered_map <long long, std::vector<Script*>> scripts;
		static SceneManager& getInstance() { return instance; }
		static SceneManager instance;
		long long idItterator = 0;

	private:
		void PipelineLoop();
		template<typename T>
		void registerComponent(T& component, long long objectID);
	};
	inline SceneManager SceneManager::instance;
	template<typename T>
	inline void SceneManager::registerComponent(T& component, long long objectID)
	{
		if  constexpr  (std::is_same<T, SpriteRenderer::Sprite>::value && std::is_convertible<T, SpriteRenderer::Sprite>::value)
		{
			 sprites[objectID] = &component;
		}
		else if  constexpr  (std::is_same<T, Transform>::value && std::is_convertible<T, Transform>::value)
		{
			 transforms[objectID] = &component;
		}		
		//Check the type of component and then attach it
	}
	template<> inline void SceneManager::registerComponent<Script>(Script& component, long long objectID)
	{
		if (&component)
		{
				scripts[objectID].push_back(&component);
			//component.BindScript(objectID);
		}
	}
}