#include"Rendererpch.h"
#include "Sprite.h"
#include"../../../Core/SpriteData.h"
SpriteRenderer::Sprite::Sprite()
{
	this->m_Color = glm::vec3(1);
	this->m_vertexArray = new VertexArray(SpriteVertexData::GenQuadVerts(), 6);
}

SpriteRenderer::Sprite::Sprite(std::string& texturePath):Sprite()
{
	this->m_texture = new Texture2D(texturePath);
}

SpriteRenderer::Sprite::~Sprite()
{
	delete(this->m_texture);
	delete(this->m_vertexArray);
}
