#include"Rendererpch.h"
#include"../../Core/Global.h"
#include"ECS/ECSManager.h"
#include"Physics/PhysicSimulation/PhysicWorld.h"
#include"Renderer/RenderSytstem.h"
#include "Scene.h"
#include"ScriptSystem/ScriptSystem.h"
#include "Physics/Collision/CollisionSytstem.h"
#include "TextureClass/TextureUnitManager.h"
#include "Window.h"
#include"ECS/EventSystem/EventSystem.h"
void SpriteRenderer::Scene::Init()
{
	TextureUnitManager::Init();
}
void SpriteRenderer::Scene::Start()
{
	ECSManager::RegisterSystem<RenderSystem>();
	ECSManager::RegisterSystem<ScriptSystem>();
	ECSManager::RegisterSystem<PhysicWorld>();
	ECSManager::RegisterSystem<CollisionSystem>();

	ECSManager::GetSystemManager().InitSystems();

	RENDER_LOG_MESSAGE_INFO("Render loop was started.");
	WindowSize winSize = MainWindow::GetWindowSize();
	instance.windowSizeChanged(winSize.winWidth,winSize.winHeight);
	instance.PipelineLoop();
}

void SpriteRenderer::Scene::PipelineLoop()
{
	Renderer::EnableDepthTest();
	uint32_t frameCounter = 0;
	double previousTime = glfwGetTime();
	double previousFrameTime = 0;
	while (!glfwWindowShouldClose(MainWindow::GetGLFWWindow()))
	{
		float time = (float)glfwGetTime();
		delta = time - (float)previousFrameTime;
		previousFrameTime = time;

		Renderer::Clear();
		glClearColor(0, 0, 1, 0);

		ECSManager::GetSystemManager().PreUpdate(delta.GetTimeInSeconds());
		ECSManager::GetSystemManager().Update(delta.GetTimeInSeconds());
		ECSManager::GetSystemManager().PostUpdate(delta.GetTimeInSeconds());
		
		glfwSwapBuffers(MainWindow::GetGLFWWindow());
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

void SpriteRenderer::Scene::windowSizeChanged(int newWidth, int newHeight)
{
	if (!this->activeCameraEntity->UpdateProjectionOnWindowResize)
		return;
	float left = (float)-newWidth / 2;
	float right = (float)newWidth / 2;
	float bottom = (float)-newHeight / 2;
	float top = (float)newHeight / 2;
	float near = -1.0f;
	float far = 1.0f;

	this->activeCameraEntity->SetCameraProjDimentions(left,right,bottom,top,near,far);
}

void SpriteRenderer::Scene::Terminate()
{
	//TODO:Clear memory;
}

