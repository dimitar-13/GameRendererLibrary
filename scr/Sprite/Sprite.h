#pragma once
#include"Rendererpch.h"
#include"Shader/ShaderProgram/ShaderProgram.h"
#include"OpenglData/VertexArray/VertexArray.h"
#include"TextureClass/Texture2D/Texture2D.h"
namespace SpriteRenderer {
	enum SpriteShape {

		CUBE = 1,
		CIRCLE = 2,
		TRIANGLE = 3
	};

	class Sprite
	{
	public:
		Sprite();
		Sprite(std::string& texturePath);
		~Sprite();
	public:
		const VertexArray& GetVertexArray() { return *this->m_vertexArray; }
		const glm::vec3 GetSpriteColor() { return this->m_Color; }
		Texture2D* GetSpriteTexture()const { return this->m_texture; }
	public:
		glm::vec3 SetSpriteColor(glm::vec3 color) { return this->m_Color = color; }
		void SetTexture(const char* path) { this->m_texture = new Texture2D(path); }
	private:
		std::vector<Vertex> m_verts;
		VertexArray* m_vertexArray;
		glm::vec3 m_Color;
		Texture2D* m_texture;
	};
}