#include "WindowFunctions.h"
#include"../../Core/Global.h"
#include"Input/Input.h"
#include<iostream>
void SpriteRenderer::Resize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	*Global::winHeight = height;
	*Global::winWidth = width;
	*Global::projection = glm::ortho<float>(-*Global::winWidth / 2, *Global::winWidth / 2, -*Global::winHeight / 2, *Global::winHeight / 2, -1.0, 1.0);
}

void SpriteRenderer::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	KeyCodeEnum keyEnum = static_cast<KeyCodeEnum>(key);
	InputManager& instance = InputManager::GetInstance();
	auto& KeyHash = instance.GetKeyHash();
  	if (KeyHash.find(keyEnum) != KeyHash.end())
	{
		KeyHash.at(keyEnum) = static_cast<KeyStateEnum>(action);
		std::cout << "Key with keycode" << key << "was:" << action << std::endl;
	}
}
void SpriteRenderer::MouseCallback(GLFWwindow* window, int button, int action, int mods)
{
	InputManager& instance = InputManager::GetInstance();
	auto& mouseHash = instance.GetMouseHash();
	MouseButton mouseButton = static_cast<MouseButton>(button);
	if (mouseHash.find(mouseButton) != mouseHash.end())
	{
		mouseHash.at(mouseButton) = static_cast<KeyStateEnum>(action);
		std::cout << "Mouse key number:" << mouseButton << "was:" << action << std::endl;
	}
}

void SpriteRenderer::mouse_position_callback(GLFWwindow* window, double x, double y)
{
	InputManager::SetMousePosition({ x,y });
	//std::cout << "Mouse at position{" << x << "," << y << "}" << std::endl;
}
