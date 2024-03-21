#pragma once
#include"Rendererpch.h"
#include"TextureClass/Texture2D/Texture2D.h"
namespace SpriteRenderer {
	class Renderer;
	enum SpriteType {
		SPRITE_SHAPE_TYPE_CUBE = 1,
		SPRITE_SHAPE_TYPE_CIRCLE = 2,
	};
	class Sprite:public Component
	{
	public:
		glm::vec3 m_Color = glm::vec3(1);
		SpriteType m_shapeType = SPRITE_SHAPE_TYPE_CUBE;
	public:
		void SetTexture(Texture2D& texture) { textureIndex = TextureUnitManager::BindTexture(&texture); }
		void RemoveTexture() { TextureUnitManager::UnBindTexture(textureIndex); textureIndex = 1; }
		~Sprite() {
			if (this->textureIndex != 0)
				TextureUnitManager::UnBindTexture(this->textureIndex);
		}	
	private:
		friend class Renderer;
		GLuint textureIndex = 1;
	};
}