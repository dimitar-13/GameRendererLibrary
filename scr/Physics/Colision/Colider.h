#pragma once
#include "Rendererpch.h"
#include "Transform/Transoform.h"
namespace SpriteRenderer {
	struct Colider
	{
		glm::vec2 originPosition;
		std::vector<glm::vec2> points;
		glm::vec2 max;
		glm::vec2 min;

		float width,height;
		bool isTrigger = false;
		Transform * transform;
		Colider(Transform& objectTransform);
		void UpdateTransfrom();
	};
	struct Colision
	{
		Colider  *colider1, *colider2;
		glm::vec2 ColisionNormal;
	};
}