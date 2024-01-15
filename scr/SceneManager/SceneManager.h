#pragma once
#include<vector>
#include"../../scr/GameObject/GameObject.h"
#include"../../scr/Renderer/Renderer.h"
class SceneManager {

public:
	SceneManager() {};
	void Start();
	void Update();
	void Draw(const ShaderProgram& shader);
	void AddObjectToScene(GameObject& obj) { this->sceneObjects.push_back(&obj);};


private:
	Renderer renderer;
	std::vector<GameObject*> sceneObjects;

private:
	void PipelineLoop();


};