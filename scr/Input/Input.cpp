#include"Rendererpch.h"
#include"input.h"
SpriteRenderer::InputManager::InputManager()
{
	double mousey, mousex;
	glfwGetCursorPos(Global::winContext, &mousex, &mousey);
	this->mouseXPos = static_cast<float>(mousex);
	this->mouseXPos = static_cast<float>(mousey);
}

bool SpriteRenderer::InputManager::isKeyPressed(KeyCodeEnum key)
{
	auto Status = this->m_keyState.at(key);
	//Easy fix for key state not updating fast enoght between frames basicly if the user presses a key that means that he will only press it once so its good to set
	//the hash value to release to avoid the problem in this way.
	this->m_keyState.at(key) = Status == KEY_PRESSED ? KEY_RELEASED : Status;
	return Status == KEY_PRESSED;
}
bool SpriteRenderer::InputManager::isMouseButtonPressed(MouseButton button)
{
	auto Status = this->m_mouseButtonStates.at(button);
	this->m_mouseButtonStates.at(button) = Status == KEY_PRESSED ? KEY_RELEASED : Status;
	return Status == KEY_PRESSED;
}
bool SpriteRenderer::InputManager::isMouseButtonDown(MouseButton button)
{
	return this->m_mouseButtonStates.at(button) == KEY_HELD || this->m_mouseButtonStates.at(button) == KEY_PRESSED;
}
bool SpriteRenderer::InputManager::isKeyDown(KeyCodeEnum key)
{
	return this->m_keyState.at(key) == KEY_HELD || this->m_keyState.at(key) == KEY_PRESSED;
}

void SpriteRenderer::InputManager::setMousePosition(std::pair<float, float> newPosition)
{
	this->mouseXPos = newPosition.first;
	this->mouseXPos = newPosition.second;
}
