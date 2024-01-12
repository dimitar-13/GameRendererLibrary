#pragma once
#include<vector>
#include"../../scr/GameObject/GameObject.h"
class SceneManager {

public:
	SceneManager() {};
	std::vector<GameObject*> sceneObjects;


	void Start();
	void Update();
	void Draw();


};