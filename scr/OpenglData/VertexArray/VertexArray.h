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
		void BindArray() const { glBindVertexArray(this->vertexArrayHandleID); };
		void UnbindArray()const { glBindVertexArray(0); }
		void DeleteVertexArray();

		unsigned int GetVertexCount()const { return this->vertexCount; }


	private:
		unsigned int vertexArrayHandleID;
		unsigned int vertexBufferHandleID;
		unsigned int elementBufferHandleID;

		unsigned int vertexCount;

	};
}