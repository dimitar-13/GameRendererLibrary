#include"Rendererpch.h"
#include "Texture2D.h"
#define STB_IMAGE_IMPLEMENTATION
#include<stb_image.h>
#include"Log.h"
SpriteRenderer::Texture2D::Texture2D(const std::string& path, TextureFiltering filtering)
{
	stbi_set_flip_vertically_on_load(true);
	ReadTexture(path);
	if (!textSource)
	{
		RENDER_LOG_MESSAGE_WARNING("Failed to read texture data of texture at:{0}", path);
	}
}

SpriteRenderer::Texture2D::~Texture2D()
{
	stbi_image_free(this->textSource);
}

void SpriteRenderer::Texture2D::ReadTexture(const std::string& path)
{
	int nrChannels;
	textSource = stbi_load(path.c_str(), &this->width, &this->height, &nrChannels, 4);
	this->textureType = nrChannels == 4? GL_RGBA : GL_RGB;
}
