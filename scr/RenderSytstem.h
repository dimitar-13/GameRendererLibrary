#pragma once
#include"ECS/ISystem.h"
#include "Renderer/Renderer.h"
namespace SpriteRenderer {
	class SystemManager;

	class RenderSystem :public ISystem {
	private:
		friend class SystemManager;
		// Inherited via ISystem
		void Init() override;
		void PreUpdate(float dt) override;
		void Update(float dt) override;
		void PostUpdate(float dt) override;
		void DestroySystem() override;
		void OnComponentArrayChanged();
	private:
		static glm::mat4 CalculateModelMatrix(const Transform& spriteTransform);
		static glm::mat4 CalculateViewMatrix(const Transform& cameraTransform);
		Renderer m_renderer;
	};


}