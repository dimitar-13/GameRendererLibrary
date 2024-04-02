#pragma once
#include"Rendererpch.h"
#include"TextureClass/Texture2D/Texture2D.h"
namespace SpriteRenderer {
	class Renderer;
	//Enumerator representing shape of the sprite.
	enum SpriteType {
		SPRITE_SHAPE_TYPE_CUBE = 1,
		SPRITE_SHAPE_TYPE_CIRCLE = 2,
	};
	/// <summary>
	/// A class representing sprite component with the options to attach texture,set color and change shape of the sprite.
	/// </summary>
	class Sprite:public Component
	{
	public:
		//Color of the sprite in RGB format.
		glm::vec3 m_Color = glm::vec3(1);
		//Shape of the sprite can be selected from the 'SpriteType' enumerator.
		SpriteType m_shapeType = SPRITE_SHAPE_TYPE_CUBE;
	public:
		/// <summary>
		/// Sets a texture to the current sprite.
		/// Texutres are managed by a manager and removed when no sprites are using them.
		/// </summary>
		/// <param name="texture">Texture to be set.</param>
		void SetTexture(Texture2D& texture) { textureIndex = TextureUnitManager::BindTexture(&texture); }
		/// <summary>
		/// Removes the current texture if any.
		/// </summary>
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