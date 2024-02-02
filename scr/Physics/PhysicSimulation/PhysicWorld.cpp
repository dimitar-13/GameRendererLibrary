#include "Rendererpch.h"
#include "PhysicWorld.h"
#include"Log/Log.h"
void SpriteRenderer::PhysicWorld::UpdateWorld(float delta)
{
	for (auto& entry : *getInstance().physicComponents)
	{
		entry.second->UpdatePhysics(delta);
	}
}

void SpriteRenderer::PhysicWorld::ColisionCheck()
{
	for (auto& entry : coliders)
	{
		entry.second->UpdateTransfrom();
	}

	for (auto it1 = coliders.begin(); it1 != coliders.end(); it1++)
	{
		for (auto it2 = std::next(it1); it2 != coliders.end(); it2++)
		{
			if (ColisionDetection::isColiding(*it1->second.get(), *it2->second.get()))
			{
				//this->colisions.push_back({ *it1->second.get() , *it2->second.get() });
				RENDER_LOG_MESSAGE_INFO("Colision");
			}
		}
	}
	for (size_t i = 0; i < this->colisions.size(); i++)
	{
		//this->colisions[i]
	}
	
}
