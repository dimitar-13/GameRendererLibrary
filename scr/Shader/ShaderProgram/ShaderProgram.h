#pragma once
#include<GL/glew.h>
#include<string>
#include"../../Debuging/OpenglDebug.h"
#include "../../Dependencies/GLM/glm.hpp"
#include "../../Dependencies/GLM/gtc/type_ptr.hpp"
#include "../../Dependencies/GLM/gtc/matrix_transform.hpp"
#include<unordered_map>

class ShaderProgram
{
public:
	ShaderProgram(const char * vertexShader,const char * fragmentShader);
	void SetUniform3FloatVector(std::string Name,const glm::vec3& value)const;
	void SetUniform3Float(const char* Name, float value1, float value2, float value3)const;
	void SetUniformInt(const char* Name, int value)const;
	void SetUniform4x4Matrix(const char* Name, const glm::mat4& value)const;
	void UseProgram()const { glUseProgram(this->programID);}
private:
	unsigned int programID;
	int CompileShader(GLenum shaderType,const char * source);
	bool IsShaderCompiled(unsigned int shader);
	int GetShaderUniformLocation(const char * Name) const;
	
	mutable std::unordered_map<std::string, uint32_t> shaderUniformCashe;

};