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
		std::vector<Collision> collisions;
		ColisionSolver solver;
		float time = 0;
	private:
		void ColisionCheck();

		void Init() override;
		void PreUpdate(float dt) override;
		void Update(float dt) override;
		void PostUpdate(float dt) override;
		void DestroySystem() override;
	};
}