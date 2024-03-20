#pragma once
#include"Rendererpch.h"
#include"TextureClass/Texture2D/Texture2D.h"
namespace SpriteRenderer {
	class Renderer;
	enum SpriteType {

		SPRITE_SHAPE_TYPE_CUBE = 1,
		SPRITE_SHAPE_TYPE_CIRCLE = 2,
		SPRITE_SHAPE_TYPE_TRIANGLE = 3,
		SPRITE_SHAPE_TYPE_CUSTOM = 4
	};
	class Sprite:public Component
	{
		friend class Renderer;
	public:
		Sprite() {
			this->m_Color = glm::vec3(1);
			this->m_shapeType = SPRITE_SHAPE_TYPE_CUBE;
		}
		~Sprite() {
			if (this->textureIndex != 0)
				TextureUnitManager::UnBindTexture(this->textureIndex);
		}
		glm::vec3 GetSpriteColor()const { return this->m_Color; }
		glm::vec3 SetSpriteColor(glm::vec3 color) { return this->m_Color = color; }
		void SetSpriteType(SpriteType type) { this->m_shapeType = type; }
		void SetTexture(Texture2D& texture) { textureIndex = TextureUnitManager::BindTexture(&texture);  }
		void RemoveTexture() { TextureUnitManager::UnBindTexture(textureIndex); textureIndex = 1; }
	private:
		glm::vec3 m_Color;
		SpriteType m_shapeType;
		GLuint textureIndex = 1;
	};
}