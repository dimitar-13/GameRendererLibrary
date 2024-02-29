#include"Rendererpch.h"
#include "SceneManager.h"
#include"../../Core/Global.h"
#include"GameObject/GameObject.h"
#include"Input/Input.h"
#include"ScriptComponent.h"
#include"Camera/Camera.h"
#include"Physics/Collision/Colider.h"
#include"Physics/Collision/CollisionDetection.h"
#include"Physics/PhysicSimulation/PhysicWorld.h"
#include"ScriptSystem/ScriptSystem.h"
void SpriteRenderer::SceneManager::Init()
{
}
void SpriteRenderer::SceneManager::Start()
{
	ECSManager::RegisterSystem<Renderer>();
	ECSManager::RegisterSystem<ScriptSystem>();
	ECSManager::RegisterSystem<PhysicWorld>();
	ECSManager::GetSystemManager().InitSystems();

	RENDER_LOG_MESSAGE_INFO("Render loop was started.");
	
	instance.PipelineLoop();
}

void SpriteRenderer::SceneManager::Update()
{
	UpdateScripts();
}
void SpriteRenderer::SceneManager::UpdateScripts()
{
	/*auto& scripts = ECSManager::GetComponentArray<ScriptComponent>();

	for (uint32_t i = 0; i < scripts.size; i++)
	{
		scripts.componentArray[i]->m_classInstance->OnUpdate();
	}*/
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
		delta = time - previousFrameTime;
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
