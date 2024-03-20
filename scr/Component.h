#pragma once
#include"ECS/ECSTypes.h"
namespace SpriteRenderer {
	class GameObject;
	struct Component {
		ECSTypes::Entity entity;
		GameObject GetGameObj();
		void SetGameObjectEntity(ECSTypes::Entity ent);
		void virtual OnEntityDeleted(){ };

	};

}