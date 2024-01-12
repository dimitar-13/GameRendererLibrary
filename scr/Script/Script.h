#pragma once
#include"../../scr/Renderer/Renderer.h"
#include"../../scr/ScriptableObject/ScriptableObject.h"
#include<vector>

class SceneManager;

class Script: public ScriptableObject
{
public:
	
	Script() { };
protected:
	friend class Renderer;
	
	virtual void OnUpdate(){ };
	virtual void OnStart(){ };
	virtual void OnDelete() { };
	//void AttachScript(const GameObject& gameObj_to_attach);

	//Get transform	
	//Encapsolate the values ingeneral

private:
	friend class SceneManager;
	//std::vector<GameObject*> attachedObjects;
	//void AttachScriptToObject(const GameObject& gameObj_to_attach) { this->AttachScriptToObject(gameObj_to_attach); }
	//void DetachScriptFromCurrentObj() { this->DetachValuesFromGameObject(); }

};