#include"Rendererpch.h"
#include "Sprite.h"
#include"../../../Core/SpriteData.h"
SpriteRenderer::Sprite::Sprite()
{
	this->m_Color = glm::vec3(1);
	this->m_vertexArray = new VertexArray(SpriteRenderer::GenQuadVerts(), 6);
	this->m_shapeType = SPRITE_SHAPE_TYPE_CUBE;
}

SpriteRenderer::Sprite::Sprite(std::string& texturePath):Sprite()
{
	this->m_texture = new Texture2D(texturePath);
}

SpriteRenderer::Sprite::~Sprite()
{
	//delete(this->m_texture);
	delete(this->m_vertexArray);
}
