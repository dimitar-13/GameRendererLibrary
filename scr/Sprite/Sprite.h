#pragma once
#include"Rendererpch.h"
#include"Shader/ShaderProgram/ShaderProgram.h"
#include"OpenglData/VertexArray/VertexArray.h"
#include <GLM/glm.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include"TextureClass/Texture2D/Texture2D.h"
namespace SpriteRenderer {
	enum SpriteShape {

		CUBE = 1,
		CIRCLE = 2,
		TRIANGLE = 3
	};

	class Sprite
	{
	public:
		Sprite();
		Sprite(std::string& texturePath);
		~Sprite();
		void Draw(const ShaderProgram& shader);
		long int gameObjID =-1;
	public:
		const VertexArray& GetVertexArray() { return *this->vertexArray; }
		const glm::vec3 GetSpriteColor() { return this->Color; }
		Texture2D* GetSpriteTexture()const { return this->texture; }
	public:
		glm::vec3 SetSpriteColor(glm::vec3 color) { return this->Color = color; }
		void SetTexture(const char* path) { this->texture = new Texture2D(path); }
	private:
		std::vector<Vertex> verts;
		VertexArray* vertexArray;
		glm::vec3 Color;
		Texture2D* texture;
	};
}