#include"Rendererpch.h"
#include "SceneManager.h"
#include"../../Core/Global.h"
#include"Input/Input.h"
#include"Log/Log.h"
void SpriteRenderer::SceneManager::Init()
{
	Renderer::Init();
}
void SpriteRenderer::SceneManager::Start()
{
	RENDER_LOG_MESSAGE_INFO("Render loop was started.");
	for (size_t i = 0; i < instance.sceneObjects.size(); i++)
	{
		for (rsize_t y = 0; y < instance.sceneObjects[i]->attachedScripts.size(); y++)
		{
			instance.sceneObjects[i]->attachedScripts[y]->AttachValuesFromGameObject(*instance.sceneObjects[i]);
			instance.sceneObjects[i]->attachedScripts[y]->OnStart();
			instance.sceneObjects[i]->attachedScripts[y]->DetachValuesFromGameObject();
		}
	}
	instance.PipelineLoop();
}

void SpriteRenderer::SceneManager::Update()
{
	for (size_t i = 0; i < this->sceneObjects.size(); i++)
	{
		for (rsize_t y = 0; y < sceneObjects[i]->attachedScripts.size(); y++)
		{
		sceneObjects[i]->attachedScripts[y]->AttachValuesFromGameObject(*sceneObjects[i]);
		sceneObjects[i]->attachedScripts[y]->OnUpdate();
		sceneObjects[i]->attachedScripts[y]->DetachValuesFromGameObject();
		}
	}
}

void SpriteRenderer::SceneManager::Draw(const ShaderProgram& shader)
{
	//ShaderProgram shader = ShaderProgram(VertexShader, FragmentShader);

	for (size_t i = 0; i < this->sceneObjects.size(); i++)
	{
		if (this->sceneObjects[i]->sprite == 0)
			continue;

		shader.UseProgram();
		shader.SetUniform4x4Matrix("ModelMatrix", this->sceneObjects[i]->transform->GetModelMatrix());
		shader.SetUniform4x4Matrix("ProjectionMatrix", *Global::projection);
		Texture2D* texture = this->sceneObjects[i]->sprite->GetSpriteTexture();
		if (texture != NULL)
		{
			glActiveTexture(0);
			texture->BindTexture();
			shader.SetUniformInt("samplerTexture", 0);
		}
		//shader.SetUniform3FloatVector("uColor", this->sceneObjects[i]->sprite->GetSpriteColor());

		Renderer::ArrayDraw(this->sceneObjects[i]->sprite->GetVertexArray());
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