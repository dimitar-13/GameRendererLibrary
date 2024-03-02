#pragma once
#include"Rendererpch.h"
//#include"ScriptableObject/ScriptableObject.h"
//Wrapper for the generic Scripts that can be created
namespace SpriteRenderer {
	class ScriptableObject;
	class ScriptComponent {
	public:
		ScriptComponent() {};
		~ScriptComponent() { m_classInstance.~shared_ptr(); }
		std::shared_ptr<ScriptableObject> m_classInstance= nullptr;
		Entity entity;
		/// <summary>
		/// Attaches and instanciates a script class inheriting from ScriptableObject.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns>Handle(instance) of the script class.</returns>
		template<typename T>
		T* AttachScript();	
	};
	template<typename T>
	T* ScriptComponent::AttachScript() {
		static_assert(std::is_base_of<ScriptableObject, T>::value, "Script class must inherit of class 'ScriptableObject'");
		m_classInstance = std::make_shared<T>();
		//m_classInstance->gameObject->m_entity = entity;
		return std::static_pointer_cast<T>(m_classInstance).get();
	}

}