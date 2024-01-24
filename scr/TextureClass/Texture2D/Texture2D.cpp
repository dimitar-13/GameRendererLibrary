#include"Rendererpch.h"
#include "Texture2D.h"
#define STB_IMAGE_IMPLEMENTATION
#include<stb_image.h>
#include"Log/Log.h"
SpriteRenderer::Texture2D::Texture2D(const std::string& path, TextureFiltering filtering)
{
	ReadTexture(path);
	if (textSource)
	{
		glGenTextures(1, &this->textureHandle);
		glBindTexture(GL_TEXTURE_2D, this->textureHandle);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, NULL, GL_RGB, GL_UNSIGNED_BYTE, textSource);
	}
	else
	{
		RENDER_LOG_MESSAGE_WARNING("Failed to read texture data of texture at:{0}", path);
		//Error
	}
	stbi_image_free(textSource);
}

SpriteRenderer::Texture2D::Texture2D(int width, int height, TextureFiltering filtering)
{
	this->width = width;
	this->height = height;
	glGenTextures(1, &this->textureHandle);
	glBindTexture(GL_TEXTURE_2D, this->textureHandle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filtering);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filtering);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
}

unsigned char* SpriteRenderer::Texture2D::ReadTexture(const std::string& path)
{
	int nrChannels;
	textSource = stbi_load(path.c_str(), &this->width, &this->height, &nrChannels, 3);
	if (textSource)
	{
		return textSource;
	}
}
