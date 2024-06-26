#pragma once
#include"Rendererpch.h"
namespace SpriteRenderer {
	/// <summary>
	/// Event class for creating and invoking events.
	/// </summary>
	/// <typeparam name="_ReturnType">Return type of the event.</typeparam>
	/// <typeparam name="..._Parameters"> Parameters of the event.</typeparam>
	template<typename _ReturnType,typename... _Parameters>
	class Event {
	public:
		//Calls all of the subscribers.
		void Invoke(_Parameters... args);
		void operator+=(const std::function<_ReturnType(_Parameters...)>& callback)
		{
			m_subscribers.push_back(callback);
		}

		void operator-=(const std::function<_ReturnType(_Parameters...)>& callback)
		{
			for (size_t i = 0; i < m_subscribers.size(); i++)
			{
				if (m_subscribers[i].target< _ReturnType(_Parameters...)>() == callback.target< _ReturnType(_Parameters...)>())
				{
					m_subscribers.erase(m_subscribers.begin() + i);
					break;
				}
			}
		}
	private:
		std::vector<std::function<_ReturnType(_Parameters...)>>m_subscribers;
	};
	template<typename _ReturnType, typename... _Parameters>
	inline void Event<_ReturnType, _Parameters...>::Invoke(_Parameters... params)
	{
		for (const auto& function : m_subscribers)
		{
			function(params...);
		}
	}
}