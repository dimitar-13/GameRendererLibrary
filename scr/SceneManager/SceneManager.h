#pragma once
#include"Rendererpch.h"
#include"DeltaTime.h"
#include"Camera/Camera.h"
#include"Log/Log.h"
namespace SpriteRenderer {
	class GameObject;
	class SceneManager {

	public:
		inline static DeltaTime delta;

	public:
		static void Init();
		static void Start();
		static void SetActiveCamera(OrthographicCamera& camera) { instance.activeCamera = &camera; }
		static void Terminate();
		static OrthographicCamera& GetAtctiveCamera() { return *getInstance().activeCamera; }

		static SceneManager& getInstance() { return instance; }
		static SceneManager instance;
		OrthographicCamera* activeCamera;
	private:
		void PipelineLoop();	
	};
	inline SceneManager SceneManager::instance;
	
}