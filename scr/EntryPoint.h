#pragma once
#include"SceneManager/SceneManager.h"
#include"../Core/Global.h"
#include"WindowFunctions/WindowFunctions.h"
#include"Shader/ShaderProgram/ShaderProgram.h"

namespace SpriteRenderer {

	//Make it a singleton or make it so the client cant delete the object
	int Init();

	void Terminate();

}
