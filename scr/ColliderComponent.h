#pragma once
#include"Rendererpch.h"
#include"Physics/Collision/Colider.h"
namespace SpriteRenderer {
	struct ColliderComponent
	{
		std::shared_ptr<Collider> attachedCollider;
		template<typename T>
		void SetColliderType()
		{
			static_assert(std::is_base_of<Collider, T>::value, "Type must inherit from Collider!");
			attachedCollider = std::dynamic_pointer_cast<Collider>(std::make_shared<T>());
		}
	};
}