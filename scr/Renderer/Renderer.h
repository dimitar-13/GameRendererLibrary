#pragma once
#include"Rendererpch.h"
#include"OpenglData/VertexArray/VertexArray.h"
#include"Sprite/Sprite.h"

namespace SpriteRenderer {
	class ShaderProgram;

	class Renderer
	{
	public:
		static void Init();
		static void EnableDepthTest() { glEnable(GL_DEPTH_TEST); }
		static void DisableDepthTest() { glDisable(GL_DEPTH_TEST); }
		static void Clear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }
		static void Draw(const std::unordered_map<long long, std::shared_ptr<Sprite>>& sprites);

		//Draw Primitives
		void DrawCircle();
		//void DrawSquare();
		//void DrawTriangle();
		//void DrawSprite(); 
		//const static ShaderProgram& GetShader() { return m_instance.getShader(); }
		static void DestroyShader();
		//TODO:
		//Render calls with shaders
	private:
		static void IndexedDraw(const VertexArray& vertexArray);
		static void ArrayDraw(const VertexArray& vertexArray);
	private:
		static Renderer m_instance;
		ShaderProgram* m_CustomShader;
		ShaderProgram* m_SquareShader;
		ShaderProgram* m_CircleShader;

		//ShaderProgram& getShader() { return *instance.mainShader; }
	};
	inline Renderer Renderer::m_instance;
}

