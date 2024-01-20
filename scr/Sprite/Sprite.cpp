#include "Sprite.h"
#include<gl/glew.h>
#include<iostream>
#include"../../Debuging/OpenglDebug.h"
#include"../../../Core/SpriteData.h"
#include<vector>
Sprite::Sprite()
{
	this->Color = glm::vec3(1);
	this->vertexArray = new VertexArray(SpriteVertexData::GenQuadVerts(), 6);

}

Sprite::Sprite(std::string& texturePath):Sprite()
{
	this->texture = new Texture2D(texturePath);
}

Sprite::~Sprite()
{
	delete(this->texture);
	delete(this->vertexArray);
}

void Sprite::Draw(const ShaderProgram& shader)
{
	shader.UseProgram();
	this->vertexArray->BindArray();
	int countTest = this->vertexArray->GetVertexCount();
	glDrawArrays(GL_TRIANGLES, 0, this->vertexArray->GetVertexCount());
	this->vertexArray->UnbindArray();
}
