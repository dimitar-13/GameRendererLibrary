#include"Rendererpch.h"
#include "WindowFunctions.h"
#include"../../Core/Global.h"
#include"Input/Input.h"
void SpriteRenderer::Resize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	*Global::winHeight = height;
	*Global::winWidth = width;
	*Global::projection = glm::ortho<float>((float)( - *Global::winWidth / 2),
											(float)(*Global::winWidth / 2), 
											(float)( - *Global::winHeight / 2), 
											(float)(*Global::winHeight / 2), -1.0, 1.0);
}

void SpriteRenderer::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	KeyCodeEnum keyEnum = static_cast<KeyCodeEnum>(key);
	InputManager& instance = InputManager::GetInstance();
	auto& KeyHash = instance.GetKeyHash();
  	if (KeyHash.find(keyEnum) != KeyHash.end())
	{
		KeyHash.at(keyEnum) = static_cast<KeyStateEnum>(action);
	}
}
void SpriteRenderer::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	InputManager& instance = InputManager::GetInstance();
	auto& mouseHash = instance.GetMouseHash();
	MouseButton mouseButton = static_cast<MouseButton>(button);
	if (mouseHash.find(mouseButton) != mouseHash.end())
	{
		mouseHash.at(mouseButton) = static_cast<KeyStateEnum>(action);
	}
}

void SpriteRenderer::MousePositionCallback(GLFWwindow* window, double x, double y)
{
	InputManager::SetMousePosition({ x,y });
}
