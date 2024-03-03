#include"Rendererpch.h"
#include"ECS/ECSManager.h"
#include "Renderer.h"
#include"SceneManager/SceneManager.h"
#include"Shader/ShaderProgram/ShaderProgram.h"
#include"Metric/MetricHelper.h"
void SpriteRenderer::Renderer::Init()
{
    m_CustomShader = new ShaderProgram("../Renderer/Assets/Shaders/Color_shader.glsl");
    m_CustomShader->UseProgram();
    m_CustomShader->GetShaderUniformLocation("ModelMatrix");
    m_CustomShader->GetShaderUniformLocation("ViewProjectionMatrix");
    m_CustomShader->GetShaderUniformLocation("samplerTexture");
    m_CustomShader->GetShaderUniformLocation("uColor");

    m_CircleShader = new ShaderProgram("../Renderer/Assets/Shaders/Circle_shader.glsl");
    m_CircleShader->UseProgram();
    m_CircleShader->GetShaderUniformLocation("ModelMatrix");
    m_CircleShader->GetShaderUniformLocation("ViewProjectionMatrix");
    m_CircleShader->GetShaderUniformLocation("uColor");

    m_SquareShader = new ShaderProgram("../Renderer/Assets/Shaders/Square_shader.glsl");
    m_SquareShader->UseProgram();
    m_SquareShader->GetShaderUniformLocation("ModelMatrix");
    m_SquareShader->GetShaderUniformLocation("ViewProjectionMatrix");
    m_SquareShader->GetShaderUniformLocation("uColor");

    //m_instance.m_entitySprites = &ECSManager::GetComponentArray<Sprite>();
    //m_instance.m_entityTransforms = &ECSManager::GetComponentArray<Transform>();
    m_entities = ECSManager::GetComponentEntities<Sprite>();
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
        Sprite* sprite = ECSManager::GetComponent<Sprite>(m_entities[i]);
        Entity cameraEntity = SceneManager::GetAtctiveCamera();
        OrthographicCamera* camera = ECSManager::GetComponent<OrthographicCamera>(cameraEntity);
        Transform* cameraTransform = ECSManager::GetComponent<Transform>(cameraEntity);

        //ISystem::Unpack(m_instance.m_entities[i], transform,sprite);
        switch (sprite->m_shapeType)
        {
        case SPRITE_SHAPE_TYPE_CUBE:
                  m_SquareShader->UseProgram();
                  m_SquareShader->SetUniform4x4Matrix("ModelMatrix", CalculateModelMatrix(*transform));
                  m_SquareShader->SetUniform4x4Matrix("ViewProjectionMatrix", camera->GetProjectionMatrix()* CalculateViewMatrix(*cameraTransform));
                  m_SquareShader->SetUniform3FloatVector("uColor", sprite->m_Color);
                  break;
        case SPRITE_SHAPE_TYPE_CIRCLE:
                m_CircleShader->UseProgram();
                m_CircleShader->SetUniform4x4Matrix("ModelMatrix", CalculateModelMatrix(*transform));
                m_CircleShader->SetUniform4x4Matrix("ViewProjectionMatrix", camera->GetProjectionMatrix() * CalculateViewMatrix(*cameraTransform));
                m_CircleShader->SetUniform3FloatVector("uColor", sprite->m_Color);
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
    delete(m_CustomShader);
    delete(m_CircleShader);
    delete(m_SquareShader);
}

const glm::mat4 SpriteRenderer::Renderer::CalculateModelMatrix(const Transform& spriteTransform)
{
    glm::mat4 result(1);
	result = glm::translate(result, glm::vec3(spriteTransform.m_Position,0));

	result = glm::rotate(result, spriteTransform.m_Rotate.x, glm::vec3(1.0f, 0, 0));
	result = glm::rotate(result, spriteTransform.m_Rotate.y, glm::vec3(0, 1.0f, 0));

    result = glm::scale(result, glm::vec3(MetricHelper::GetUnitInMeters(spriteTransform.m_Scale.x),
		MetricHelper::GetUnitInMeters(spriteTransform.m_Scale.y),0));
	return result;
}

const glm::mat4 SpriteRenderer::Renderer::CalculateViewMatrix(const Transform& cameraTransform)
{
    glm::mat4 result(1);
    glm::vec3 DirVec = glm::vec3(0) - glm::vec3(cameraTransform.m_Position,0.1);
    glm::vec3 front = glm::length(DirVec) > 1 ? glm::normalize(DirVec) : DirVec;
    glm::vec3 tempUp(0, 1, 0);

    glm::vec3 right = glm::cross(front, tempUp);
    glm::vec3 up = glm::cross(right, front);

    right = glm::length(right) > 1 ? glm::normalize(right) : right;
    up = glm::length(up) > 1 ? glm::normalize(up) : up;

    result[0][0] = right.x;
    result[1][0] = right.y;
    result[2][0] = right.z;

    result[0][1] = up.x;
    result[1][1] = up.y;
    result[2][1] = up.z;
    
    result[0][2] = front.x;
    result[1][2] = front.y;
    result[2][2] = front.z;
    
    result[0][3] = -cameraTransform.m_Position.x;
    result[1][3] = -cameraTransform.m_Position.y;
    result[2][3] = -0.1;
    result = glm::mat4(1);
    //The target vector must have the same position as the camera exept the z so the camera doesnt
    //move on z and stays paralel to the x axie.
    result = glm::lookAt(glm::vec3(cameraTransform.m_Position,.1), glm::vec3(cameraTransform.m_Position,0), tempUp);
    return result;
}

