#pragma once
#include"Rendererpch.h"
#include"OpenglData/VertexData/Vertex.h"
#include"../../Core/Global.h"
namespace SpriteRenderer {
	class VertexArray
	{
	public:
		//For Testing purposes
		VertexArray(const std::vector<Vertex> verts, unsigned int count);
		void BindArray() const { glBindVertexArray(this->m_vertexArrayHandleID); };
		void UnbindArray()const { glBindVertexArray(0); }
		void DeleteVertexArray();

		unsigned int GetVertexCount()const { return this->m_vertexCount; }


	private:
		unsigned int m_vertexArrayHandleID;
		unsigned int m_vertexBufferHandleID;
		unsigned int m_elementBufferHandleID;

		unsigned int m_vertexCount;

	};
}