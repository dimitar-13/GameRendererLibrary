#include"Rendererpch.h"
#include <RendererEngine_s.h>
#include"GameScripts/ExampleScript.h"
int main()
{
    using namespace SpriteRenderer;
    Init();

    ECSManager::GetComponentManager().RegisterComponentTypes<Sprite,
                                                           ScriptComponent,
                                                           Transform,
                                                           PhysicBody,
                                                           OrthographicCamera,
                                                           ColliderComponent,TagComponent>();
    GameObject cameraObj;
    auto* camera = cameraObj.AttachComponent<OrthographicCamera>();
    
    //Create game object.
    GameObject gameObj;

    //Gets the component.
    auto* gameObjTransform = gameObj.GetComponent<Transfrom>();
      
    //Attaches the example script.
    gameObj.AttachComponent<ScriptComponent>()->AttachScript<ExampleScript>();

    Scene::Start();
    SpriteRenderer::Terminate();

}