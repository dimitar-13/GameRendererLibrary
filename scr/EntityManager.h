#pragma once
#include"Rendererpch.h"
#include"ECSTypes.h"

namespace SpriteRenderer {
	class EntityManager
	{
	public:
		EntityManager();
		ECSTypes::Entity CreateEntity();
		void DestroyEntity(ECSTypes::Entity ent);
		void DestroyEntities();
	private:
		std::queue<ECSTypes::Entity> m_entities{};
		uint32_t m_entityCount{};
	};
}

