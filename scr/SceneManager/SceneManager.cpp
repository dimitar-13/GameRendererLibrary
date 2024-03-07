#include"Rendererpch.h"
#include"../../Core/Global.h"
#include"ECS/ECSManager.h"
#include"Physics/PhysicSimulation/PhysicWorld.h"
#include"Renderer/Renderer.h"
#include "SceneManager.h"
#include"ScriptSystem/ScriptSystem.h"
#include "Physics/Collision/CollisionSytstem.h"

void SpriteRenderer::SceneManager::Init()
{
}
void SpriteRenderer::SceneManager::Start()
{
	ECSManager::RegisterSystem<Renderer>();
	ECSManager::RegisterSystem<ScriptSystem>();
	ECSManager::RegisterSystem<PhysicWorld>();
	ECSManager::RegisterSystem<CollisionSystem>();

	ECSManager::GetSystemManager().InitSystems();

	RENDER_LOG_MESSAGE_INFO("Render loop was started.");
	
	instance.PipelineLoop();
}

void SpriteRenderer::SceneManager::PipelineLoop()
{
	Renderer::EnableDepthTest();
	uint32_t frameCounter = 0;
	double previousTime = glfwGetTime();
	double previousFrameTime = 0;
	while (!glfwWindowShouldClose(Global::winContext))
	{
		float time = (float)glfwGetTime();
		delta = time - (float)previousFrameTime;
		previousFrameTime = time;

		Renderer::Clear();
		glClearColor(0, 0, 1, 0);

		ECSManager::GetSystemManager().PreUpdate(delta.GetTimeInSeconds());
		ECSManager::GetSystemManager().Update(delta.GetTimeInSeconds());
		ECSManager::GetSystemManager().PostUpdate(delta.GetTimeInSeconds());
		
		glfwSwapBuffers(Global::winContext);
		glfwPollEvents();
		if (glfwGetTime() - previousTime >= 1.0)
		{
			previousTime = glfwGetTime();
			RENDER_LOG_MESSAGE_INFO("FPS:{0}", frameCounter);
			frameCounter = 0;
		}
		else
		{
			frameCounter += 1;
		}	
	}
}

void SpriteRenderer::SceneManager::Terminate()
{
	//TODO:Clear memory;
}
