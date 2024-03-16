#pragma once
#include"Rendererpch.h"
#include"TextureClass/TextureUnitManager.h"

namespace SpriteRenderer {
	enum TextureFiltering {
		LINEAR = GL_LINEAR,
		NEAREST = GL_NEAREST,
	};
	class Texture2D {

	public:
		Texture2D(const std::string& path, TextureFiltering filtering = LINEAR);
		~Texture2D();
	private:
		friend class TextureUnitManager;
	private:
		int width;
		int height;
		unsigned char* textSource;
		TextureFiltering filtering;
		GLenum textureType;
		uint32_t textureHandle = 0;
	private:
		void ReadTexture(const std::string& path);
	};
}