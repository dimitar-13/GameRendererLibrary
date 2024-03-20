#pragma once
#include"Rendererpch.h"
#include"Component.h"
namespace SpriteRenderer {
	class OrthographicCamera:public Component
	{
	public:
		glm::mat4& GetProjectionMatrix() { return this->projection; }
		void SetCameraProjDimentions(float left, 
			float right, 
			float bottom, 
			float top, 
			float near, 
			float far) {
			this->projection = glm::ortho(left, right, bottom, top, near, far);}
		bool UpdateProjectionOnWindowResize = true;
	private:
		glm::mat4 projection;
	};
};

