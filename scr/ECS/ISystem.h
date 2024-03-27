#pragma once
#include"ECS/ECSTypes.h"
#include"Rendererpch.h"
namespace SpriteRenderer {
	class SystemManager;
	class ISystem
	{
	protected:
		friend class SystemManager;
		virtual void Init() = 0;
		virtual void PreUpdate(float dt) = 0;
		virtual void Update(float dt) = 0;
		virtual void PostUpdate(float dt) = 0;
		virtual void DestroySystem() = 0;
		
		std::vector<ECSTypes::Entity> m_entities;
		std::uint32_t m_SystemEntitiesSize = 0;
	};
}