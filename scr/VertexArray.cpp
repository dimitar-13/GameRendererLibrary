#include"Rendererpch.h"
#include "VertexArray.h"


SpriteRenderer::VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &this->m_vertexArrayHandleID);
	glDeleteBuffers(1, &this->m_vertexBufferHandleID);
	glDeleteBuffers(1, &this->m_elementBufferHandleID);
}

void SpriteRenderer::VertexArray::CreateVertexArray(const std::vector<AttributeData>& vertexArrayLayour)
{
	glGenVertexArrays(1, &this->m_vertexArrayHandleID);

	//Generates a vertex buffer and binds it because for the glVertexAttribPointer func to work 
	//properly it must have a non zero bound buffer read here: https://registry.khronos.org/OpenGL-Refpages/es2.0/xhtml/glVertexAttribPointer.xml

	glGenBuffers(1, &m_vertexBufferHandleID);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferHandleID);
	glBindVertexArray(this->m_vertexArrayHandleID);

	for (uint32_t i = 0; i < vertexArrayLayour.size(); i++)
	{
		glVertexAttribPointer(vertexArrayLayour[i].location,
			vertexArrayLayour[i].attributeElementCount, vertexArrayLayour[i].attributeType,
			GL_FALSE, vertexArrayLayour[i].sizeofVertex, (void*)vertexArrayLayour[i].offset);
		glEnableVertexAttribArray(vertexArrayLayour[i].location);

	}
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void SpriteRenderer::VertexArray::BindBufferToVertexArray(uint32_t bufferHandle, GLenum bufferType)
{
	glBindVertexArray(this->m_vertexArrayHandleID);
	glBindBuffer(bufferType, bufferHandle);
	glBindVertexArray(0);
	glBindBuffer(bufferType,0);


}

void SpriteRenderer::VertexArray::GenerateAndBindBufferToVertexArray(GLenum bufferType, 
	uint32_t buffSize,void * data, GLenum bufferDataType)
{
	if (bufferType == GL_ARRAY_BUFFER)
	{
		glBindBuffer(bufferType, this->m_vertexBufferHandleID);
		glBufferData(GL_ARRAY_BUFFER, buffSize, data, bufferDataType);

	}

	uint32_t buffer;
	glBindVertexArray(this->m_vertexArrayHandleID);
	glGenBuffers(1, &buffer);
	glBindBuffer(bufferType, buffer);
	glBufferData(bufferType, buffSize, data, bufferDataType);
	glBindVertexArray(0);
	glBindBuffer(bufferType, 0);

	this->m_elementBufferHandleID = bufferType == GL_ELEMENT_ARRAY_BUFFER ? buffer : 0;
}

void SpriteRenderer::VertexArray::SendBufferSubData(GLenum bufferTarget,
	uint32_t offset,uint32_t dataSize,
	void* data)
{
	uint32_t targetBufferID = bufferTarget == GL_ARRAY_BUFFER ? this->m_vertexBufferHandleID :
		this->m_elementBufferHandleID;
	glBindBuffer(bufferTarget, targetBufferID);
	glBufferSubData(bufferTarget, offset, dataSize, data);
	glBindBuffer(bufferTarget, 0);
}