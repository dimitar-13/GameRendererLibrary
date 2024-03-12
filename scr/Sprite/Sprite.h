#pragma once
#include"Rendererpch.h"
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
		~Sprite();
	public:
		const glm::vec3 GetSpriteColor() { return this->m_Color; }
	public:
		glm::vec3 SetSpriteColor(glm::vec3 color) { return this->m_Color = color; }
		void SetSpriteType(SpriteType type) { this->m_shapeType = type; }
		//TODO:Sprite should not manage texture lifetime.

		//Set texture in slot for the lifetime of this object
		void SetTexture(Texture2D& texture) { textureIndex = TextureUnitManager::RegisterTexture(&texture); }
	private:
		glm::vec3 m_Color;
		SpriteType m_shapeType;
		GLuint textureIndex = 0;
	};
}