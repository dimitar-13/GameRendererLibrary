#pragma once
#include"Rendererpch.h"
#include"TextureUnitManager.h"

namespace SpriteRenderer {
#pragma region Enums
	//Enumerator for representing texture filtering for minification and magnification.
	enum TextureFiltering {
		LINEAR = GL_LINEAR,
		NEAREST = GL_NEAREST,
	};
#pragma endregion

	//Class for reading 2D textures.
	class Texture2D {

	public:
		/// <summary>
		/// Reads texture from path.
		/// </summary>
		/// <param name="path">Absolute path to the texture or relative to the current project.</param>
		/// <param name="filtering">Minification and magnification filtering options.</param>
		Texture2D(const std::string& path, TextureFiltering filtering = LINEAR);
		//Destroyers the texture and frees the pixel data.
		~Texture2D();
		//Returns the readonly width of the texture.
		const int GetTextureWidth()const { return width; }
		//Returns the readonly height of the texture.
		const int GetTextureHeight()const { return height; }
		//Returns the readonly pixel data of the texture.
		const unsigned char* const GetTextureSource()const { return textSource; }
	private:
		friend class TextureUnitManager;
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