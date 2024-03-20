#pragma once
#include<GLFW/glfw3.h>
namespace SpriteRenderer
{
	class EventCallbackFuncs {
		public:
			static void Resize(GLFWwindow* window, int width, int height);
			static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
			static void MousePositionCallback(GLFWwindow* window, double x, double y);
			static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	};
}

