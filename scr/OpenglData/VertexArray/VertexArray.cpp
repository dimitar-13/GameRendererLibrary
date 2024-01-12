#include "VertexArray.h"

#include<iostream>


VertexArray::VertexArray(std::vector<Vertex> &verts, unsigned int count)
{
	void* ref = &verts[0];

	glGenVertexArrays(1, &this->vertexArrayHandleID);
	glGenBuffers(1, &this->vertexBufferHandleID);
	//glGenBuffers(1, &this->elementBufferHandleID);
	if (count != 0)
	{


		glBindVertexArray(this->vertexArrayHandleID);

		glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferHandleID);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->elementBufferHandleID);

		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)* verts.size(), ref, GL_STATIC_DRAW);

		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);


		glVertexAttribPointer(0, 8, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 8, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 8, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, UvCoords));
		glEnableVertexAttribArray(2);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	}
	this->vertexCount = count;
	
}

void VertexArray::DeleteVertexArray()
{
}
