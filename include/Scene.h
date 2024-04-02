#pragma once
#include"Rendererpch.h"
#include"DeltaTime.h"
#include"Components/Camera.h"
#include"Log.h"
#include"ECSManager.h"
namespace SpriteRenderer {
	class GameObject;

	//Class that represents the scene.
	class Scene {
	public:
		//Change in time from the previous to this frame.
		inline static DeltaTime delta;

		/// <summary>
		/// Gets all of the components in the scene.
		/// </summary>
		/// <returns>Returns constant a vector of components.</returns>
		template<typename T>
		static const std::shared_ptr<std::vector<T*>> GetComponents();
	public:
		static void Init();
		//Initializes all the ECS systems and starts the render loop.
		static void Start();
		//Sets the active camera.
		static void SetActiveCamera(OrthographicCamera* camera) { instance.activeCameraEntity = camera; }
		//Is obsolete.
		static void Terminate();
		//Gets the current active camera.
		static OrthographicCamera* GetActiveCamera() { return instance.activeCameraEntity; }
		static void WindowSizeChanged(int newWidth,int newHeight) { instance.windowSizeChanged(newWidth, newHeight); }
		template<typename T>
		std::function<void()> BindToFunc(void(T::*instance)(),const T& classInstance);
	private:
		static Scene instance;
		OrthographicCamera* activeCameraEntity;
		void PipelineLoop();	
		void windowSizeChanged(int newWidth, int newHeight);

	};
	inline Scene Scene::instance;
#pragma region Templated Methods
	template<typename T>
	inline const std::shared_ptr<std::vector<T*>> Scene::GetComponents()
	{
		auto& Comparray = ECSManager::GetComponentArray<T>();
		std::vector<T*> result(Comparray.size);
		for (size_t i = 0; i < Comparray.size; ++i) {
			result[i] = Comparray.componentArray[i];
		}
		return  std::make_shared< std::vector<T*>>(result);
	}
	template<typename T>
	inline std::function<void()> Scene::BindToFunc(void(T::* instance)(),const T& classInstance)
	{
		return std::bind(instance, classInstance);
	}
#pragma endregion
}