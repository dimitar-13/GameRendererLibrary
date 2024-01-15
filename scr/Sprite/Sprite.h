#pragma once
#include"../Shader/ShaderProgram/ShaderProgram.h"
#include"../OpenglData/VertexArray/VertexArray.h"
#include "../../Dependencies/GLM/glm.hpp"
#include "../../Dependencies/GLM/gtc/type_ptr.hpp"
#include "../../Dependencies/GLM/gtc/matrix_transform.hpp"

#include<vector>

class Sprite
{
public:
	Sprite();
	void Draw(const ShaderProgram& shader);
	const VertexArray& GetVertexArray() { return *this->vertexArray;}
	const glm::vec3 GetSpriteColor() { return this->Color; }
	glm::vec3 SetSpriteColor(glm::vec3 color) { return this->Color = color; }


private:
	std::vector<Vertex> verts;
	VertexArray* vertexArray;
	glm::vec3 Color;
	//Position

};