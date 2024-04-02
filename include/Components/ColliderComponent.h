#pragma once
#include"Rendererpch.h"
#include"Colider.h"
namespace SpriteRenderer {
	class ScriptableObject;
	//Wrapper struct for holding collider and callback functions.
	struct ColliderComponent : public Component
	{
		//Collider pointer.
		std::shared_ptr<Collider> attachedCollider;

		//Called on collision start.
		std::function<void(ColliderComponent*)>OnCollisionStart;
		//Called on trigger start.
		//This will get called even if the other component is collider.
		std::function<void(ColliderComponent*)> OnTriggerStart;
		//Called on collision exit.
		std::function<void(ColliderComponent*)>OnCollisionExit;
		//Called on trigger exit.
		//This will get called even if the other component is collider.
		std::function<void(ColliderComponent*)> OnTriggerExit;

		//Sets the collider to be used.
		template<typename T>
		void SetColliderType()
		{
			static_assert(std::is_base_of<Collider, T>::value, "Type must inherit from Collider!");
			attachedCollider = std::dynamic_pointer_cast<Collider>(std::make_shared<T>());
		}
	};


}