#include "Rendererpch.h"
#include "RenderSytstem.h"
#include "ECS/ECSManager.h"
#include "Scene/Scene.h"
#include "Metric/MetricHelper.h"
#include "GameObject/GameObject.h"

void SpriteRenderer::RenderSystem::Init()
{
    m_entities = ECSManager::GetComponentEntities<Sprite>();
    auto onCompArrayChanged = std::bind(&RenderSystem::OnComponentArrayChanged, this);
    //void(*listener)() = &(this->*OnComponentArrayChanged)();
    ECSManager::AddEventListenerOnComponentArrayChange<Sprite>(onCompArrayChanged);
}

void SpriteRenderer::RenderSystem::PreUpdate(float dt)
{
    m_entities = ECSManager::GetComponentEntities<Sprite>();
}

void SpriteRenderer::RenderSystem::Update(float dt)
{
    OrthographicCamera* cameraEntity = Scene::GetActiveCamera();
    Transform* cameraTransform = cameraEntity->GetGameObject()->GetComponent<Transform>();
    glm::mat4 viewProjMatrix = cameraEntity->GetProjectionMatrix() * CalculateViewMatrix(*cameraTransform);
    m_renderer.BeginBatch();
    for (uint32_t i = 0; i < m_entities.size(); i++)
    {
        Transform* transform = ECSManager::GetComponent<Transform>(m_entities[i]);
        Sprite* sprite = ECSManager::GetComponent<Sprite>(m_entities[i]);   
        glm::mat4 spriteModelMatrix = CalculateModelMatrix(*transform);
      
        m_renderer.SubmitToDraw(sprite, spriteModelMatrix);
    }
    glm::mat4 test(1);
    m_renderer.DrawBatches(viewProjMatrix);
}

void SpriteRenderer::RenderSystem::PostUpdate(float dt)
{
}

void SpriteRenderer::RenderSystem::DestroySystem()
{
}

void SpriteRenderer::RenderSystem::OnComponentArrayChanged()
{
    m_entities = ECSManager::GetComponentEntities<Sprite>();

}

glm::mat4 SpriteRenderer::RenderSystem::CalculateModelMatrix(const Transform& spriteTransform)
{
    glm::mat4 result(1);
    result = glm::translate(result, glm::vec3(spriteTransform.m_Position, 0));

    result = glm::rotate(result, glm::radians(spriteTransform.m_RotationAngle), glm::vec3(0.0, 0, 1.0f));
    //result = glm::rotate(result, spriteTransform.m_Rotate.y, glm::vec3(0, 1.0f, 0));

    result = glm::scale(result, glm::vec3(MetricHelper::GetUnitInMeters(spriteTransform.m_Scale.x),
        MetricHelper::GetUnitInMeters(spriteTransform.m_Scale.y), 0));
    return result;
}

glm::mat4 SpriteRenderer::RenderSystem::CalculateViewMatrix(const Transform& cameraTransform)
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
    result[2][3] = -0.1f;
    result = glm::mat4(1);
    //The target vector must have the same position as the camera exept the z so the camera doesnt
    //move on z and stays paralel to the x axie.
    result = glm::lookAt(glm::vec3(cameraTransform.m_Position, .1), glm::vec3(cameraTransform.m_Position, 0), tempUp);
    return result;
}