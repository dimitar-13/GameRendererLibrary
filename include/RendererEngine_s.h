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
#include"Scene/Scene.h"
#include"Renderer/Renderer.h"

//Scripts
#include"ScriptableObject/ScriptableObject.h"
#include"DeltaTime.h"

//Game object
#include"GameObject/GameObject.h"

//Components
#include"Components/Transoform.h"
#include"Components/Sprite.h"
#include"Components/PhysicBody.h"
#include"Components/ColliderComponent.h"
#include"Components/Camera.h"
#include"Components/ScriptComponent.h"
#include"Components/TagComponent.h"

//Sprites and textures
#include"TextureClass/Texture2D/Texture2D.h"


//Input and window functins
#include"Input/Input.h"
#include"WindowFunctions/WindowFunctions.h"