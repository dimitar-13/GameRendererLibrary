#pragma once
#include"../scr/OpenglData/VertexData/Vertex.h"
#include<vector>
#include"../../Core/Global.h"
namespace SpriteVertexData {

	inline std::vector<SpriteRenderer::Vertex>GenQuadVerts()
	{
        std::vector<SpriteRenderer::Vertex> verts;

        const float test = 20;

        // First triangle (top-right, bottom-right, top-left)
        verts.push_back({ glm::vec2(test, test),  glm::vec2(1.0f, 1.0f) });
        verts.push_back({ glm::vec2(test, -test), glm::vec2(1.0f, 0.0f) });
        verts.push_back({ glm::vec2(-test, test), glm::vec2(0.0f, 1.0f) });

        // Second triangle (top-left, bottom-right, bottom-left)
        verts.push_back({ glm::vec2(-test, test),  glm::vec2(0.0f, 1.0f) });
        verts.push_back({ glm::vec2(test, -test),  glm::vec2(1.0f, 0.0f) });
        verts.push_back({ glm::vec2(-test, -test), glm::vec2(0.0f, 0.0f) });


		return verts;
	}

}