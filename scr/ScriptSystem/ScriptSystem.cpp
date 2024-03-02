#include "Rendererpch.h"
#include "ScriptSystem.h"
#include"ECS/ECSManager.h"
#include"ScriptableObject/ScriptableObject.h"
void SpriteRenderer::ScriptSystem::Init()
{
	auto& scripts = ECSManager::GetComponentArray<ScriptComponent>();
	for (uint32_t i = 0; i < scripts.size; i++)
	{
		scripts.componentArray[i]->m_classInstance->BindScriptToEntity(scripts.componentArray[i]->entity);
		scripts.componentArray[i]->m_classInstance->OnStart();
	}
}

void SpriteRenderer::ScriptSystem::PreUpdate(float dt)
{
}

void SpriteRenderer::ScriptSystem::Update(float dt)
{
	auto& scripts = ECSManager::GetComponentArray<ScriptComponent>();
	for (uint32_t i = 0; i < scripts.size; i++)
	{
		scripts.componentArray[i]->m_classInstance->OnUpdate();	
	}
}

void SpriteRenderer::ScriptSystem::PostUpdate(float dt)
{
}

void SpriteRenderer::ScriptSystem::DestroySystem()
{
	
}
