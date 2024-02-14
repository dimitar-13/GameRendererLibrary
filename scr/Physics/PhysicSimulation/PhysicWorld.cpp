#include "Rendererpch.h"
#include "PhysicWorld.h"
#include"Log/Log.h"
void SpriteRenderer::PhysicWorld::UpdateWorld(float delta)
{
	for (const auto& entry : *getInstance().physicComponents)
	{
		entry.second->UpdatePhysics(delta);
	}
	getInstance().ColisionCheck();
}

void SpriteRenderer::PhysicWorld::ResolveColisions()
{
	for (auto& collsion : this->collisions)
	{
	this->solver.SolveColision(collsion);
	}
	this->collisions.clear();
}

void SpriteRenderer::PhysicWorld::ColisionCheck()
{
	for (auto it1 = coliders->begin(); it1 != coliders->end(); it1++)
	{
		for (auto it2 = std::next(it1); it2 != coliders->end(); it2++)
		{
			//Get transform
			Transform test{};
			Transform test2{};

			if (it1->second.get()->TestForCollision(test,it2->second.get(), test2).isColliding)
			{
				this->collisions.push_back({ it1->second.get() , it2->second.get(),it1->second.get()->originPosition - it2->second.get()->originPosition });
				//RENDER_LOG_MESSAGE_INFO("Colision");
			}
		}
	}
	ResolveColisions();
	
}
