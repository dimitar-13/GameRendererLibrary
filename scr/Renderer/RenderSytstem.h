#pragma once
#include"ECS/ISystem.h"
#include "Renderer/Renderer.h"
namespace SpriteRenderer {
	class RenderSysytem :public ISystem {
		// Inherited via ISystem
		void Init() override;
		void PreUpdate(float dt) override;
		void Update(float dt) override;
		void PostUpdate(float dt) override;
		void DestroySystem() override;
		const glm::mat4 CalculateModelMatrix(const Transform& spriteTransform);
		const glm::mat4 CalculateViewMatrix(const Transform& cameraTransform);
		Renderer m_renderer;
	};


}