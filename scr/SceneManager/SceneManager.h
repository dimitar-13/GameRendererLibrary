#pragma once
#include"Rendererpch.h"
#include"DeltaTime.h"
#include"Camera/Camera.h"
#include"Log/Log.h"
namespace SpriteRenderer {
	using Entity = std::uint32_t;
	class GameObject;
	class SceneManager {

	public:
		inline static DeltaTime delta;

	public:
		static void Init();
		static void Start();
		static void SetActiveCamera(Entity camera) { instance.activeCameraEntity = camera; }
		static void Terminate();
		static Entity GetAtctiveCamera() { return getInstance().activeCameraEntity; }

		static SceneManager& getInstance() { return instance; }
		static SceneManager instance;
		Entity activeCameraEntity;
	private:
		void PipelineLoop();	
	};
	inline SceneManager SceneManager::instance;
	
}