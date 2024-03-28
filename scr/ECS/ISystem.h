#pragma once
#include"ECS/ECSTypes.h"
#include"Rendererpch.h"
namespace SpriteRenderer {
	class SystemManager;

	//Interface for creating ECS system classes.
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
	};
}