#pragma once
#include<GLFW/glfw3.h>
//TODO:
//Add more 
namespace SpriteRenderer
{
void Resize(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_position_callback(GLFWwindow* window, double x, double y);
void MouseCallback(GLFWwindow* window, int button, int action, int mods);
}

