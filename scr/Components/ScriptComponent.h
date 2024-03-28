#pragma once
#include"Rendererpch.h"
#include"Component.h"
namespace SpriteRenderer {
	class ScriptableObject;
	class GameObject;

	/// <summary>
	/// Wrapper class used for attaching scripts to game objects.
	/// </summary>
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
		/// <summary>
		/// Calls script OnDelete function.
		/// </summary>
		void OnEntityDeleted()const;
	};
	template<typename T>
	T* ScriptComponent::AttachScript() {
		static_assert(std::is_base_of<ScriptableObject, T>::value, "Script class must inherit of class 'ScriptableObject'");
		m_classInstance = std::make_shared<T>();
		m_classInstance->BindScript(this->GetGameObject());
		return std::static_pointer_cast<T>(m_classInstance).get();
	}
	inline void SpriteRenderer::ScriptComponent::OnEntityDeleted()const { m_classInstance->OnDelete(); }
}