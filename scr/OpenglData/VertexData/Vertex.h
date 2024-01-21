#pragma once
#include <GLM/glm.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include"../../Core/Global.h"
namespace SpriteRenderer {
	struct Vertex {
		//Position
		glm::vec3 Position;
		//Uv coords
		glm::vec2 UvCoords;
	};

}
