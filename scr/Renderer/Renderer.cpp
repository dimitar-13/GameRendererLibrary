#include"Rendererpch.h"
#include "Renderer.h"
#include"Shader/ShaderProgram/ShaderProgram.h"
#include"Shader/ShadersContianer/Shaders.h"
#include"SceneManager/SceneManager.h"
void SpriteRenderer::Renderer::Init()
{
    m_instance.m_CustomShader = new ShaderProgram("../Renderer/Assets/Shaders/Color_shader.glsl");
    m_instance.m_CustomShader->UseProgram();
    m_instance.m_CustomShader->GetShaderUniformLocation("ModelMatrix");
    m_instance.m_CustomShader->GetShaderUniformLocation("ViewProjectionMatrix");
    m_instance.m_CustomShader->GetShaderUniformLocation("samplerTexture");
    m_instance.m_CustomShader->GetShaderUniformLocation("uColor");

    m_instance.m_CircleShader = new ShaderProgram("../Renderer/Assets/Shaders/Circle_shader.glsl");
    m_instance.m_CircleShader->UseProgram();
    m_instance.m_CircleShader->GetShaderUniformLocation("ModelMatrix");
    m_instance.m_CircleShader->GetShaderUniformLocation("ViewProjectionMatrix");
    m_instance.m_CircleShader->GetShaderUniformLocation("uColor");

    m_instance.m_SquareShader = new ShaderProgram("../Renderer/Assets/Shaders/Square_shader.glsl");
    m_instance.m_SquareShader->UseProgram();
    m_instance.m_SquareShader->GetShaderUniformLocation("ModelMatrix");
    m_instance.m_SquareShader->GetShaderUniformLocation("ViewProjectionMatrix");
    m_instance.m_SquareShader->GetShaderUniformLocation("uColor");
}

void SpriteRenderer::Renderer::IndexedDraw(const VertexArray& vertexArray)
{
}

void SpriteRenderer::Renderer::ArrayDraw(const VertexArray& vertexArray)
{
    vertexArray.BindArray();
    glDrawArrays(GL_TRIANGLES, 0, vertexArray.GetVertexCount());
    vertexArray.UnbindArray();
}

void SpriteRenderer::Renderer::Draw(const std::unordered_map<long long, std::shared_ptr<Sprite>>& sprites)
{
    for (const auto& sprite : sprites)
    {
        switch (sprite.second->m_shapeType)
        {
        case SPRITE_SHAPE_TYPE_CUBE:
            m_instance.m_SquareShader->UseProgram();
            m_instance.m_SquareShader->SetUniform4x4Matrix("ModelMatrix", SceneManager::GetGameObjectComponent<Transform>(sprite.first)->GetModelMatrix());
            m_instance.m_SquareShader->SetUniform4x4Matrix("ViewProjectionMatrix", SceneManager::GetAtctiveCamera().GetViewProjectionMatrix());
            m_instance.m_SquareShader->SetUniform3FloatVector("uColor", sprite.second->m_Color);
            break;
        case SPRITE_SHAPE_TYPE_CIRCLE:
            m_instance.m_CircleShader->UseProgram();
            m_instance.m_CircleShader->SetUniform4x4Matrix("ModelMatrix", SceneManager::GetGameObjectComponent<Transform>(sprite.first)->GetModelMatrix());
            m_instance.m_CircleShader->SetUniform4x4Matrix("ViewProjectionMatrix", SceneManager::GetAtctiveCamera().GetViewProjectionMatrix());
            m_instance.m_CircleShader->SetUniform2FloatVector("uOrigin", SceneManager::GetGameObjectComponent<Transform>(sprite.first)->m_Position);
            m_instance.m_CircleShader->SetUniform3FloatVector("uColor", sprite.second->m_Color);
            break;
        case SPRITE_SHAPE_TYPE_TRIANGLE:
            break;
        case SPRITE_SHAPE_TYPE_CUSTOM:
            break;
        }
      //Set up shaders
      //Issue draw call
        m_instance.ArrayDraw(*sprite.second->m_vertexArray);
    }
}

void SpriteRenderer::Renderer::DestroyShader()
{
    delete(m_instance.m_CustomShader);
    delete(m_instance.m_CircleShader);
    delete(m_instance.m_SquareShader);
}

