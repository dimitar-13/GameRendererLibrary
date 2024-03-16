#pragma once
#include"Rendererpch.h"
namespace SpriteRenderer {
	class Texture2D;
	struct TextureGPU {
		uint32_t index = 0;
		uint32_t spriteBindCount = 0;
	};
	struct TextureSlots {
		std::array<uint32_t, 32> m_textureUnits = {};
		uint32_t size =0;
		std::unordered_map<uint32_t, TextureGPU> m_textureHandleToIndex = {};

		std::array<int, 32> m_textureUnitIndicies = {};
		GLint maxTextureSlots = {};
	};
	
	class TextureUnitManager {
	public:
		/// <summary>
		/// Upload the texture data to the gpu and returns the handle of the texture object.
		/// If already uploaded it returns the handle of the texture object.
		/// </summary>
		/// <param name="textureToRegister">Texture to upload</param>
		/// <returns>Returns the handle of the texture object.</returns>
		static uint32_t BindTexture(Texture2D* textureToRegister) { return GetInstance().bindTexture(textureToRegister); }
		/// <summary>
		/// Returns the texture index that will be used to get the correct sampler at fragment shader stage.
		/// </summary>
		/// <param name="textureHandle">Handle of the texture object.</param>
		/// <returns>Returns the texture index.</returns>
		static uint32_t GetTexutreIndex(uint32_t textureHandle) { return GetInstance().m_TextureSlots.m_textureHandleToIndex[textureHandle].index; }

		/// <summary>
		/// Decrement the "spriteBindCount" of the texture. If spriteBindCount is 0 than it will delete the texture from GPU
		/// and free the texture slot.
		/// </summary>
		/// <param name="textureHandle">Texture object to be removed.</param>
		static void UnBindTexture(uint32_t textureHandle) { GetInstance().unBindTexture(textureHandle); }
		/// <summary>
		/// Removes the texture data from the gpu.
		/// </summary>
		/// <param name="textureHandle">Texture object to be removed.</param>
		static void UnRegisterTexture(uint32_t textureHandle) { GetInstance().unRegisterTexture(textureHandle); }
		static const TextureSlots& GetTextureSlotData() { return GetInstance().m_TextureSlots; }
		static void Init();
		/// <summary>
		/// Binds all the texture object to their respective texture units.
		/// </summary>
		static void BindTextures() { GetInstance().bindTextures();}
		static void Destroy() { GetInstance().destroy(); }
	private:
		void querryMaxTextureSlotsCount();
		uint32_t registerTexture(Texture2D* textureToRegister);
		uint32_t bindTexture(Texture2D* textureToRegister);
		void unBindTexture(uint32_t textureHandle);
		void unRegisterTexture(uint32_t textureHandle);
		void bindTextures();
		void destroy();
		void fillTextureSlotsArray();
		static TextureUnitManager& GetInstance() { return m_instance; }
	private:
		static TextureUnitManager m_instance;
		TextureSlots m_TextureSlots;
	};

	inline TextureUnitManager TextureUnitManager::m_instance;

}