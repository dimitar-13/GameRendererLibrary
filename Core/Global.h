#pragma once
#include<GLFW/glfw3.h>
#include "../Dependencies/GLM/glm.hpp"
#include "../Dependencies/GLM/gtc/type_ptr.hpp"
#include "../Dependencies/GLM/gtc/matrix_transform.hpp"
namespace Global
{
	  inline int* winWidth = new int(1000);
	  inline int* winHeight = new int(1000);
	  inline GLFWwindow* winContext = 0;
	  inline glm::mat4* projection = new glm::mat4(1);
}