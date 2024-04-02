#include "Rendererpch.h"
#include "TextureUnitManager.h"
#include"Log/Log.h"
#include "Texture2D/Texture2D.h"
#include"../Assets/AssetPath.h"

void SpriteRenderer::TextureUnitManager::Init()
{
	auto& instance = GetInstance();
	instance.queryMaxTextureSlotsCount();
	instance.fillTextureSlotsArray();
}
void SpriteRenderer::TextureUnitManager::fillTextureSlotsArray()
{
	for (int i = 0; i < m_TextureSlots.maxTextureSlots; i++)
	{
		m_TextureSlots.m_textureUnitIndicies[i] = i;
	}
}

void SpriteRenderer::TextureUnitManager::queryMaxTextureSlotsCount()
{
	glGetIntegerv(GL_MAX_TEXTURE_UNITS, &m_TextureSlots.maxTextureSlots);
	Texture2D whiteTexture(AssetPathHelper::GetAssetPath()+"/Textures/WhiteTexture.png");
	registerTexture(&whiteTexture);
}

uint32_t SpriteRenderer::TextureUnitManager::registerTexture(Texture2D* textureToRegister)
{
	uint32_t currentCountIndex = m_TextureSlots.size;
	if (currentCountIndex >= m_TextureSlots.maxTextureSlots)
	{
		RENDER_LOG_MESSAGE_WARNING("No more slots left to assing to.");
		return 0;
	}
	uint32_t textureHandle;
	glGenTextures(1, &textureHandle);
	glBindTexture(GL_TEXTURE_2D, textureHandle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, textureToRegister->textureType, textureToRegister->width, textureToRegister->height, NULL, GL_RGBA, GL_UNSIGNED_BYTE, textureToRegister->textSource);
	glBindTexture(GL_TEXTURE_2D, 0);

	m_TextureSlots.m_textureUnits[currentCountIndex] = textureHandle;
	m_TextureSlots.m_textureHandleToIndex[textureHandle] = { currentCountIndex,1 };
	m_TextureSlots.size += 1;
	textureToRegister->textureHandle = textureHandle;
	return textureHandle;
}

uint32_t SpriteRenderer::TextureUnitManager::bindTexture(Texture2D* textureToRegister)
{
	if (textureToRegister->textureHandle != 0)
	{
		m_TextureSlots.m_textureHandleToIndex[textureToRegister->textureHandle].spriteBindCount++;
		return textureToRegister->textureHandle;
	}

	return this->registerTexture(textureToRegister);
}

void SpriteRenderer::TextureUnitManager::unBindTexture(uint32_t textureHandle)
{
	if (m_TextureSlots.m_textureHandleToIndex.find(textureHandle) == m_TextureSlots.m_textureHandleToIndex.end())
		return;

	m_TextureSlots.m_textureHandleToIndex[textureHandle].spriteBindCount--;
	if (!(m_TextureSlots.m_textureHandleToIndex[textureHandle].spriteBindCount <= 0))
		return;

	unRegisterTexture(textureHandle);
}

void SpriteRenderer::TextureUnitManager::unRegisterTexture(uint32_t textureHandle)
{
	if (textureHandle == 1)
		return;

	if (m_TextureSlots.size == 1)
	{
		glDeleteTextures(1, &textureHandle);
		m_TextureSlots.m_textureUnits[0] = 0;
		m_TextureSlots.size = 0;
		m_TextureSlots.m_textureHandleToIndex.clear();
		return;
	}
	if (m_TextureSlots.size == m_TextureSlots.m_textureHandleToIndex[textureHandle].index)
	{
		m_TextureSlots.m_textureUnits[m_TextureSlots.size] = 0;
		m_TextureSlots.m_textureHandleToIndex[textureHandle] = { 0,0 };
		--m_TextureSlots.size;
		return;
	}

	uint32_t indexOfTextureToRemove = m_TextureSlots.m_textureHandleToIndex[textureHandle].index;
	uint32_t indexOfLastTexutre = m_TextureSlots.size - 1;
	uint32_t lastTexture = m_TextureSlots.m_textureUnits[indexOfLastTexutre];

	glDeleteTextures(1, &textureHandle);
	m_TextureSlots.m_textureUnits[indexOfTextureToRemove] = m_TextureSlots.m_textureUnits[indexOfLastTexutre];
	m_TextureSlots.m_textureHandleToIndex[lastTexture].index = indexOfTextureToRemove;

	m_TextureSlots.m_textureUnits[indexOfLastTexutre] = 0;
	m_TextureSlots.m_textureHandleToIndex.erase(textureHandle);

	--m_TextureSlots.size;
}

void SpriteRenderer::TextureUnitManager::bindTextures()
{
	for (size_t i = 0; i < m_TextureSlots.size; i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D,m_TextureSlots.m_textureUnits[i]);
	}

}

void SpriteRenderer::TextureUnitManager::destroy()
{
	glDeleteTextures(m_TextureSlots.size, m_TextureSlots.m_textureUnits.data());
	RENDER_LOG_MESSAGE_SUCCESS("Texture unit manager deleted successfully.");
}

