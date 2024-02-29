#pragma once
#include"ECS/ISystem.h"
namespace SpriteRenderer {
	class ScriptSystem :public ISystem
	{
		// Inherited via ISystem
		void Init() override;
		void PreUpdate(float dt) override;
		void Update(float dt) override;
		void PostUpdate(float dt) override;
		void DestroySystem() override;
	};
}


