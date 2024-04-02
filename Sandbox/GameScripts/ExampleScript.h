#pragma once
#include"ScriptableObject.h"
class ExampleScript:SpriteRenderer::ScriptableObject
{
	public:
		void OnStart()override;
		void OnUpdate()override;
		void OnDelete()override;

};