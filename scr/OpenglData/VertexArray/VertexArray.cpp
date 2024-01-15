#include "VertexArray.h"

#include<iostream>


VertexArray::VertexArray(const std::vector<Vertex> verts, unsigned int count)
{
	glGenVertexArrays(1, &this->vertexArrayHandleID);
	//glGenBuffers(1, &this->elementBufferHandleID);
	if (count != 0)
	{

		glBindVertexArray(this->vertexArrayHandleID);

		glGenBuffers(1, &this->vertexBufferHandleID);

		glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferHandleID);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->elementBufferHandleID);

		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)  * verts.size(), (void *) &verts[0], GL_STATIC_DRAW);

		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);


		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, UvCoords));
		glEnableVertexAttribArray(1);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	}
	this->vertexCount = verts.size();
	
}

void VertexArray::DeleteVertexArray()
{
}
