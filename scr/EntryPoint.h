#pragma once
#include <iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"SceneManager/SceneManager.h"
#include"../Core/Global.h"
#include"WindowFunctions/WindowFunctions.h"
#include"Shader/ShaderProgram/ShaderProgram.h"

namespace SpriteRenderer {

	inline SpriteRenderer::SceneManager* mainSceneManager;
	int Init();

}
