#include"Rendererpch.h"
#include <RendererEngine_s.h>
#include"GameLogic/Player2Script/Player2.h"
using namespace SpriteRenderer;
int main()
{

    SpriteRenderer::Init();

    std::string test2();

    ECSManager::GetComponentManager().RegisterComponentTypes<Sprite,
                                                           ScriptComponent,
                                                           Transform,
                                                           PhysicBody,
                                                           OrthographicCamera,
                                                           ColliderComponent,TagComponent>();
    //ECSManager::RegisterSystem<CustomSystem>();
    {
        GameObject cameraObj;
        auto* camera = cameraObj.AttachComponent<OrthographicCamera>();

        Texture2D snakeTexture("SnakeSprite.png");

        Texture2D textureApple("Applepng.png");

        GameObject snake;

        GameObject apple;

        auto* appleSprite = apple.AttachComponent<Sprite>();
        appleSprite->SetTexture(textureApple);
        auto* applecollider = apple.AttachComponent<ColliderComponent>();
        applecollider->SetColliderType<SquareCollider>();
        applecollider->attachedCollider->m_isTrigger = true;

        apple.AttachComponent<TagComponent>()->tag = "AppleTag";

        auto* snakeSprite = snake.AttachComponent<Sprite>();
        snakeSprite->SetTexture(snakeTexture);
        auto* snakeCollider = snake.AttachComponent<ColliderComponent>();
        snakeCollider->SetColliderType<SquareCollider>();
        snakeCollider->attachedCollider->m_isTrigger = true;

        auto*scriptComponent = snake.AttachComponent<ScriptComponent>();
        auto movementScript = scriptComponent->AttachScript<Player2>();

        movementScript->speed = 500.0f;

        Scene::SetActiveCamera(camera);
        
    }
    Scene::Start();
    SpriteRenderer::Terminate();

}