#pragma once
#include"Rendererpch.h"
namespace SpriteRenderer {
	class OrthographicCamera
	{
	public:
		glm::mat4& GetProjectionMatrix() { return this->projection; }
		void SetCameraProjDimentions(float left, 
			float right, 
			float bottom, 
			float top, 
			float near, 
			float far) {this->projection = glm::ortho(left, right, bottom, top, near, far);}
	public:
		//TODO:Think how to make it so when the window is resized the camera will recalculate the
		//matrix.
		bool ResizeOnWindowResize = false;
	private:
		glm::mat4 projection;
	};
};

