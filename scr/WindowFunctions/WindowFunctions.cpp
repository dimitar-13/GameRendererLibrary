#include "WindowFunctions.h"
#include"../../Core/Global.h"
#include<iostream>
void Resize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	*Global::winHeight = height;
	*Global::winHeight = width;
}