#pragma once
#include <iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"SceneManager/SceneManager.h"
#include"../Core/Global.h"
#include"WindowFunctions/WindowFunctions.h"
#include"Shader/ShaderProgram/ShaderProgram.h"

namespace SpriteRenderer {

	//Make it a singleton or make it so the client cant delete the object
	inline SpriteRenderer::SceneManager* mainSceneManager;
	int Init();

	void Terminate();

}
