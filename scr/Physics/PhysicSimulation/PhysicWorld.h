#pragma once
#include"Rendererpch.h"
#include"Physics/PhysicBody.h"
#include"Physics/Collision/Colider.h"
#include"Physics/Collision/CollisionDetection.h"
#include"Physics/Collision/CollisionSolver.h"
#include"ECS/ISystem.h"
namespace SpriteRenderer
{
	class PhysicWorld : public ISystem
	{
	public:
		void ResolveColisions();
	private:
		const  glm::vec2 GRAVITY_FORCE = glm::vec2(0, -9.81f);
			std::vector<Entity> m_CollisionEntities;
		float time = 0;
	private:
		void ColisionCheck();

		void Init() override;
		void PreUpdate(float dt) override;
		void Update(float dt) override;
		void PostUpdate(float dt) override;
		void DestroySystem() override;
		void UpdatePhysics(PhysicBody& physicBodie, glm::vec2* position, float delta);
	};
}