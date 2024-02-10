#pragma once
#include"Rendererpch.h"
#include"Physics/PhysicBody.h"
#include"Physics/Collision/Colider.h"
#include"Physics/Collision/CollisionDetection.h"
#include"Physics/Collision/CollisionSolver.h"
namespace SpriteRenderer
{
	class PhysicWorld
	{
	public:
		//static void AddPhysicalBody(std::shared_ptr<PhysicBody> physicBody) { insatnce.physicBodies.push_back(physicBody); }
		static void SetPhysicComponenets(std::unordered_map <long long, std::shared_ptr<PhysicBody>>* componentMap) { getInstance().physicComponents = componentMap; }
		static void SetColiderComponents(std::unordered_map <long long, std::shared_ptr<Collider>>* coliders) { getInstance().coliders = coliders; }

		static void UpdateWorld(float delta);
		void ResolveColisions();
	private:
		//std::vector<std::shared_ptr<PhysicBody>> physicBodies;
		std::unordered_map <long long, std::shared_ptr<PhysicBody>>* physicComponents;
		std::unordered_map <long long, std::shared_ptr<Collider>>* coliders;
		std::vector<Collision> collisions;
		ColisionSolver solver;
		float time = 0;
		static PhysicWorld insatnce;
		static PhysicWorld& getInstance() { return insatnce; }
	private:
		void ColisionCheck();
	};
	inline PhysicWorld PhysicWorld::insatnce;
}