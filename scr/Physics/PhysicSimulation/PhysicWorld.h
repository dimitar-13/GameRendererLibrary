#pragma once
#include"Rendererpch.h"
#include"Components/PhysicBody.h"
#include"ECS/ISystem.h"
namespace SpriteRenderer
{
	class PhysicWorld : public ISystem
	{
	private:
		void Init() override;
		void PreUpdate(float dt) override;
		void Update(float dt) override;
		void PostUpdate(float dt) override;
		void DestroySystem() override;
		void UpdatePhysics(PhysicBody& physicBodie, glm::vec2* position, float delta);
	private:
		const glm::vec2 GRAVITY_FORCE = glm::vec2(0, -9.81f);
		std::vector<Entity> m_CollisionEntities;
	};
}