#pragma once
#include"Rendererpch.h"
#include"Shader/ShaderProgram/ShaderProgram.h"
#include"OpenglData/VertexArray/VertexArray.h"
#include"TextureClass/Texture2D/Texture2D.h"
namespace SpriteRenderer {
	class Renderer;
	enum SpriteType {

		SPRITE_SHAPE_TYPE_CUBE = 1,
		SPRITE_SHAPE_TYPE_CIRCLE = 2,
		SPRITE_SHAPE_TYPE_TRIANGLE = 3,
		SPRITE_SHAPE_TYPE_CUSTOM = 4
	};

	class Sprite
	{
		friend class Renderer;
	public:
		Sprite();
		Sprite(std::string& texturePath);
		~Sprite();
	public:
		const VertexArray& GetVertexArray() { return *this->m_vertexArray; }
		const glm::vec3 GetSpriteColor() { return this->m_Color; }
	public:
		glm::vec3 SetSpriteColor(glm::vec3 color) { return this->m_Color = color; }
		void SetSpriteType(SpriteType type) { this->m_shapeType = type; }
	private:
		std::vector<Vertex> m_verts;
		VertexArray* m_vertexArray;
		glm::vec3 m_Color;
		SpriteType m_shapeType;
		Texture2D* m_texture;
	};
}