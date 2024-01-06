#include "Sprite.h"
#include<gl/glew.h>
#include<iostream>
#include"../../Debuging/OpenglDebug.h"

Sprite::Sprite()
{
	//this->vertexArray = new VertexArray();

	const float verts[] = {
		//Position   Color
		0.5f,0.5f	,0.0f,0.0f,0.0f,
		0.5f,-0.5	,0.0f,0.0f,0.0f,
		-0.5f,-0.5	,0.0f,0.0f,0.0f,

		-0.5f,-0.5	,0.0f,0.0f,0.0f,
		0.5f,0.5	,0.0f,0.0f,0.0f,
		-0.5f,0.5	,0.0f,0.0f,0.0f
	};				

	/*unsigned int VBO;
	GLCall(glGenBuffers(1, &VBO));
	
	this->vertexArray->BindArray();
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, VBO));
	GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW));
	

	this->vertexArray->UnbindArray();

	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));*/

}

void Sprite::Draw(ShaderProgram shader)
{
	shader.UseProgram();
	this->vertexArray->BindArray();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	this->vertexArray->UnbindArray();
}
