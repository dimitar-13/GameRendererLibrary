#include"Rendererpch.h"
#include "SceneManager.h"
#include"../../Core/Global.h"
#include"GameObject/GameObject.h"
#include"Input/Input.h"
#include"Log/Log.h"
#include"Script/Script.h"
void SpriteRenderer::SceneManager::Init()
{
	Renderer::Init();
}
void SpriteRenderer::SceneManager::Start()
{
	RENDER_LOG_MESSAGE_INFO("Render loop was started.");
	

	for (auto& entry : instance.scripts)
	{
		for (size_t y = 0; y < entry.second.size(); y++)
			entry.second[y]->BindScript(entry.first);
	}
	instance.PipelineLoop();
}

void SpriteRenderer::SceneManager::Update()
{
	UpdateScripts();
}

void SpriteRenderer::SceneManager::UpdateTransform()
{

}

void SpriteRenderer::SceneManager::UpdateScripts()
{
	for (auto& entry : instance.scripts)
	{
		for (size_t y = 0; y < entry.second.size(); y++)
			entry.second[y]->OnUpdate();
	}
}

void SpriteRenderer::SceneManager::Draw(const ShaderProgram& shader)
{
	for (auto& entry :this->sprites)
	{
		shader.UseProgram();
		shader.SetUniform4x4Matrix("ModelMatrix", this->transforms[entry.first]->GetModelMatrix());
		shader.SetUniform4x4Matrix("ProjectionMatrix", *Global::projection);
		Renderer::ArrayDraw(this->sprites[entry.first]->GetVertexArray());
	}
}

void SpriteRenderer::SceneManager::PipelineLoop()
{
	Renderer::EnableDepthTest();

	uint32_t frameCounter = 0;
	double previousTime = glfwGetTime();
	while (!glfwWindowShouldClose(Global::winContext))
	{
		
		Renderer::Clear();
		glClearColor(1, 0, 0, 0);

		Update();
		
		Draw(Renderer::GetShader());

		glfwSwapBuffers(Global::winContext);
		glfwPollEvents();
	
		if (glfwGetTime() - previousTime >= 1.0f)
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
	instance.sceneObjects[result] = &gameobj;
	SceneManager::instance.idItterator += 1;
}

void SpriteRenderer::SceneManager::Terminate()
{
	//TODO:Clear memory;
}
