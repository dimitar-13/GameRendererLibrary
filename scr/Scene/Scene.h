#pragma once
#include"Rendererpch.h"
#include"DeltaTime.h"
#include"Components/Camera.h"
#include"Log/Log.h"
#include"ECS/ECSManager.h"
namespace SpriteRenderer {
	class GameObject;

	//TODO: I am not 100% sure if Scene is the best name or even if the scene must take care of the 
	//Pipeline run.

	class Scene {

	public:
		inline static DeltaTime delta;
		template<typename T>
		static const std::shared_ptr<std::vector<T*>> GetComponents();
	public:
		static void Init();
		static void Start();
		static void SetActiveCamera(OrthographicCamera* camera) { instance.activeCameraEntity = camera; }
		static void Terminate();
		static OrthographicCamera* GetAtctiveCamera() { return instance.activeCameraEntity; }
		static void WindowSizeChanged(int newWidth,int newHeight) { instance.windowSizeChanged(newWidth, newHeight); }
		static Scene instance;
		OrthographicCamera* activeCameraEntity;
		template<typename T>
		std::function<void()> BindToFunc(void(T::*instance)(),const T& classInstance);
	private:
		void PipelineLoop();	
		void windowSizeChanged(int newWidth, int newHeight);

	};
	inline Scene Scene::instance;
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
}