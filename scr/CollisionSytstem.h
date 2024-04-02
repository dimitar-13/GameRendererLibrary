#pragma once
#include"Rendererpch.h"
#include"Components/ColliderComponent.h"
#include"ISystem.h"
#include"Colider.h"
#include"CollisionDetection.h"
#include"CollisionSolver.h"
namespace SpriteRenderer {
	class SystemManager;
	class CollisionSystem: public ISystem {
	private:
		std::vector<Collision> collisions;
		CollisionSolver solver;
	private:
		void ResolveCollisions();
	protected:
		friend class SystemManager;
		// Inherited via ISystem
		void Init() override;
		void PreUpdate(float dt) override;
		void Update(float dt) override;
		void PostUpdate(float dt) override;
		void DestroySystem() override;
		void OnColliderArrayChanged();
	};
}