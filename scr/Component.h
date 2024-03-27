#pragma once
#include"ECS/ECSTypes.h"
namespace SpriteRenderer {
	class GameObject;
	template<typename T>
	class ComponentArray;
	class Component {
	public:
		const GameObject *const GetGameObject() { return m_gameObject; }
	private:
		template<typename T>
		friend class ComponentArray;
		void SetGameObjectMember(GameObject* gameObj) {this->m_gameObject = gameObj; }
		GameObject* m_gameObject;
	};
}