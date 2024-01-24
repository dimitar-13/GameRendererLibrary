#pragma once
#include"Rendererpch.h"
#include"OpenglData/VertexArray/VertexArray.h"


namespace SpriteRenderer {
	class ShaderProgram;

	class Renderer
	{
	public:
		static void Init();
		static void EnableDepthTest() { glEnable(GL_DEPTH_TEST); }
		static void DisableDepthTest() { glDisable(GL_DEPTH_TEST); }
		static void Clear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }
		static void IndexedDraw(const VertexArray& vertexArray);
		static void ArrayDraw(const VertexArray& vertexArray);
		const static ShaderProgram& GetShader() { return instance.getShader(); }
		static void DestroyShader();
		//TODO:
		//Render calls with shaders

	private:
		static Renderer instance;
		ShaderProgram* mainShader;
		ShaderProgram& getShader() { return *instance.mainShader; }
	};
	inline Renderer Renderer::instance;
}

