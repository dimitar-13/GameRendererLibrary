#pragma once
#include<vector>
#include"GameObject/GameObject.h"
#include"Renderer/Renderer.h"
namespace SpriteRenderer {
	class SceneManager {

	public:
		SceneManager() {};
		void Start();
		void Update();
		void Draw(const ShaderProgram& shader);
		void AddObjectToScene(GameObject& obj) { this->sceneObjects.push_back(&obj); };


	private:
		Renderer renderer;
		std::vector<GameObject*> sceneObjects;

	private:
		void PipelineLoop();


	};
}