#include "Rendererpch.h"
#include "PhysicWorld.h"
#include"Log/Log.h"
#include"SceneManager/SceneManager.h"
#include"ECS/ECSManager.h"

void SpriteRenderer::PhysicWorld::ColisionCheck()
{
	//for (auto it1 = coliders->begin(); it1 != coliders->end(); it1++)
	//{
	//	for (auto it2 = std::next(it1); it2 != coliders->end(); it2++)
	//	{
	//		//Get transform
	//		//I know its slow but cant think of better solution
	//		it2->second->UpdatePosition();
	//		it1->second->UpdatePosition();

	//		Collision collision = it1->second.get()->TestForCollision(it2->second.get());
	//		if (collision.isColliding)
	//		{
	//			this->collisions.push_back(collision);
	//			//RENDER_LOG_MESSAGE_INFO("Colision");
	//		}
	//	}
	//}
	//ResolveColisions();
	
}

void SpriteRenderer::PhysicWorld::Init()
{
}

void SpriteRenderer::PhysicWorld::PreUpdate(float dt)
{
}

void SpriteRenderer::PhysicWorld::Update(float dt)
{
	auto& physicsBodies = ECSManager::GetComponentArray<PhysicBody>();
	for (uint32_t i =0; i< physicsBodies.size;i++)
	{
		physicsBodies.componentArray[i]->UpdatePhysics(dt);
	}
	ColisionCheck();
}

void SpriteRenderer::PhysicWorld::PostUpdate(float dt)
{
	for (auto& collsion : this->collisions)
	{
		this->solver.SolveColision(collsion);
	}
	this->collisions.clear();
}

void SpriteRenderer::PhysicWorld::DestroySystem()
{
}
