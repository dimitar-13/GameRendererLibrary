#pragma once
#include"Rendererpch.h"
#include"DeltaTime.h"
#include "Transform/Transoform.h"
#include "Sprite/Sprite.h"
#include"Renderer/Renderer.h"
#include"Camera/Camera.h"
#include"Log/Log.h"
#include"Physics/Collision/Colider.h"
#include"Physics/PhysicBody.h"
namespace SpriteRenderer {
	class GameObject;
	class SceneManager {

	public:
		inline static DeltaTime delta;

	public:
		static void Init();
		static void Start();
		static void SetActiveCamera(OrthographicCamera& camera) { instance.activeCamera = &camera; }
		void Update();
		void UpdateScripts();
		//void Draw(const ShaderProgram& shader);
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