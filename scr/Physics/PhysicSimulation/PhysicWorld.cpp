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

	getInstance().colisions.clear();
}

void SpriteRenderer::PhysicWorld::ColisionCheck()
{
	for (const auto& entry : *coliders)
	{
		entry.second->UpdateTransfrom();
	}

	for (auto it1 = coliders->begin(); it1 != coliders->end(); it1++)
	{
		for (auto it2 = std::next(it1); it2 != coliders->end(); it2++)
		{
			if (ColisionDetection::isColiding(*it1->second, *it2->second))
			{
				this->colisions.push_back({ it1->second.get() , it2->second.get(),it1->second.get()->originPosition - it2->second.get()->originPosition });
				//RENDER_LOG_MESSAGE_INFO("Colision");
			}
		}
	}
	
	
}
