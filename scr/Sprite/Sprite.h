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
	void Draw(ShaderProgram shader);
	

private:
	std::vector<Vertex> verts;
	VertexArray* vertexArray;

	//Position

};