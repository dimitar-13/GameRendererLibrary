#include"input.h"

	bool SpriteRenderer::IsButtonPressed(SpriteRenderer::Keys key)
	{
		return glfwGetKey(Global::winContext, key) == GLFW_PRESS;
	}



