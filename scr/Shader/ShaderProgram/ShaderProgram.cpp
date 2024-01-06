#include "ShaderProgram.h"
#include<iostream>

ShaderProgram::ShaderProgram(const char* vertexShader, const char* fragmentShader)
{
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
	if (vs < 0 || fs < 0)
	{
		//throw error
	}
	else
	{
		this->programID = glCreateProgram();
		glAttachShader(programID, vs);
		glAttachShader(programID, fs);
		glLinkProgram(programID);
		glDetachShader(programID, vs);
		glDetachShader(programID, fs);
	}
	glDeleteShader(vs);
	glDeleteShader(fs);
	
	int status;
	glGetProgramiv(this->programID, GL_LINK_STATUS, &status);
	if (!status)
	{
		char infolog[225];
		glGetProgramInfoLog(this->programID, 255, 0, infolog);
		std::cout << "PROGRAM LINKING ERROR" << infolog << std::endl;
	}
}

void ShaderProgram::SetUniform3FloatVector(std::string Name, float value[3])
{
	GLCall(glUniform3fv(this->getShaderUniformLocation(Name.c_str()), 1, value));
}

void ShaderProgram::SetUniform3Float(const char* Name, float value1, float value2, float value3)
{
	GLCall(glUniform3f(this->getShaderUniformLocation(Name),value1,value2,value3));

}

void ShaderProgram::SetUniformInt(const char* Name, int value)
{
	glUniform1i(this->getShaderUniformLocation(Name), value);

}

void ShaderProgram::SetUniform4x4Matrix(const char* Name, float value)
{
	//glUniform3fv(this->getShaderUniformLocation(Name), 1, value);

}

int ShaderProgram::CompileShader(GLenum shaderType, const char* source)
{
	unsigned int shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &source, 0);
	glCompileShader(shader);
	if (!IsShaderCompiled(shader))
	{
		return -1;
	}

	return shader;
}

bool ShaderProgram::IsShaderCompiled(unsigned int shader)
{
	int status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (!status)
	{
		char infoLog[255];
		glGetShaderInfoLog(shader, 255, 0, infoLog);
		std::cout << infoLog;
		return false;
	}
	return true;
}

int ShaderProgram::getShaderUniformLocation(const char* Name)
{
	return glGetUniformLocation(this->programID,Name);
}
