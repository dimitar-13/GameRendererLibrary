#pragma once
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"..\Sprite\Sprite.h"
#include"../Script/Script.h"
#include"../../scr/OpenglData/VertexArray/VertexArray.h"
#include<vector>
class Script;


	class Renderer 
	{
	public:
		void StartRenderLoop();
		void RenderOject();
		void Clear();
		void IndexedDraw(const VertexArray& vertexArray);
		void ArrayDraw(const VertexArray& vertexArray);
		//TODO:
		//Render calls with shaders


		std::vector<Script*> scripts;
	};
	

