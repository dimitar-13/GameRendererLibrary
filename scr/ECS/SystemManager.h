#pragma once
#include"ECS/ISystem.h"
#include"Rendererpch.h"
#include"Log/Log.h"
namespace SpriteRenderer {
	struct SystemComponentDependencies {
		std::uint32_t m_systemID;
		std::vector<const char*> m_componentsNames;
		template<typename T,typename... Ts>
		inline void AddDependecies(T component,Ts... components)
		{
			m_componentsNames.push_back(component);
			if constexpr (sizeof...(components) > 0)
			{
				AddDependecies(components...);
			}
		}
	};

	class SystemManager {
	public:
		template<typename T,typename... Ts>
		void RegisterSystem(Ts... componentsNames);
		void InitSystems();
		void PreUpdate(float dt);
		void Update(float dt);
		void PostUpdate(float dt);
		~SystemManager();
		std::vector<std::shared_ptr<ISystem>> m_systems;
		//std::vector<SystemComponentDependencies> m_systemComponentDependecies;

	};
	template<typename T, typename... Ts>
	inline void SystemManager::RegisterSystem(Ts... componentsNames)
	{
		static_assert(std::is_base_of<ISystem, T>::value, "System class must inherit of class 'ISystem'.");
		m_systems.push_back(std::make_shared<T>());
		/*SystemComponentDependencies systemDependencie{};
		systemDependencie.m_systemID = m_systems.size() - 1;
		if constexpr (sizeof...(componentsNames) > 0)
		{
		systemDependencie.AddDependecies(componentsNames...);
		}
		m_systemComponentDependecies.push_back(systemDependencie);
		*/
	}
}