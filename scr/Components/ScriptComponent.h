#pragma once
#include"Rendererpch.h"
#include"Component.h"
//Wrapper for the generic Scripts that can be created
namespace SpriteRenderer {
	class ScriptableObject;
	class GameObject;
	class ScriptComponent:public Component
	{
	public:
		std::shared_ptr<ScriptableObject> m_classInstance= nullptr;
		/// <summary>
		/// Attaches and instanciates a script class inheriting from ScriptableObject.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns>Handle(instance) of the script class.</returns>
		template<typename T>
		T* AttachScript();
	private:
		friend class GameObject;
		void OnEntityDeleted()const;
	};
	template<typename T>
	T* ScriptComponent::AttachScript() {
		static_assert(std::is_base_of<ScriptableObject, T>::value, "Script class must inherit of class 'ScriptableObject'");
		m_classInstance = std::make_shared<T>();
		m_classInstance->BindScript(this->GetGameObject());
		//m_classInstance->gameObject->m_entity = entity;
		return std::static_pointer_cast<T>(m_classInstance).get();
	}
	inline void SpriteRenderer::ScriptComponent::OnEntityDeleted()const { m_classInstance->OnDelete(); }
}