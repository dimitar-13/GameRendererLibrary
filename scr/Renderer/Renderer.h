#pragma once
#include"Rendererpch.h"
#include"Transform/Transoform.h"
#include "Sprite/Sprite.h"
namespace SpriteRenderer {
	class ShaderProgram;
	//TODO:Create a Render system and a renderer.
	//The render system can do calls to the renderer 

	/*struct IndexArraySpriteData {
		std::array<Vertex, 4> m_verts;
		std::array<uint32_t, 4> m_indicies;
	};

	struct VertexArraySpriteData {
		std::array<Vertex, 6> m_verts;
	};*/

	class Renderer
	{
	public:
		Renderer();
		~Renderer();
		static void EnableDepthTest() { glEnable(GL_DEPTH_TEST); }
		static void DisableDepthTest() { glDisable(GL_DEPTH_TEST); }
		static void Clear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }
		

		void SubmitToDraw(Sprite* spriteToDraw,
			const glm::mat4& modelMatrix,
			const glm::mat4& viewProjMatrix);
	

		//Draw Primitives
		void DrawCircle(Sprite* spriteToDraw, const glm::mat4& modelMatrix,
			const glm::mat4& viewProjMatrix);
		void DrawSquare(Sprite* spriteToDraw, const glm::mat4& modelMatrix,
			const glm::mat4& viewProjMatrix);
		void DrawSprite(Sprite* spriteToDraw, const glm::mat4& modelMatrix,
			const glm::mat4& viewProjMatrix);
		//void GenVertexArray();
		//void GenIndexArray();

		//void DrawTriangle();
		//const static ShaderProgram& GetShader() { return m_instance.getShader(); }
		//TODO:
		//Render calls with shaders
	private:
		static void IndexedDraw(const VertexArray& vertexArray);
		static void ArrayDraw(const VertexArray& vertexArray);
	private:
		ShaderProgram* m_CustomShader = nullptr;
		ShaderProgram* m_SquareShader = nullptr;
		ShaderProgram* m_CircleShader = nullptr;
	};
}

