#pragma once
#include"Rendererpch.h"
namespace SpriteRenderer {
	class Texture2D;
	struct TextureSlots {
		std::array<uint32_t, 32> m_textureUnits;
		GLint maxTextureSlots;
		uint32_t lastTexureUnit =0;
	};

	//GLint MAX_TEXTURE_SLOTS;

	class TextureUnitManager {
	public:
		static uint32_t RegisterTexture(Texture2D* textureToRegister) { return GetInstance().registerTexture(textureToRegister); }
		static void UnRegisterTexture(uint32_t textureLocationID) { GetInstance().unRegisterTexture(textureLocationID); }
		static TextureSlots& GetTextureSlotArray() { return GetInstance().m_TextureSlots; }
		static void Init();
		static void BindTextures() { GetInstance().bindTextures();}
		static void Destroy() { GetInstance().destroy(); }
	private:
		void QuerryMaxTextureSlotsCount();
		uint32_t registerTexture(Texture2D* textureToRegister);
		void unRegisterTexture(uint32_t textureLocationID);
		void bindTextures();
		void destroy();
		static TextureUnitManager& GetInstance() { return m_instance; }
	private:
		static TextureUnitManager m_instance;
		TextureSlots m_TextureSlots;
	};

	inline TextureUnitManager TextureUnitManager::m_instance;

}