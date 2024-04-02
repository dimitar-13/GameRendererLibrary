# What is this renderer library?
This is a solo project of mine created for educational purposes.There are only 5 dependencies: [GLFW](https://github.com/glfw/glfw),
[GLM](https://github.com/g-truc/glm),
[GLEW](https://glew.sourceforge.net/),
[stb_image](https://github.com/nothings/stb/blob/master/stb_image.h),
[fmt](https://github.com/fmtlib/fmt).
In no way do I think this library can be used in profesional setting but it was a fun project that maybe took way too much that i would have liked.
In short this is a simple 2D rendering library.
* The end goal: The goal is to allow users to create games easily without worrying about graphics, ECS, and so on.
* Why is called like this: Well I didnt come up with a name so yeah.
* Features: So far the this project have the following features:  
  * Batch renderer.
  * Custom entity component system.
  * Collision/Trigger detection.
  * Physic simulation.
  * Input manager class for a way to check for inputs.
  * Native c++ scripting using virtual functions.
  * An intuative way to get/add components to game objects. 
# How to build.
It currently supports only windows.To build it you will need:
* cmake
* gitbash
First open the cmd in the folder you want to clone the repo and past this command:
```git
git clone https://github.com/dimitar-13/GameRendererLibrary.git --recursive
```
After its clonned go to the folder where the project is cloned and in the cmd run this:
```cmake
cmake -S . -B .
```
Lastly on visual studio set the Sandbox app as startup project and run.

# How it works ? 
Since there is no GUI, the usage is straightforward. You can create a game object, and it will remain active until the end of the program or until you explicitly delete it using the DeleteGameObject function. Every game object comes with a transform component by default. When you use methods like AttachComponent, it attaches a component and returns a handle/pointer for you to work with. You can remove components, and upon destroying a game object, the components that it holds will be deleted as well. The sandbox app is your lets say it "game world" in there you can have your scripts and so on.

# How to use ? 
You first need to initialize the library using the Init function. This function essentially initializes GLFW and other important features of the library. After that, you can specify your game objects, similar to how they are defined in a scene within a game engine. You also have to define your main camera, but this requirement will likely be removed in the future. Once you’ve defined all the game objects and attached the desired components, you can use Scene::Start to initiate the scene and the render pipeline. This will bind all the scripts you’ve attached and call the Start function. Currently, there is no function to stop the pipeline; the only way to do so is by closing the window. After closing the window, you can call Terminate to free all the resources used.
```c++
  SpriteRenderer::Init();

  std::string test2();

  ECSManager::GetComponentManager().RegisterComponentTypes<Sprite,
                                                         ScriptComponent,
                                                         Transform,
                                                         PhysicBody,
                                                         OrthographicCamera,
                                                         ColliderComponent,TagComponent>();
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

  auto* scriptComponent = snake.AttachComponent<ScriptComponent>();
  auto* movementScript = scriptComponent->AttachScript<Player2>();

  scriptComponent->entity = snake.GetEntity();
  movementScript->speed = 100.0f;

  Scene::SetActiveCamera(camera);
  Scene::Start();
  SpriteRenderer::Terminate();
```
*Note that there is an option for custom components and a way for you to say wich component you want to use this option might be removed i am not really sure of it for now.

## Native Scripting with virtual functions.
You can define your scripts as classes that inherit from the 'ScriptableObject' class. This class provides the GameObject, which is the game object attach to the script.
You can use the OnStart, OnUpdate, and OnDelete virtual functions to implement your script behavior. 
*Note: Each of these virtual functions is not pure, so you are not obligated to implement them.

Once you’ve completed your script, you can attach a ScriptComponent, which is a wrapper for your script,and attach your script class using 'AttachScript' method(this method instanciate your script and 
returns the pointer to it so you can work on it or set some script member variables).
```c++
void Player2::OnUpdate()
{
	auto* transform = this->gameObject.GetComponent<SpriteRenderer::Transform>();
	if (SpriteRenderer::InputManager::IsButtonPressed(SpriteRenderer::KEY_SPACE))
	{
		switch (this->direction)
		{
		case DOWN:
			this->direction = RIGHT;
			this->vecDir = glm::vec2(1, 0);
			transform->m_RotationAngle = 90.0f;
			break;
		case RIGHT:
			this->direction = UP;
			this->vecDir = glm::vec2(0, 1);
			transform->m_RotationAngle = -180.0f;
			break;
		case LEFT:
			this->direction = DOWN;
			this->vecDir = glm::vec2(0, -1);
			transform->m_RotationAngle = 0.0f;
			break;
		case UP:
			this->direction = LEFT;
			this->vecDir = glm::vec2(-1, 0);
			transform->m_RotationAngle = -90.0f;
			break;
		}
	}

	transform->Translate(this->vecDir * speed * SpriteRenderer::Scene::delta.GetTimeInSeconds());

}
void Player2::OnDelete()
{
	std::cout << "Component was deleted" << '\n';
}
```
*Note:Enumrators, used in this example, are custom defined and are not part of the library.
Example of attaching a script:
```c++
    auto* scriptComponent = snake.AttachComponent<ScriptComponent>();
    auto* movementScript = scriptComponent->AttachScript<Player2>();
```
# Custom ECS 
## First attempts to make the ECS.
When I first heard of ECS I wanted to try to implement it myself so ,like the most sane person, I just placed randomly in a class and called it a day.
Now to be more clear my initial approach was for each component to make a unorderer map of entity compoennt and using templated functions to add or remove components.Now the problem with this was that
the ways of determining wich hash map to use was not really readable and often because of my bad code placement i was not really able to use this code anywhere without getting circular dependencies.
## Second attemp at it.
At some point the code was really unworkable and I wanted to change that so I searched in the internet for some answers I came across [this post](https://austinmorlan.com/posts/entity_component_system/).
Now the post itself did give me a lot of ideas and my final ECS is really inspired by it.But the new design is that instead placing everything in the scene class and calling it a day I seperated
every component of the ECS in its own class and manager class.

## How does the ECS work ?
Here I will try to explain it breefly but for more details you can check  [this post](https://austinmorlan.com/posts/entity_component_system/) since my ECS is heavily based of it.
The user uses singelton class 'ECSManager' to communicate with the entity component system the singelton class holds 3 objects that are the ComponentManager,SystemManager and EntityManager.
* ComponentManager - Manages all of the component arrays.
  * ComponentArray - Templated class that manages the lifetime and creation of components of type T.
* SystemManager - Holds every system instance and its responsable for systems lifetime.
  * System - Templated class that is responsible for some task like: drawing to the screen,updating physics etc.
* EntityManager - Manages all of the avaiable entity IDs.
Most of the times direct need to use ECSManager wont be needed because 'GameObject' class is a wrapper for Entity and the calss to the ECSManager.

## Featrues of the ECS
The ECS can be used for a user to specify their own custom components with only rule that the component must inherit from Component base class.Like the components user can specify a custom system
that will work with certain components.The project provides some initial components like Transform,Sprite and so on with their respective systems.

# Custom physic simulation and collision detection
## Physics
The physics simulation have 2 main parts the physics body component and the physic system.
The physics body keeps track of position,velocity,total force, and acceleration.The physic system uses this information to calculate the new position using Newton acceleration formula.
## Collision
The collision classes and collision detection design are based from [this video](https://www.youtube.com/watch?v=-_IspRG548E&t=209s&ab_channel=Winterdev).

# Things that are not added and most likely wont be
* Custom shader support.
* Frame buffer customizer for cool effect.
* Sprite attlas support.
* Better collision detection.
* System dependencies.
* Text rendering.
* Scene graph.
* Use of multithreading systems.
* Differend systems.
