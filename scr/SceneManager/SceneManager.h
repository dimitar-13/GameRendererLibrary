#pragma once
#include"Rendererpch.h"
#include"DeltaTime.h"
#include"Components/Camera.h"
#include"Log/Log.h"
namespace SpriteRenderer {
	class GameObject;
	class SceneManager {

	public:
		inline static DeltaTime delta;

	public:
		static void Init();
		static void Start();
		static void SetActiveCamera(OrthographicCamera* camera) { instance.activeCameraEntity = camera; }
		static void Terminate();
		static OrthographicCamera* GetAtctiveCamera() { return getInstance().activeCameraEntity; }
		
		static SceneManager& getInstance() { return instance; }
		static void WindowSizeChanged(int newWidth,int newHeight) { getInstance().windowSizeChanged(newWidth, newHeight); }
		static SceneManager instance;
		OrthographicCamera* activeCameraEntity;
	private:
		void PipelineLoop();	
		void windowSizeChanged(int newWidth, int newHeight);

	};
	inline SceneManager SceneManager::instance;
	
}