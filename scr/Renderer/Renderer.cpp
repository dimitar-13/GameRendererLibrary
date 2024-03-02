#include"Rendererpch.h"
#include "Renderer.h"
#include"Shader/ShaderProgram/ShaderProgram.h"
#include"Shader/ShadersContianer/Shaders.h"
#include"SceneManager/SceneManager.h"
#include"ECS/ECSManager.h"
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

    //m_instance.m_entitySprites = &ECSManager::GetComponentArray<Sprite>();
    //m_instance.m_entityTransforms = &ECSManager::GetComponentArray<Transform>();
    m_instance.m_entities = ECSManager::GetComponentEntities<Sprite>();
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

void SpriteRenderer::Renderer::Draw()
{
    m_entities = ECSManager::GetComponentEntities<Sprite>();

    for (uint32_t i = 0 ; i < m_entities.size(); i++)
    {
        Transform* transform = ECSManager::GetComponent<Transform>(m_entities[i]);
        Sprite* sprite = ECSManager::GetComponent<Sprite>(m_entities[i]);;
        //ISystem::Unpack(m_instance.m_entities[i], transform,sprite);
        switch (sprite->m_shapeType)
        {
        case SPRITE_SHAPE_TYPE_CUBE:
            /*      m_instance.m_SquareShader->UseProgram();
                  m_instance.m_SquareShader->SetUniform4x4Matrix("ModelMatrix", ECSManager::GetInstance().GetComponent<Transform>(sprite.first)->GetModelMatrix());
                  m_instance.m_SquareShader->SetUniform4x4Matrix("ViewProjectionMatrix", SceneManager::GetAtctiveCamera().GetViewProjectionMatrix());
                  m_instance.m_SquareShader->SetUniform3FloatVector("uColor", ECSManager::GetInstance().GetComponent<Sprite>(sprite.first)->m_Color);
           */       break;
        case SPRITE_SHAPE_TYPE_CIRCLE:
                m_instance.m_CircleShader->UseProgram();
                m_instance.m_CircleShader->SetUniform4x4Matrix("ModelMatrix", transform->GetModelMatrix());
                m_instance.m_CircleShader->SetUniform4x4Matrix("ViewProjectionMatrix", SceneManager::GetAtctiveCamera().GetViewProjectionMatrix());
              //  m_instance.m_CircleShader->SetUniform2FloatVector("uOrigin", ECSManager::GetInstance().GetComponent<Transform>(sprite.first)->m_Position);
                m_instance.m_CircleShader->SetUniform3FloatVector("uColor", sprite->m_Color);
                break;
        case SPRITE_SHAPE_TYPE_TRIANGLE:
            break;
        case SPRITE_SHAPE_TYPE_CUSTOM:
            break;
        }
        //Set up shaders
        //Issue draw call
          ArrayDraw(*sprite->m_vertexArray);
    }
}

void SpriteRenderer::Renderer::PreUpdate(float dt)
{
}

void SpriteRenderer::Renderer::Update(float dt)
{
    Draw();
}

void SpriteRenderer::Renderer::PostUpdate(float dt)
{
}

void SpriteRenderer::Renderer::DestroySystem()
{
    delete(m_instance.m_CustomShader);
    delete(m_instance.m_CircleShader);
    delete(m_instance.m_SquareShader);
}

