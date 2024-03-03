#pragma once
#include"Rendererpch.h"
#include"OpenglData/VertexArray/VertexArray.h"
#include"ECS/ISystem.h"
#include"Transform/Transoform.h"
namespace SpriteRenderer {
	class ShaderProgram;
	//TODO:Create a Render system and a renderer.
	//The render system can do calls to the renderer 

	class Renderer:public ISystem
	{
	public:
		void Init() override;
		static void EnableDepthTest() { glEnable(GL_DEPTH_TEST); }
		static void DisableDepthTest() { glDisable(GL_DEPTH_TEST); }
		static void Clear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }
		void Draw();

		void PreUpdate(float dt) override;
		void Update(float dt) override;
		void PostUpdate(float dt) override;
		void DestroySystem() override;

		const glm::mat4 CalculateModelMatrix(const Transform& spriteTransform);
		const glm::mat4 CalculateViewMatrix(const Transform& cameraTransform);

		//Draw Primitives
		void DrawCircle();
		//void DrawSquare();
		//void DrawTriangle();
		//void DrawSprite(); 
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

