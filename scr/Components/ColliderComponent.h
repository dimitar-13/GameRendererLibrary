#pragma once
#include"Rendererpch.h"
#include"Physics/Collision/Colider.h"
#include<functional>
namespace SpriteRenderer {
	class ScriptableObject;
	struct ColliderComponent : public Component
	{
		std::shared_ptr<Collider> attachedCollider;

		std::function<void(Collider*)>OnCollisionStart;
		std::function<void(Collider*)> OnTriggerStart;

		std::function<void(Collider*)>OnCollisionExit;
		std::function<void(Collider*)> OnTriggerExit;

		template<typename T>
		void SetColliderType()
		{
			static_assert(std::is_base_of<Collider, T>::value, "Type must inherit from Collider!");
			attachedCollider = std::dynamic_pointer_cast<Collider>(std::make_shared<T>());
		}
	};


}