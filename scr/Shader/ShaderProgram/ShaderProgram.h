#pragma once
#include"Rendererpch.h"
namespace SpriteRenderer {
	//Helper class for creating and using a shader program.
	class ShaderProgram
	{
	public:
		ShaderProgram(const char* vertexShader, const char* fragmentShader);
		ShaderProgram(const std::string& path);
		~ShaderProgram() { glDeleteProgram(this->m_programID); }
		void SetUniform3FloatVector(std::string Name, const glm::vec3& value)const;
		void SetUniform3Float(const char* Name, float value1, float value2, float value3)const;
		void SetUniform2FloatVector(std::string Name, const glm::vec2& value)const;	
		void SetUniformInt(const char* Name, int value)const;
		void SetUniform4x4Matrix(const char* Name, const glm::mat4& value)const;
		void SetUniformIntArray(const char* Name,uint32_t count, const int* value)const;
		void UseProgram()const { glUseProgram(this->m_programID); }
		int GetShaderUniformLocation(const char* Name) const;
	private:
		unsigned int m_programID;
		mutable std::unordered_map<std::string, uint32_t> m_shaderUniformCashe;

	private:
		int CompileShader(GLenum shaderType, const char* source);
		void CompileProgram(const std::vector<uint32_t>& shaders);
		void DetachAndDelete(const std::vector<uint32_t>& shaders);
		bool IsShaderCompiled(unsigned int shader);
		bool IsProgramCompiled();
		std::unordered_map<GLenum, std::string> ReadShaderSource(const std::string& path);
	};
}