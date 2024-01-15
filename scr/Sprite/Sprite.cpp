#include "Sprite.h"
#include<gl/glew.h>
#include<iostream>
#include"../../Debuging/OpenglDebug.h"
#include"../../../Core/SpriteData.h"
#include<vector>
Sprite::Sprite()
{

	
	this->Color = glm::vec3(1);

	
	 //std::cout << sizeof(verts);
	this->vertexArray = new VertexArray(SpriteVertexData::GenQuadVerts(), 6);

	/*unsigned int VBO;
	GLCall(glGenBuffers(1, &VBO));
	
	this->vertexArray->BindArray();
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, VBO));
	GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW));
	

	this->vertexArray->UnbindArray();

	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));*/

}

void Sprite::Draw(const ShaderProgram& shader)
{
	shader.UseProgram();
	this->vertexArray->BindArray();
	int countTest = this->vertexArray->GetVertexCount();
	glDrawArrays(GL_TRIANGLES, 0, this->vertexArray->GetVertexCount());
	this->vertexArray->UnbindArray();
}
