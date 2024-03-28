#pragma once
#include"ECS/ISystem.h"
namespace SpriteRenderer {
	class SystemManager;
	class ScriptSystem :public ISystem
	{
	private:
		friend class SystemManager;
		// Inherited via ISystem
		void Init() override;
		void PreUpdate(float dt) override;
		void Update(float dt) override;
		void PostUpdate(float dt) override;
		void DestroySystem() override;
	};
}


