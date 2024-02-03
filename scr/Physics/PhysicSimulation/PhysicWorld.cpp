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
	for (const auto& entry : getInstance().colisions)
	{
		if (entry.colider1->isTrigger || entry.colider2->isTrigger)
		{
			continue;
		}
		
				glm::vec3 newPos(0);
				glm::vec2 newColisionNormal;
			newColisionNormal = glm::vec2(entry.colider1->transform->t_Position - entry.colider2->transform->t_Position);
		if (entry.colider1->transform->t_Position != glm::vec3(entry.colider1->originPosition, 0))
		{
			if (glm::dot(newColisionNormal- entry.ColisionNormal,entry.ColisionNormal) <= 0)
			{
				newPos.x = entry.ColisionNormal.x == newColisionNormal.x ? entry.colider1->transform->t_Position.x : entry.colider1->originPosition.x;
				newPos.y = entry.ColisionNormal.y == newColisionNormal.y ? entry.colider1->transform->t_Position.y : entry.colider1->originPosition.y;

				entry.colider1->transform->t_Position =  glm::vec3(newPos);
			}
		}
		else if (entry.colider2->transform->t_Position != glm::vec3(entry.colider2->originPosition, 0))
		{
			float test = glm::dot(glm::normalize(-newColisionNormal + entry.ColisionNormal), glm::normalize(-entry.ColisionNormal));
			if (glm::dot(glm::normalize( - newColisionNormal + entry.ColisionNormal),glm::normalize(- entry.ColisionNormal)) <= 0)
			{
				newPos.x = entry.ColisionNormal.x == -newColisionNormal.x ? entry.colider2->transform->t_Position.x : entry.colider2->originPosition.x;
				newPos.y = entry.ColisionNormal.y == -newColisionNormal.y ? entry.colider2->transform->t_Position.y : entry.colider2->originPosition.y;

				entry.colider2->transform->t_Position = glm::vec3(newPos);
			}
		}
	}
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
