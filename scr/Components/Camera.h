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
			float far) {this->projection = glm::ortho(left, right, bottom, top, near, far);}
		void WindowSizeChanged(int width, int height) {
			float left, right, bottom, top, near, far;
			left = (float)-width / 2;
			right = (float)width / 2;
			bottom = (float)-height / 2;
			top = (float)height / 2;
			near = -1.0f;
			far = 1.0f;
			this->projection = glm::ortho<float>(left, right, bottom, top, near, far);
		}

	public:
		//TODO:Think how to make it so when the window is resized the camera will recalculate the
		//matrix.
		bool ResizeOnWindowResize = false;
	private:
		glm::mat4 projection;
	};
};

