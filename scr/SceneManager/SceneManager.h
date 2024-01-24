#pragma once
#include"Rendererpch.h"
#include"GameObject/GameObject.h"
#include"Renderer/Renderer.h"
namespace SpriteRenderer {
	class SceneManager {

	public:
		static void Init();

		static void Start();

		static void AddObjectToScene(GameObject& obj) { instance.sceneObjects.push_back(&obj); };

		void Update();
		void Draw(const ShaderProgram& shader);
	private:
		std::vector<GameObject*> sceneObjects;
		static SceneManager instance;
	private:
		void PipelineLoop();


	};
	inline SceneManager SceneManager::instance;
}