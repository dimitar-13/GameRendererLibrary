#include "Rendererpch.h"
#include "RenderSytstem.h"
#include "ECS/ECSManager.h"
#include "SceneManager/SceneManager.h"
#include "Metric/MetricHelper.h"
void SpriteRenderer::RenderSysytem::Init()
{
    m_entities = ECSManager::GetComponentEntities<Sprite>();
}

void SpriteRenderer::RenderSysytem::PreUpdate(float dt)
{
    m_entities = ECSManager::GetComponentEntities<Sprite>();
}

void SpriteRenderer::RenderSysytem::Update(float dt)
{
    Entity cameraEntity = SceneManager::GetAtctiveCamera();
    OrthographicCamera* camera = ECSManager::GetComponent<OrthographicCamera>(cameraEntity);
    for (uint32_t i = 0; i < m_entities.size(); i++)
    {
        Transform* transform = ECSManager::GetComponent<Transform>(m_entities[i]);
        Sprite* sprite = ECSManager::GetComponent<Sprite>(m_entities[i]);   
        glm::mat4 spriteModelMatrix = CalculateModelMatrix(*transform);
        Transform* cameraTransform = ECSManager::GetComponent<Transform>(cameraEntity);
        glm::mat4 viewProjMatrix = camera->GetProjectionMatrix() * CalculateViewMatrix(*cameraTransform);

        m_renderer.SubmitToDraw(sprite, spriteModelMatrix, viewProjMatrix);
    }
}

void SpriteRenderer::RenderSysytem::PostUpdate(float dt)
{
}

void SpriteRenderer::RenderSysytem::DestroySystem()
{
}

const glm::mat4 SpriteRenderer::RenderSysytem::CalculateModelMatrix(const Transform& spriteTransform)
{
    glm::mat4 result(1);
    result = glm::translate(result, glm::vec3(spriteTransform.m_Position, 0));

    result = glm::rotate(result, spriteTransform.m_Rotate.x, glm::vec3(1.0f, 0, 0));
    result = glm::rotate(result, spriteTransform.m_Rotate.y, glm::vec3(0, 1.0f, 0));

    result = glm::scale(result, glm::vec3(MetricHelper::GetUnitInMeters(spriteTransform.m_Scale.x),
        MetricHelper::GetUnitInMeters(spriteTransform.m_Scale.y), 0));
    return result;
}

const glm::mat4 SpriteRenderer::RenderSysytem::CalculateViewMatrix(const Transform& cameraTransform)
{
    glm::mat4 result(1);
    glm::vec3 DirVec = glm::vec3(0) - glm::vec3(cameraTransform.m_Position, 0.1);
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
    result = glm::lookAt(glm::vec3(cameraTransform.m_Position, .1), glm::vec3(cameraTransform.m_Position, 0), tempUp);
    return result;
}