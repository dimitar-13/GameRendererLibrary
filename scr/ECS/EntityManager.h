#pragma once

#include<iostream>
#include<array>
#include<queue>
#include<bitset>

using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 5000;
using ComponentType = std::uint8_t;
const ComponentType MAX_COMPONENTS = 32;
using Signature = std::bitset<MAX_COMPONENTS>;
namespace SpriteRenderer {
	class EntityManager
	{
	public:
		EntityManager();
		Entity CreateEntity();
		void DestroyEntity(Entity ent);
	private:
		std::queue< Entity> m_entitites{};
		uint32_t m_entityCount{};
	};
}

