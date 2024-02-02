#pragma once
#include"Physics/Colision/Colider.h"
namespace SpriteRenderer {
	class ColisionDetection
	{
	public:
		static bool isColiding(const Colider& colider1, const Colider& colider2);
		static bool isColidingSAT(const Colider& colider1, const Colider& colider2);

	};
}

