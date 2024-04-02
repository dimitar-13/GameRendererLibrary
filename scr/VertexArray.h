#pragma once
#include"Rendererpch.h"
#include"OpenglData/VertexData/Vertex.h"
namespace SpriteRenderer {

#pragma region Helper structs
	//Struct representing information for attribute data used in vertex array creation.
	struct AttributeData {
		//Location of the attribute in the vertex shader.
		uint32_t location;
		//Amount of elements per variable if vec2 then is 2 elements. 
		uint32_t attributeElementCount;
		//Type of attribute.
		GLenum attributeType;
		//Size of all the attributes.
		uint32_t sizeofVertex;
		//Offset of the current attribute.
		uint32_t offset;
	};
#pragma endregion

	//Helper class for creating vertex arrays.
	class VertexArray
	{
	public:
		//Binds the vertex array.
		void BindArray() const { glBindVertexArray(this->m_vertexArrayHandleID); }
		//Unbinds the vertex array.
		void UnbindArray()const { glBindVertexArray(0); }
		//Gets the vertex array handle.
		unsigned int GetVertexCount()const { return this->m_vertexCount; }
		//Creates vertex array.
		void CreateVertexArray(const std::vector< AttributeData>& vertexArrayLayour);
		/// <summary>
		///Binds a pre-defined buffer to the current array. 
		/// </summary>
		/// <param name="bufferHandle">Handle or Id of the buffer.</param>
		/// <param name="bufferType">Type of the buffer vertex,index ect.</param>
		void BindBufferToVertexArray(uint32_t bufferHandle, GLenum bufferType);
		~VertexArray();
		/// <summary>
		/// Generates a buffer and binds it to the vertex array.
		/// </summary>
		/// <param name="bufferTarget">Type of the buffer vertex,index ect.</param>
		/// <param name="buffSize">Size of the data to be send.If no data is provided then size of data to allocate.</param>
		/// <param name="data">Data to be uploaded to the buffer.If null than it will be an empty buffer.</param>
		/// <param name="bufferDataType">The type of the buffer static,dynamic etc..</param>
		void GenerateAndBindBufferToVertexArray(GLenum bufferType,
			uint32_t buffSize,void * data, GLenum bufferDataType);
		/// <summary>
		/// Send sub-data to specified buffer target.
		/// </summary>
		/// <param name="bufferTarget">Type of buffer if none attach no data will be uploaded.</param>
		/// <param name="offset">Offset of the buffer data(NOT the specified data but from where in the buffer to override the data).</param>
		/// <param name="dataSize">Size of the data to be uploaded.</param>
		/// <param name="data">Pointer to the start of the data.</param>
		void SendBufferSubData(GLenum bufferTarget,uint32_t offset,
			uint32_t dataSize, void * data);
	private:
		uint32_t m_vertexArrayHandleID;
		uint32_t m_elementBufferHandleID;
		uint32_t m_vertexBufferHandleID;
		uint32_t m_vertexCount;

	};
}