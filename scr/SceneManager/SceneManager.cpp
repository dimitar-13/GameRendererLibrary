#include"Rendererpch.h"
#include "SceneManager.h"
#include"../../Core/Global.h"
#include"GameObject/GameObject.h"
#include"Input/Input.h"
#include"ScriptableObject/ScriptableObject.h"
#include"Camera/Camera.h"
#include"Physics/Collision/Colider.h"
#include"Physics/Collision/CollisionDetection.h"
#include"Physics/PhysicSimulation/PhysicWorld.h"

void SpriteRenderer::SceneManager::Init()
{
	Renderer::Init();
}
void SpriteRenderer::SceneManager::Start()
{
	RENDER_LOG_MESSAGE_INFO("Render loop was started.");
	
	//Instanciate scripts
	PhysicWorld::SetPhysicComponenets(&instance.physicBodies);
	PhysicWorld::SetColiderComponents(&instance.colliders);
	for (auto& entry : instance.scripts)
	{
		for (size_t y = 0; y < entry.second.size(); y++)
		{		
			entry.second[y]->BindScriptToObj(entry.first, instance.GetGameObjectByID(entry.first));
			entry.second[y]->OnStart();
		}
	}
	instance.PipelineLoop();
}

void SpriteRenderer::SceneManager::Update()
{
	UpdateScripts();
	//PhysicWorld::ResolveColisions();
	//PhysicsUpdate();
	//UpdateColisions();
}
void SpriteRenderer::SceneManager::UpdateScripts()
{
	for (auto& entry : instance.scripts)
	{
		for (size_t y = 0; y < entry.second.size(); y++)
			entry.second[y]->OnUpdate();
	}
}

void SpriteRenderer::SceneManager::UpdateColisions()
{
	/*for (auto& entry : instance.coliders)
	{
		entry.second->UpdateTransfrom();
	}

	for (auto it1 = coliders.begin(); it1 != coliders.end();it1++)
	{
		for (auto it2 = std::next(it1); it2 != coliders.end(); it2++)
		{
			if (CollisionDetection::isColiding(*it1->second.get(),*it2->second.get()))
			{
				RENDER_LOG_MESSAGE_INFO("Colision");
			}
		}
	}*/
}

void SpriteRenderer::SceneManager::PhysicsUpdate()
{
	for (auto& entry : instance.physicBodies)
	{
		//auto* transform = instance.getGameObjectComponent<Transform>(entry.first);
		//entry.second->UpdatePhysics(delta.GetTimeInSeconds(), transform->t_Position);
	}
}

//void SpriteRenderer::SceneManager::Draw(const ShaderProgram& shader)
//{
//	for (auto& entry :this->sprites)
//	{
//		//Need to able to draw circles and squres and maybe batch them together 
//		shader.UseProgram();
//		shader.SetUniform4x4Matrix("ModelMatrix", this->transforms[entry.first]->GetModelMatrix());
//		shader.SetUniform4x4Matrix("ViewProjectionMatrix", this->activeCamera->GetViewProjectionMatrix());
//		shader.SetUniformInt("samplerTexture", 1);
//		glActiveTexture(GL_TEXTURE1);
//		entry.second->GetSpriteTexture()->BindTexture();
//		Renderer::ArrayDraw(this->sprites[entry.first]->GetVertexArray());
//	}
//}

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

		Update();
		PhysicWorld::UpdateWorld(delta.GetTimeInSeconds());
		Renderer::Draw(this->sprites);
		//Draw(Renderer::GetShader());

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

void SpriteRenderer::SceneManager::GetGameObjectID(GameObject& gameobj)
{
	uint32_t result =  SceneManager::instance.idItterator;
	gameobj.objectID = result;
	instance.sceneObjects[result] = std::make_shared< GameObject>(gameobj);
	SceneManager::instance.idItterator += 1;
}

void SpriteRenderer::SceneManager::Terminate()
{
	//TODO:Clear memory;
}
