#pragma once
#include"Component.h"
#include"Rendererpch.h"
namespace SpriteRenderer {
	struct TagComponent :public Component {
		std::string tag;
	};
}