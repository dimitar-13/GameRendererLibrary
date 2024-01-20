#pragma once
#include"../Shader/ShaderProgram/ShaderProgram.h"
#include"../OpenglData/VertexArray/VertexArray.h"
#include "../../Dependencies/GLM/glm.hpp"
#include "../../Dependencies/GLM/gtc/type_ptr.hpp"
#include "../../Dependencies/GLM/gtc/matrix_transform.hpp"
#include"../TextureClass/Texture2D/Texture2D.h"
#include<vector>

enum SpriteShape {

	CUBE =1,
	CIRCLE =2,
	TRIANGLE =3
};



class Sprite
{
public:
	Sprite();
	Sprite(std::string& texturePath);
	~Sprite();
	void Draw(const ShaderProgram& shader);
	const VertexArray& GetVertexArray() { return *this->vertexArray;}
	const glm::vec3 GetSpriteColor() { return this->Color; }
	glm::vec3 SetSpriteColor(glm::vec3 color) { return this->Color = color; }
	Texture2D* GetSpriteTexture()const { return this->texture; }

private:
	std::vector<Vertex> verts;
	VertexArray* vertexArray;
	glm::vec3 Color;
	Texture2D* texture;
	//Position

};