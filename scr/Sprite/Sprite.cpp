#include "Sprite.h"
#include<gl/glew.h>
#include<iostream>
#include"../../Debuging/OpenglDebug.h"
#include<vector>
Sprite::Sprite()
{

	Vertex vert;
	vert.Position = glm::vec3(0.5f, 0.5f, 0.0f);
	vert.Color = glm::vec3(0.0f, 0.0f, 0.0f);
	vert.UvCoords = glm::vec2(0.0f, 0.0);
	this->verts.push_back(vert);

	vert.Position = glm::vec3(0.5f, -0.5, 0.0f);
	vert.Color = glm::vec3(0.0f, 0.0f, 0.0f);
	vert.UvCoords = glm::vec2(0.0f, 0.0);
	this->verts.push_back(vert);

	vert.Position = glm::vec3(-0.5f, -0.5, 0.0f);
	vert.Color = glm::vec3(0.0f, 0.0f, 0.0f);
	vert.UvCoords = glm::vec2(0.0f, 0.0);
	this->verts.push_back(vert);

	vert.Position = glm::vec3(-0.5f, -0.5, 0.0f);
	vert.Color = glm::vec3(0.0f, 0.0f, 0.0f);
	vert.UvCoords = glm::vec2(0.0f, 0.0);
	this->verts.push_back(vert);

	vert.Position = glm::vec3(0.5f, 0.5, 0.0f);
	vert.Color = glm::vec3(0.0f, 0.0f, 0.0f);
	vert.UvCoords = glm::vec2(0.0f, 0.0);
	this->verts.push_back(vert);

	vert.Position = glm::vec3(-0.5f, 0.5, 0.0f);
	vert.Color = glm::vec3(0.0f, 0.0f, 0.0f);
	vert.UvCoords = glm::vec2(0.0f, 0.0);
	this->verts.push_back(vert);

	
	 //std::cout << sizeof(verts);
	this->vertexArray = new VertexArray(this->verts, 6);

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
	glDrawArrays(GL_TRIANGLES, 0, 1);
	this->vertexArray->UnbindArray();
}
