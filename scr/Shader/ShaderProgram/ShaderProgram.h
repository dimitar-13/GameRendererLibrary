#pragma once
#include<GL/glew.h>
#include<string>
#include"../../Debuging/OpenglDebug.h"
#include <GLM/glm.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include<unordered_map>
namespace SpriteRenderer {
	class ShaderProgram
	{
	public:
		ShaderProgram(const char* vertexShader, const char* fragmentShader);
		ShaderProgram(const std::string& path);
		void SetUniform3FloatVector(std::string Name, const glm::vec3& value)const;
		void SetUniform3Float(const char* Name, float value1, float value2, float value3)const;
		void SetUniformInt(const char* Name, int value)const;
		void SetUniform4x4Matrix(const char* Name, const glm::mat4& value)const;
		void UseProgram()const { glUseProgram(this->programID); }
	private:
		unsigned int programID;
		mutable std::unordered_map<std::string, uint32_t> shaderUniformCashe;

	private:
		int CompileShader(GLenum shaderType, const char* source);
		void CompileProgram(const std::vector<uint32_t>& shaders);
		void DetachAndDelete(const std::vector<uint32_t>& shaders);
		bool IsShaderCompiled(unsigned int shader);
		bool IsProgramCompiled();
		int GetShaderUniformLocation(const char* Name) const;
		std::unordered_map<GLenum, std::string> ReadShaderSource(const std::string& path);
	};
}