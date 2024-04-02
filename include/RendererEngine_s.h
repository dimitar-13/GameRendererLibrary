#pragma once

//Dependency libs
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtc/matrix_transform.hpp>

//Renderer Libs
#include"EntryPoint.h"
#include"../Core/Global.h"
#include"Scene.h"
#include"Renderer.h"

//Scripts
#include"ScriptableObject.h"
#include"DeltaTime.h"

//Game object
#include"GameObject.h"

//Components
#include"Components/Transoform.h"
#include"Components/Sprite.h"
#include"Components/PhysicBody.h"
#include"Components/ColliderComponent.h"
#include"Components/Camera.h"
#include"Components/ScriptComponent.h"
#include"Components/TagComponent.h"

//Sprites and textures
#include"Texture2D.h"


//Input and window functins
#include"Input.h"
#include"WindowFunctions.h"