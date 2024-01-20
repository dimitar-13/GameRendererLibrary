#pragma once
#include<GLFW/glfw3.h>
#include"../../Core/Global.h"

enum Keys
{
	KEY_W = GLFW_KEY_W,
	KEY_A = GLFW_KEY_A,
	KEY_S = GLFW_KEY_S,
	KEY_D = GLFW_KEY_D,
	KEY_E = GLFW_KEY_E,
	KEY_R = GLFW_KEY_R,
	KEY_SPACE = GLFW_KEY_SPACE,
	KEY_ARROW_UP = GLFW_KEY_UP,
	KEY_ARRPW_DOWN = GLFW_KEY_DOWN,
	KEY_ARRPW_LEFT = GLFW_KEY_LEFT,
	KEY_ARRPW_RIGHT = GLFW_KEY_RIGHT
};

 bool IsButtonPressed(Keys key);



