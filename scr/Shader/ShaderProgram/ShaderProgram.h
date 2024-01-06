#pragma once
#include<GL/glew.h>
#include<string>
#include"../../Debuging/OpenglDebug.h"

class ShaderProgram
{
public:
	ShaderProgram(const char * vertexShader,const char * fragmentShader);
	void SetUniform3FloatVector(std::string Name, float value[3]);
	void SetUniform3Float(const char* Name, float value1, float value2, float value3);
	void SetUniformInt(const char* Name, int value);
	void SetUniform4x4Matrix(const char* Name, float value);
	void UseProgram() { glUseProgram(this->programID);}
private:
	unsigned int programID;
	int CompileShader(GLenum shaderType,const char * source);
	bool IsShaderCompiled(unsigned int shader);
	int getShaderUniformLocation(const char * Name);
	
};