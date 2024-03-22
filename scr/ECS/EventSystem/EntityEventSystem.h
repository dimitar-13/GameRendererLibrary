#pragma once
#include"Rendererpch.h"
namespace SpriteRenderer {
	class ECSEventMesanger
	{
		template<typename T>
		static void OnComponentArrayChanged();
		void OnEntityDeleted();



		/*template<typename T>
		static void ComponentRemoveCallback();
		template<typename T>
		static void ComponentAddedCallback(void(*callback)());*/
		static void(*callback)();

	};
	template<typename _ReturnType,typename... Args>
	class Event {

	public:
		void Invoke(Args... args);
		void operator+=(const std::function<_ReturnType(Args...)>& callback)
		{
			m_subscribers.push_back(callback);
		}
		void operator-=(const std::function<_ReturnType(Args...)>& callback)
		{
			for (size_t i = 0; i < m_subscribers.size(); i++)
			{
				if (m_subscribers[i].target< _ReturnType(Args...)>() == callback.target< _ReturnType(Args...)>())
				{
					m_subscribers.erase(m_subscribers.begin() + i);
					break;
				}
			}
		}
	private:
		std::vector<std::function<_ReturnType(Args...)>>m_subscribers;
	};
	template<typename _ReturnType, typename... Args>
	inline void Event<_ReturnType, Args...>::Invoke(Args... args)
	{
		for (const auto& function : m_subscribers)
		{
			function(args...);
		}
	}

	template<typename T>
	inline void ECSEventMesanger::OnComponentArrayChanged()
	{
		
	}



}