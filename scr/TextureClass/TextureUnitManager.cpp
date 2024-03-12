#include "Rendererpch.h"
#include "TextureUnitManager.h"
#include"Log/Log.h"
#include "Texture2D/Texture2D.h"

void SpriteRenderer::TextureUnitManager::Init()
{
	GetInstance().QuerryMaxTextureSlotsCount();
}
void SpriteRenderer::TextureUnitManager::QuerryMaxTextureSlotsCount()
{
	glGetIntegerv(GL_MAX_TEXTURE_UNITS, &m_TextureSlots.maxTextureSlots);
	Texture2D whiteTexture("D:/c++/OpenGl/SnakeGame/Renderer/Assets/Textures/WhiteTexture.png");
	//m_TextureSlots.lastTexureUnit = 1;
	registerTexture(&whiteTexture);

}

uint32_t SpriteRenderer::TextureUnitManager::registerTexture(Texture2D* textureToRegister)
{
	uint32_t currentCountIndex = m_TextureSlots.lastTexureUnit;
	if (currentCountIndex >= m_TextureSlots.maxTextureSlots)
	{
		RENDER_LOG_MESSAGE_WARNING("No more slots left to assing to.");
		return 0;
	}
	GLuint textureHandle;
	glGenTextures(1, &textureHandle);
	glBindTexture(GL_TEXTURE_2D, textureHandle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, textureToRegister->textureType, textureToRegister->width, textureToRegister->height, NULL, GL_RGBA, GL_UNSIGNED_BYTE, textureToRegister->textSource);
	glBindTexture(GL_TEXTURE_2D, 0);
	m_TextureSlots.m_textureUnits[currentCountIndex] = textureHandle;
	m_TextureSlots.lastTexureUnit += 1;
	textureToRegister->textureHandle = textureHandle;
	return currentCountIndex;
}

void SpriteRenderer::TextureUnitManager::unRegisterTexture(uint32_t textureLocationID)
{
	if (m_TextureSlots.lastTexureUnit == 1)
	{
		glDeleteTextures(1, &m_TextureSlots.m_textureUnits[textureLocationID]);
		m_TextureSlots.m_textureUnits[0] = 0;
		return;
	}
	uint32_t lastTextureIndex = m_TextureSlots.lastTexureUnit;
	glDeleteTextures(1, &m_TextureSlots.m_textureUnits[textureLocationID]);
	m_TextureSlots.m_textureUnits[textureLocationID] = m_TextureSlots.m_textureUnits[lastTextureIndex];

	--m_TextureSlots.lastTexureUnit;
}

void SpriteRenderer::TextureUnitManager::bindTextures()
{
	for (size_t i = 0; i < m_TextureSlots.lastTexureUnit; i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D,m_TextureSlots.m_textureUnits[i]);
	}

}

void SpriteRenderer::TextureUnitManager::destroy()
{
	glDeleteTextures(m_TextureSlots.lastTexureUnit, m_TextureSlots.m_textureUnits.data());
}

