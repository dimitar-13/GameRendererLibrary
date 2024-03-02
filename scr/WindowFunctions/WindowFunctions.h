#pragma once
#include<GLFW/glfw3.h>
//TODO:
//Add more 
namespace SpriteRenderer
{
void Resize(GLFWwindow* window, int width, int height);
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void MousePositionCallback(GLFWwindow* window, double x, double y);
void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
}

