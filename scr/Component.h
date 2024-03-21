#pragma once
#include"ECS/ECSTypes.h"
namespace SpriteRenderer {
	class GameObject;
	class IComponentArray;
	class Component {
	public:
		GameObject GetGameObj();
		ECSTypes::Entity entity = {};
		void SetGameObjectEntity(ECSTypes::Entity ent);
		void virtual OnEntityDeleted(){ };

	};

}