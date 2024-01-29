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

		OrthographicCamera(float left,float right,float bottom,float top,float near,float far, glm::vec3 Position = glm::vec3(0));

		glm::mat4& GetViewProjectionMatrix();
		glm::vec3& GetCameraPositionMatrix() { return this->position; }
		
	private:
		glm::vec3 position;
		glm::vec3 target;
		glm::mat4 lookAtMatrix;
		glm::mat4 projection;
		glm::mat4 viewProjection;

	private:
		void CalculateLookAtMatrix();

	};
};

