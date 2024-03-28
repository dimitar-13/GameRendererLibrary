#pragma once
#include"ECS/ECSTypes.h"
namespace SpriteRenderer {
	class GameObject;
	template<typename T>
	class ComponentArray;

	/// <summary>
	/// Base class for components.Provides a way for the user to get the game object attached to this component.
	/// </summary>
	class Component {
	public:
		/// <summary>
		/// Gets the game object that is holding the component.
		/// </summary>
		/// <returns>Retruns a pointer to the game object that have this script attached.</returns>
		const GameObject *const GetGameObject() { return m_gameObject; }
	private:
		template<typename T>
		friend class ComponentArray;
		void SetGameObjectMember(GameObject* gameObj) {this->m_gameObject = gameObj; }
		GameObject* m_gameObject;
	};
}