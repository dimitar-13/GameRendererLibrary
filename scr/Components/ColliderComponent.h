#pragma once
#include"Rendererpch.h"
#include"Physics/Collision/Colider.h"
#include<functional>
namespace SpriteRenderer {
	class ScriptableObject;
	struct ColliderComponent : public Component
	{
		std::shared_ptr<Collider> attachedCollider;

		std::function<void(ColliderComponent*)>OnCollisionStart;
		std::function<void(ColliderComponent*)> OnTriggerStart;

		std::function<void(ColliderComponent*)>OnCollisionExit;
		std::function<void(ColliderComponent*)> OnTriggerExit;

		template<typename T>
		void SetColliderType()
		{
			static_assert(std::is_base_of<Collider, T>::value, "Type must inherit from Collider!");
			attachedCollider = std::dynamic_pointer_cast<Collider>(std::make_shared<T>());
		}
	};


}