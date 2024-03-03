#pragma once
#include"Rendererpch.h"

#ifdef  RENDER_ENGINE_API_BUILD
	#define RENDER_ENGINE_API __declspec(dllexport)
#else
	#define RENDER_ENGINE_API __declspec(dllimport)
#endif
namespace SpriteRenderer {
	namespace Global
	{
		inline int* winWidth = new int(1000);
		inline int* winHeight = new int(1000);
		inline GLFWwindow* winContext = 0;
	}
}