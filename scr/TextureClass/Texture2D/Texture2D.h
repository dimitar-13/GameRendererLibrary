#pragma once
#include<string>
#include<GL/glew.h>

namespace SpriteRenderer {
	enum TextureFiltering {
		LINEAR = GL_LINEAR,
		NEAREST = GL_NEAREST,
	};

	//struct TextureUnit {
	//	unsigned int textureUnit;
	//	bool isTextureUnitInUse = false;
	//};

	class Sprite;
	class SceneManager;

	class Texture2D {

	public:
		Texture2D(const std::string& path, TextureFiltering filtering = LINEAR);
		Texture2D(int width, int height, TextureFiltering filtering);
	private:
		friend class Sprite;
		friend class SceneManager;
		void BindTexture()const { glBindTexture(GL_TEXTURE_2D, this->textureHandle); }
		void UnBindTexture()const { glBindTexture(GL_TEXTURE_2D, 0); }


	private:
		int width;
		int height;
		uint32_t textureHandle;
		unsigned char* textSource;
	private:
		unsigned char* ReadTexture(const std::string& path);
	};
}