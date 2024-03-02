#pragma once
namespace SpriteRenderer {
	class EntitiyEventSystem
	{
		template<typename T>
		static void ComponentRemoveCallback();
		template<typename T>
		static void ComponentAddedCallback(void(*callback)());
		static void(*callback)();

	};
}