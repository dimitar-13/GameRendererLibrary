#pragma once
#include"Rendererpch.h"
#include"Physics/PhysicBody.h"
#include"Physics/Colision/Colider.h"
#include"Physics/Colision/ColisionDetection.h"
namespace SpriteRenderer
{
	class PhysicWorld
	{
	public:
		//static void AddPhysicalBody(std::shared_ptr<PhysicBody> physicBody) { insatnce.physicBodies.push_back(physicBody); }
		static void SetPhysicComponenets(std::unordered_map <long long, std::shared_ptr<PhysicBody>>* componentMap) { getInstance().physicComponents = componentMap; }
		static void UpdateWorld(float delta);
	private:
		//std::vector<std::shared_ptr<PhysicBody>> physicBodies;
		std::unordered_map <long long, std::shared_ptr<PhysicBody>>* physicComponents;
		std::unordered_map <long long, std::shared_ptr<Colider>> coliders;
		std::vector<Colision> colisions;

		float time = 0;
		static PhysicWorld insatnce;
		static PhysicWorld& getInstance() { return insatnce; }
	private:
		void ColisionCheck();
	};
	inline PhysicWorld PhysicWorld::insatnce;
}