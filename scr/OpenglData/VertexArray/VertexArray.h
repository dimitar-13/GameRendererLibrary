#pragma once
#include"Rendererpch.h"
#include"OpenglData/VertexData/Vertex.h"
namespace SpriteRenderer {

	struct AttributeData {
		uint32_t location;
		uint32_t attributeElementCount;
		GLenum attributeType;
		uint32_t sizeofVertex;
		uint32_t offset;
	};

	class VertexArray
	{
	public:
		void BindArray() const { glBindVertexArray(this->m_vertexArrayHandleID); }
		void UnbindArray()const { glBindVertexArray(0); }
		unsigned int GetVertexCount()const { return this->m_vertexCount; }
		void CreateVertexArray(const std::vector< AttributeData>& vertexArrayLayour);
		void BindBufferToVertexArray(uint32_t bufferHandle, GLenum bufferType);
		~VertexArray();
		void GenerateAndBindBufferToVertexArray(GLenum bufferType,
			uint32_t buffSize,void * data, GLenum bufferDataType);

		void SendBufferSubData(GLenum bufferTarget,uint32_t offset,
			uint32_t dataSize, void * data);
	private:
		unsigned int m_vertexArrayHandleID;
		unsigned int m_elementBufferHandleID;
		unsigned int m_vertexBufferHandleID;
		unsigned int m_vertexCount;

	};
}