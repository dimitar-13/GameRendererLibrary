#pragma once
#include"Transform/Transoform.h"
#include"Sprite/Sprite.h"
namespace SpriteRenderer {
	using Entity = std::uint32_t;
	class SystemManager;
	class ISystem
	{
	protected:
		friend class SystemManager;
		virtual void Init() = 0;
		virtual void PreUpdate(float dt) = 0;
		virtual void Update(float dt) = 0;
		virtual void PostUpdate(float dt) = 0;
		virtual void DestroySystem() = 0;
		//template<typename T, typename ...Ts>
		//static void Unpack(Entity entity, T*& pcomponent, Ts*& ...pcomponents);

		std::vector<Entity> m_entities;
		std::uint32_t m_SystemEntitiesSize = 0;
	};
	/*template <typename T, typename... Ts>
	inline void ISystem::Unpack(Entity entity, T*& pcomponent, Ts*&... pcomponents)
	{
		pcomponent = ECSManager::GetComponent<T>(entity);
		if constexpr (sizeof...(pcomponents) > 0)
		{
		Unpack(entity, pcomponents...);
		}
	}*/
}