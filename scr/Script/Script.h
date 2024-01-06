#pragma once
#include"../../scr/Renderer/Renderer.h"
#include"../../scr/ScriptableObject/ScriptableObject.h"
#include"../../scr/GameObject/GameObject.h"
#include<vector>
class Script: public ScriptableObject
{
public:
	

protected:
	friend class Renderer;
	Script(const GameObject& gameObj_to_attach) :ScriptableObject(gameObj_to_attach) { };
	virtual void OnUpdate(){ };
	virtual void OnStart(){ };
	virtual void OnDelete() { };
	ScriptableObject* object = 0;

	std::vector<GameObject*> attachedObjects;

	void AttachScript(const GameObject& gameObj_to_attach);

	//Get transform	
	//Encapsolate the values ingeneral



};