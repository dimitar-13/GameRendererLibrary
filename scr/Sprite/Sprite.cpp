#include"Rendererpch.h"
#include "Sprite.h"
SpriteRenderer::Sprite::Sprite()
{
	this->m_Color = glm::vec3(1);
	this->m_shapeType = SPRITE_SHAPE_TYPE_CUBE;
}

SpriteRenderer::Sprite::~Sprite()
{
	if(this->textureIndex != 0 )
		TextureUnitManager::UnBindTexture(this->textureIndex);
}
