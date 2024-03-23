#include "Rendererpch.h"
#include "SystemManager.h"


void SpriteRenderer::SystemManager::InitSystems()
{
	for (size_t i = 0; i < this->m_systems.size(); i++)
	{
		m_systems[i]->Init();
	}
}

void SpriteRenderer::SystemManager::PreUpdate(float dt)
{
	for (size_t i = 0; i < this->m_systems.size(); i++)
	{
		m_systems[i]->PreUpdate(dt);
	}
}

void SpriteRenderer::SystemManager::Update(float dt)
{
	for (size_t i = 0; i < this->m_systems.size(); i++)
	{
		m_systems[i]->Update(dt);
	}
}

void SpriteRenderer::SystemManager::PostUpdate(float dt)
{
	for (size_t i = 0; i < this->m_systems.size(); i++)
	{
		m_systems[i]->PostUpdate(dt);
	}
}

SpriteRenderer::SystemManager::~SystemManager()
{
	for (uint32_t i = 0; i < m_systems.size(); i++)
	{
		m_systems[i]->DestroySystem();
	}
	m_systems.clear();
	RENDER_LOG_MESSAGE_SUCCESS("All systems were destroyed successfully.");
}
