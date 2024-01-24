#include"Rendererpch.h"
#include "SceneManager.h"
#include"Shader/ShadersContianer/Shaders.h"
#include"../../Core/Global.h"
#include"Input/Input.h"
#include"Log/Log.h"
void SpriteRenderer::SceneManager::Start()
{
	RENDER_LOG_MESSAGE_INFO("Render loop was started.");
	for (size_t i = 0; i < this->sceneObjects.size(); i++)
	{
		for (rsize_t y = 0; y < sceneObjects[i]->attachedScripts.size(); y++)
		{
			sceneObjects[i]->attachedScripts[y]->AttachValuesFromGameObject(*sceneObjects[i]);
			sceneObjects[i]->attachedScripts[y]->OnStart();
			sceneObjects[i]->attachedScripts[y]->DetachValuesFromGameObject();
		}
	}
	PipelineLoop();
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

		this->renderer.ArrayDraw(this->sceneObjects[i]->sprite->GetVertexArray());
	}

}

void SpriteRenderer::SceneManager::PipelineLoop()
{
	this->renderer.EnableDepthTest();
	while (!glfwWindowShouldClose(Global::winContext))
	{
		this->renderer.Clear();
		glClearColor(1, 0, 0, 0);

		Update();
		
		Draw(*this->renderer.mainShader);

		glfwSwapBuffers(Global::winContext);
		glfwPollEvents();
	}
}

void SpriteRenderer::SceneManager::onUpdateCallback(void(*func_ptr)())
{
	(*func_ptr)();
}
