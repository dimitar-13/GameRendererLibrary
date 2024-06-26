#pragma once
#include"Scene.h"
#include"../Core/Global.h"
#include"WindowFunctions.h"
#include"ShaderProgram.h"

namespace SpriteRenderer {
	//initializes the renderer library by creating a window and setting up dependencies.
	int Init();

	//Frees the memory used by the library.
	void Terminate();
}
