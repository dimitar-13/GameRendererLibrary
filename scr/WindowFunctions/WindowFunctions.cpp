#include"Rendererpch.h"
#include "WindowFunctions.h"
#include"../../Core/Global.h"
#include"Input/Input.h"
#include"SceneManager/SceneManager.h"
void SpriteRenderer::Resize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	*Global::winHeight = height;
	*Global::winWidth = width;
	SceneManager::GetAtctiveCamera()->WindowSizeChanged(width, height);
	//TODO:Get the current camera and change the projection
	//or use event so single the camera that is interested.
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
