#pragma once
#include"../scr/OpenglData/VertexData/Vertex.h"
#include<vector>
#include"../../Core/Global.h"
#include"iostream"
namespace SpriteRenderer {

	inline std::vector<Vertex>GenQuadVerts()
	{
        std::vector<Vertex> verts;

        const float UnitMeter = 0.5f;

        // First triangle (top-right, bottom-right, top-left)

        verts.push_back({ glm::vec2(UnitMeter, UnitMeter), glm::vec2(1.0f, 1.0f) });
        verts.push_back({ glm::vec2(UnitMeter, -UnitMeter), glm::vec2(1.0f, 0.0f) });
        verts.push_back({ glm::vec2(-UnitMeter, UnitMeter), glm::vec2(0.0f, 1.0f) });

        // Second triangle (top-left, bottom-right, bottom-left)
        verts.push_back({ glm::vec2(-UnitMeter, UnitMeter), glm::vec2(0.0f, 1.0f) });
        verts.push_back({ glm::vec2(UnitMeter, -UnitMeter), glm::vec2(1.0f, 0.0f) });
        verts.push_back({ glm::vec2(-UnitMeter, -UnitMeter), glm::vec2(0.0f, 0.0f) });

		return verts;
	}

}