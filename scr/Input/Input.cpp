#include"input.h"

	bool IsButtonPressed(Keys key)
	{
		return glfwGetKey(Global::winContext, key) == GLFW_PRESS;
	}



