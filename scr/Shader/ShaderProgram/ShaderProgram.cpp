#include"Rendererpch.h"
#include"Log/Log.h"
#include "ShaderProgram.h"
SpriteRenderer::ShaderProgram::ShaderProgram(const char* vertexShader, const char* fragmentShader)
{
	std::vector<uint32_t> shaders;

	uint32_t vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	uint32_t fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
	shaders.push_back(vs);
	shaders.push_back(fs);

	if (vs == 0 || fs == 0)
	{
		//throw error
		RENDER_LOG_MESSAGE_ERROR("Shader failed to be created.Vertex shader id:{0}. Fragment shader id:{1}.",vs,fs);

	}
	else
	{
		CompileProgram(shaders);
		DetachAndDelete(shaders);
	}

	IsProgramCompiled();
	
}

SpriteRenderer::ShaderProgram::ShaderProgram(const std::string& path)
{
	std::unordered_map<GLenum, std::string> shader_sources = this->ReadShaderSource(path);
	std::vector<uint32_t> shaders;
	if (shader_sources.find(GL_VERTEX_SHADER) != shader_sources.end())
	{
		uint32_t shaderID = CompileShader(GL_VERTEX_SHADER, shader_sources[GL_VERTEX_SHADER].c_str());
		if(shaderID != 0)
			shaders.push_back(shaderID);
	}

	if (shader_sources.find(GL_FRAGMENT_SHADER) != shader_sources.end())
	{
		uint32_t shaderID = CompileShader(GL_FRAGMENT_SHADER, shader_sources[GL_FRAGMENT_SHADER].c_str());
		if (shaderID != 0)
			shaders.push_back(shaderID);
	}

	CompileProgram(shaders);
	DetachAndDelete(shaders);

	IsProgramCompiled();

}


void SpriteRenderer::ShaderProgram::CompileProgram(const std::vector<uint32_t>& shaders)
{
	this->m_programID = glCreateProgram();
	for (uint32_t shader : shaders)
	{
		glAttachShader(m_programID, shader);
	}
	glLinkProgram(m_programID);

	int status;
	glGetProgramiv(this->m_programID, GL_LINK_STATUS, &status);
	if (!status)
	{
		char infolog[225];
		glGetProgramInfoLog(this->m_programID, 255, 0, infolog);
		RENDER_LOG_MESSAGE_ERROR("Program linking error:Error{0}", infolog);
	}
}

void SpriteRenderer::ShaderProgram::DetachAndDelete(const std::vector<uint32_t>& shaders)
{
	for (uint32_t shader : shaders)
	{
		glDetachShader(m_programID, shader);
		glDeleteShader(shader);
	}
}

void SpriteRenderer::ShaderProgram::SetUniform3FloatVector(std::string Name, const glm::vec3& value) const
{
	glUniform3fv(this->GetShaderUniformLocation(Name.c_str()), 1, &value[0]);
}
void SpriteRenderer::ShaderProgram::SetUniform2FloatVector(std::string Name, const glm::vec2& value) const
{
	glUniform2fv(this->GetShaderUniformLocation(Name.c_str()), 1, &value[0]);
}

void SpriteRenderer::ShaderProgram::SetUniform3Float(const char* Name, float value1, float value2, float value3) const
{
	glUniform3f(this->GetShaderUniformLocation(Name),value1,value2,value3);

}

void SpriteRenderer::ShaderProgram::SetUniformInt(const char* Name, int value) const
{
	glUniform1i(this->GetShaderUniformLocation(Name), value);
}

void SpriteRenderer::ShaderProgram::SetUniform4x4Matrix(const char* Name, const glm::mat4& value) const
{
	glUniformMatrix4fv(this->GetShaderUniformLocation(Name), 1,GL_FALSE, glm::value_ptr(value));
}

void SpriteRenderer::ShaderProgram::SetUniformIntArray(const char* Name, uint32_t count, const int* value) const
{
	glUniform1iv(this->GetShaderUniformLocation(Name), count, value);
}

int SpriteRenderer::ShaderProgram::CompileShader(GLenum shaderType, const char* source)
{
	unsigned int shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &source, 0);
	glCompileShader(shader);
	if (!IsShaderCompiled(shader))
	{
		glDeleteShader(shader);
		return 0;
	}

	return shader;
}


bool SpriteRenderer::ShaderProgram::IsShaderCompiled(unsigned int shader)
{
	int status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (!status)
	{
		char infoLog[255];
		glGetShaderInfoLog(shader, 255, 0, infoLog);
		RENDER_LOG_MESSAGE_ERROR("Shader compile error:Error{0}", infoLog);
		return false;
	}
	return true;
}

bool SpriteRenderer::ShaderProgram::IsProgramCompiled()
{
	int status;
	glGetProgramiv(this->m_programID, GL_LINK_STATUS, &status);
	if (!status)
	{
		char infolog[225];
		glGetProgramInfoLog(this->m_programID, 255, 0, infolog);
		RENDER_LOG_MESSAGE_ERROR("Program compile error:Error{0}", infolog);
		return false;
	}
	RENDER_LOG_MESSAGE_INFO("Shader program with id:'{0}' was compiled successfully.",this->m_programID);
	return true;
}

int SpriteRenderer::ShaderProgram::GetShaderUniformLocation(const char* Name)const
{
	if (this->m_shaderUniformCashe.find(Name) != m_shaderUniformCashe.end())
		return this->m_shaderUniformCashe[Name];

	int result = glGetUniformLocation(this->m_programID, Name);
	if (result < 0)
	{
		//RENDER_LOG_MESSAGE_WARNING("Cant find uniform with name:{0}",  Name);
		return -1;
	}
	this->m_shaderUniformCashe[Name] = result;
	return result;
}

 std::unordered_map<GLenum,std::string> SpriteRenderer::ShaderProgram::ReadShaderSource(const std::string& path)
{
	std::ifstream file(path);
	std::string line;
	std::unordered_map<GLenum, std::string> shaderSourceHash;
	GLenum currentShaderSource;
	if(file)
	{
		while (std::getline(file, line))
		{
			if (line.find("#Shader_type") != std::string::npos)
			{
				if (line.find("vertex") != std::string::npos)
				{
					currentShaderSource = GL_VERTEX_SHADER;
					shaderSourceHash[GL_VERTEX_SHADER] = "";
				}
				else if (line.find("fragment") != std::string::npos)
				{
					currentShaderSource = GL_FRAGMENT_SHADER;
					shaderSourceHash[GL_FRAGMENT_SHADER] = "";
				}
				else
				{
					currentShaderSource = GL_NONE;
				}
			}
			else
			{
				if (currentShaderSource == GL_NONE)
					continue;

				shaderSourceHash[currentShaderSource] += line + '\n';
			}
		}
	}
	file.close();
	return shaderSourceHash;
}
