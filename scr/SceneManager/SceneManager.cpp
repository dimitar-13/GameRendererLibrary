#include "SceneManager.h"
#include"../../scr/Shader/ShadersContianer/Shaders.h"
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

void SceneManager::Draw()
{
	ShaderProgram shader = ShaderProgram(VertexShader, FragmentShader);

	/*for (size_t i = 0; i < this->sceneObjects.size(); i++)
	{
		sceneObjects[i]->sprite->Draw(shader);
	}*/

}
