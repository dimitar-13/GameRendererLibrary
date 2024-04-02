#pragma once
#include"Component.h"
#include"Rendererpch.h"
namespace SpriteRenderer {
	//Component holding a tag/string of choice (Tags are not managed by a system).
	struct TagComponent :public Component {
		std::string tag;
	};
}