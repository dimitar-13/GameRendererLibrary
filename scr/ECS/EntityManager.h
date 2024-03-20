#pragma once

#include"Rendererpch.h"
#include"ECS/ECSTypes.h"

namespace SpriteRenderer {
	class EntityManager
	{
	public:
		EntityManager();
		ECSTypes::Entity CreateEntity();
		void DestroyEntity(ECSTypes::Entity ent);
		void DestroyEntities();
	private:
		std::queue<ECSTypes::Entity> m_entitites{};
		uint32_t m_entityCount{};
	};
}

