#pragma once
#include<GL/glew.h>
#include<iostream>

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GlClearError();\
	x;\
	ASSERT(CheckForError(#x,__FILE__,__LINE__))

static void GlClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

static bool CheckForError(const char * function,const char * file, int line)
{
	while (GLenum error = glGetError())
	{	
		std::cout << "[OPENGL ERROR] function call :" << function << "in file:" << file << "line:" + line << "\nError:" << glewGetErrorString(error)<< std::endl;
		return false;
	}
	return true;
}