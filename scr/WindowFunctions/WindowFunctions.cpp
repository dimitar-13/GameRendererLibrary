#include"Rendererpch.h"
#include "WindowFunctions.h"
#include"../../Core/Global.h"
#include"Input/Input.h"
#include"SceneManager/SceneManager.h"
#include"Window.h"
void SpriteRenderer::EventCallbackFuncs::Resize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	MainWindow::SetWindowSize(width, height);
	SceneManager::WindowSizeChanged(width, height);
}

void SpriteRenderer::EventCallbackFuncs::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	KeyCodeEnum keyEnum = static_cast<KeyCodeEnum>(key);
	InputManager& instance = InputManager::GetInstance();
	auto& KeyHash = instance.GetKeyHash();
  	if (KeyHash.find(keyEnum) != KeyHash.end())
	{
		KeyHash.at(keyEnum) = static_cast<KeyStateEnum>(action);
	}
}
void SpriteRenderer::EventCallbackFuncs::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	InputManager& instance = InputManager::GetInstance();
	auto& mouseHash = instance.GetMouseHash();
	MouseButton mouseButton = static_cast<MouseButton>(button);
	if (mouseHash.find(mouseButton) != mouseHash.end())
	{
		mouseHash.at(mouseButton) = static_cast<KeyStateEnum>(action);
	}
}

void SpriteRenderer::EventCallbackFuncs::MousePositionCallback(GLFWwindow* window, double x, double y)
{
	InputManager::SetMousePosition({ x,y });
}
