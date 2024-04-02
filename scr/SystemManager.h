#pragma once
#include"ISystem.h"
#include"Rendererpch.h"
#include"Log.h"
namespace SpriteRenderer {
	/*struct SystemComponentDependencies {
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
	};*/
	
	class Scene;
	class ECSManager;

	//Class managing systems.
	class SystemManager {
	public:
		/// <summary>
		/// Adds a custom system.
		/// </summary>
		/// <typeparam name="T">System class must implement ISystem.</typeparam>
		/// <typeparam name="...Ts">Is obselate.</typeparam>
		/// <param name="...componentsNames">Is obselate</param>
		template<typename T,typename... Ts>
		void RegisterSystem(Ts... componentsNames);
	private:
		friend class Scene;
		friend class ECSManager;

		void InitSystems();
		void PreUpdate(float dt);
		void Update(float dt);
		void PostUpdate(float dt);
		void Destroy();
		std::vector<std::shared_ptr<ISystem>> m_systems;
		//std::vector<SystemComponentDependencies> m_systemComponentDependecies;

	};
	template<typename T, typename... Ts>
	inline void SystemManager::RegisterSystem(Ts... componentsNames)
	{
		static_assert(std::is_base_of<ISystem, T>::value, "System class must inherit of class 'ISystem'.");
		m_systems.push_back(std::make_shared<T>());
	}
}