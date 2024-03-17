#pragma once
namespace SpriteRenderer {
	class GameObject;
	using Entity = std::uint32_t;
	struct Component {
		Entity entity;
		GameObject GetGameObj();
		void SetGameObjectEntity(Entity ent);
	};

}