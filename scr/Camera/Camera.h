#pragma once
#include"Rendererpch.h"
namespace SpriteRenderer {

	enum CameraDirection {
		RIGHT =1,
		LEFT  =2,
		UP	  =3,
		DOWN  =4,
		FRONT =6,
		BACK  =7
	};

	class OrthographicCamera
	{
	public:
		glm::mat4& GetViewProjectionMatrix();
		glm::vec3& GetCameraPositionMatrix() { return this->position; }
		void SetCameraProjDimentions(float left, 
			float right, 
			float bottom, 
			float top, 
			float near, 
			float far) {this->projection = glm::ortho(left, right, bottom, top, near, far);}
	public:
		bool ResizeOnWindowResize = false;
	private:
		glm::vec3 position = glm::vec3(0,0,0.1);
		glm::mat4 lookAtMatrix;
		glm::mat4 projection;
		glm::mat4 viewProjection;

	private:
		void CalculateLookAtMatrix();

	};
};

