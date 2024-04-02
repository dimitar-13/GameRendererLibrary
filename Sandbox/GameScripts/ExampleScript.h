#pragma once
#include"ScriptableObject.h"
class ExampleScript: public SpriteRenderer::ScriptableObject
{
	public:
		void OnStart()override;
		void OnUpdate()override;
		void OnDelete()override;

};