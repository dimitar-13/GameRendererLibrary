#include "WindowFunctions.h"
#include"../../Core/Global.h"
#include<iostream>
void Resize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	*Global::winHeight = height;
	*Global::winWidth = width;
	*Global::projection = glm::ortho<float>(-*Global::winWidth / 2, *Global::winWidth / 2, -*Global::winHeight / 2, *Global::winHeight / 2, -1.0, 1.0);
}
