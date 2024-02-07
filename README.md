A 2D game engine rendering library for creating non profesional games.
It was created as a challange to myself to try to create such library so far it supports input polling, entity component system, sprites/textures. 
It is only supported on windows devices and for now can be only linked staticly.

# Dependencies
The project depends on 5 libraries GLFW,GLEW,GLM, fmt and stb image
# Initialization
First the SpriteRenderer must be initlized using the init function. After the init call the client/user can define the objects that will be on the scene as like in other engines that are with GUI before the runtime of the program the user can dfine some game objects and attach the needed components.
After that to start the rendering loop client/user calls the function 'Start'.
```c++
    SpriteRenderer::Init();
    GameObject obj2("Object2");
    auto* script2 = obj2.AttachComponent<Player2>();
    auto* sprite2 = obj2.AttachComponent<Sprite>();
    sprite2->SetTexture("../Renderer/Assets/Textures/Apple.png");
    script2->scriptName = "Well this is script instace 2";
    script2->InitialPosition = glm::vec3(0, 0, 0);
    script2->speed = 50;
    SceneManager::Start();
```
# ECS 
The entitiy component system is custom made and the client can interact with it like this:
```c++
    GameObject obj2("Object2");
    auto* script2 = obj2.AttachComponent<Player2>();
    auto* sprite2 = obj2.AttachComponent<Sprite>();
    sprite2->SetTexture("../Renderer/Assets/Textures/Apple.png");
    script2->scriptName = "Well this is script instace 2";
    script2->InitialPosition = glm::vec3(0, 0, 0);
    script2->speed = 50;
```
Because the renderer doesnt have GUI the way that it works is whenever the client/user attaches a component if it was successfull the library retrurns a handle/pointer to the component and the user can use it to 
set the values of the component properties.

# Scripting
For now the renderer supports native c++ scripting with virtual functions the client/user can define a class that inherits from 'ScriptableObject' and override the onUpdate,onDelete and onStart functions.
The script itself gets instanciated when the user attaches it to the program and later it gets bind with the gameObject when the program starts.
