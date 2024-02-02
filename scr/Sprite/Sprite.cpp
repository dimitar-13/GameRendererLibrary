#include"Rendererpch.h"
#include "Sprite.h"
#include"../../Debuging/OpenglDebug.h"
#include"../../../Core/SpriteData.h"
SpriteRenderer::Sprite::Sprite()
{
	this->Color = glm::vec3(1);
	this->vertexArray = new VertexArray(GenQuadVerts(), 6);

}

SpriteRenderer::Sprite::Sprite(std::string& texturePath):Sprite()
{
	this->texture = new Texture2D(texturePath);
}

SpriteRenderer::Sprite::~Sprite()
{
	delete(this->texture);
	delete(this->vertexArray);
}
