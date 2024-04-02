#include "Rendererpch.h"
#include"ECS/ECSManager.h"
#include"ScriptableObject/ScriptableObject.h"
#include"Components/ScriptComponent.h"
#include "ScriptSystem.h"
void SpriteRenderer::ScriptSystem::Init()
{
	auto& scripts = ECSManager::GetComponentArray<ScriptComponent>();
	for (uint32_t i = 0; i < scripts.size; i++)
	{
		//scripts.componentArray[i]->m_classInstance->BindScriptToEntity(scripts.componentArray[i]->entity);
		const auto& func = std::bind(&ScriptableObject::OnDelete,scripts.componentArray[i]->m_classInstance.get());
		ECSManager::AddEventListenerOnEntityDeletion(func);
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
