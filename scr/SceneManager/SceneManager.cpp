#include "SceneManager.h"
#include"../../scr/Shader/ShadersContianer/Shaders.h"
#include"../../Core/Global.h"
void SceneManager::Start()
{
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

void SceneManager::Update()
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

void SceneManager::Draw(const ShaderProgram& shader)
{
	//ShaderProgram shader = ShaderProgram(VertexShader, FragmentShader);

	for (size_t i = 0; i < this->sceneObjects.size(); i++)
	{
		if (this->sceneObjects[i]->sprite == 0)
			continue;

		shader.UseProgram();
		shader.SetUniform4x4Matrix("ModelMatrix", this->sceneObjects[i]->transform->GetModelMatrix());
		shader.SetUniform4x4Matrix("ProjectionMatrix", *Global::projection);
		//shader.SetUniform3FloatVector("uColor", this->sceneObjects[i]->sprite->GetSpriteColor());

		this->renderer.ArrayDraw(this->sceneObjects[i]->sprite->GetVertexArray());
	}

}

void SceneManager::PipelineLoop()
{
	this->renderer.EnableDepthTest();
	while (!glfwWindowShouldClose(Global::winContext))
	{
		Update();

		this->renderer.Clear();
		glClearColor(1, 0, 0, 0);
		
		Draw(*this->renderer.mainShader);

		glfwSwapBuffers(Global::winContext);
		glfwPollEvents();
	}

	glfwTerminate();
	glfwDestroyWindow(Global::winContext);
}
