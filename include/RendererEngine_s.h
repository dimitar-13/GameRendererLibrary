#pragma once


//Dependency libs
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<GLM/glm.hpp>
#include<GLM/gtc/type_ptr.hpp>
#include<GLM/gtc/matrix_transform.hpp>

//Renderer Libs
#include"EntryPoint.h"
#include"../Core/Global.h"
#include"Camera/Camera.h"
#include"SceneManager/SceneManager.h"
#include"Renderer/Renderer.h"

//Scripts
#include"ScriptableObject/ScriptableObject.h"
#include"DeltaTime.h"

//Game object
#include"GameObject/GameObject.h"
#include"Transform/Transoform.h"
#include"Sprite/Sprite.h"

//Sprites and textures
#include"Sprite/Sprite.h"
#include"TextureClass/Texture2D/Texture2D.h"


//Input and window functins
#include"Input/Input.h"
#include"WindowFunctions/WindowFunctions.h"