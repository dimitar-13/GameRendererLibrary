#pragma once
#include"Rendererpch.h"
#include"ECS/ISystem.h"
#include"Components/ColliderComponent.h"
#include"Physics/Collision/CollisionSolver.h"
#include"Physics/Collision/Colider.h"
#include"Physics/Collision/CollisionDetection.h"
namespace SpriteRenderer {
	class CollisionSystem:public ISystem {

	private:
		std::vector<Collision> collisions;
		ColisionSolver solver;
	private:
		void ResolveColisions();
		//void ColisionCheck();
	protected:
		// Inherited via ISystem
		void Init() override;
		void PreUpdate(float dt) override;
		void Update(float dt) override;
		void PostUpdate(float dt) override;
		void DestroySystem() override;
		void OnColliderArrayChanged();
	};
}