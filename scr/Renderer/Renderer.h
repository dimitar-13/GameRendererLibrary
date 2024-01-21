#pragma once
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"OpenglData/VertexArray/VertexArray.h"

#include<vector>

namespace SpriteRenderer {
	class ShaderProgram;

	class Renderer
	{
	public:
		Renderer();

		void EnableDepthTest() { glEnable(GL_DEPTH_TEST); }
		void DisableDepthTest() { glDisable(GL_DEPTH_TEST); }

		void Clear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }


		void IndexedDraw(const VertexArray& vertexArray);
		void ArrayDraw(const VertexArray& vertexArray);

		//TODO:
		//Render calls with shaders

		ShaderProgram* mainShader;
	};
}

