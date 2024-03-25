# What is this renderer library?
This is a solo project of mine created for educational purposes.There are only 5 dependencies: [GLFW](https://github.com/glfw/glfw),
[GLM](https://github.com/g-truc/glm),
[GLEW](https://glew.sourceforge.net/),
[stb_image](https://github.com/nothings/stb/blob/master/stb_image.h),
[fmt](https://github.com/fmtlib/fmt).
In no way do I think this library can be used in profesional setting but it was a fun project that maybe took way too much that i would have liked. 
So far the this project have the following features:
* Batch renderer.
* Custom entity component system.
* Collision/Trigger detection.
* Physic simulation.
* Input manager class for a way to check for inputs.
* Native c++ scripting using virtual functions.
* An intuative way to get/add components to game objects. 

# How it works ? 
Since there is no GUI the way you use it is simple.You can create a game object and your game object will be alive until the end of the program or until you dont use the 'DeleteGameObject' function.
Every game object comes with a transform component by default.When you use AttachComponent it attaches component and returns you a handle/pointer to work on it.You can remove component and when you do
your component gets deleted from the heap.

# How to use ? 
You first need to intilize the lirbrary using Init function.This function basicly initilize glfw, and other importand features of the library. After that you can specify you game objects kinda like if you are in a game engine
and they are defined in the scene.You also have to define your main camera for now but this will be most likely removed. After you've defined all of the game objects and attached the desired components you can 
use Scene::Start to start the scene and the render pipeline this will bind all the scripts that you've attached and call the Start function. As for now there is not function to Stop the pipeline so only way by 
closing the window.After closing the window you can call Terminate to free all resources used.Example:
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
You can define your scripts as classes that inherit from 'ScriptableObject' class.This class provide the 'GameObject' wich is a wrapper for calls to the ECSManager for stuff like attaching component and 
getting them. You can use the OnStart,OnUpdate and OnDelete virtual functions to implement your script behavior.*Note every one of thise virtual function is not pure so you are not forced to implement it.
When done with your script you can call 'ScriptComponent' wich is a wrapper for your Script it manages the lifetime of your script so you dont have to create object of you script.
Example of a custom script:
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
*Enumrators used in this example are custom defined and are not part of the library.
Example of attaching a script:
```c++
    auto* scriptComponent = snake.AttachComponent<ScriptComponent>();
    auto* movementScript = scriptComponent->AttachScript<Player2>();
```
# Custom ECS 
## First attempts to make the ECS.
When I first head of ECS I wanted to try to implement it myself so like the most sane person i just placed randomly in a class and called it a day.
Now to be more clear my initial approach was for each component to make a unordererMap of entity compoennt and using templated functions to add or remove components.Now the problem with this was that
the ways of determating wich hash map to use was not really readable and often because of my bad code placement i was not really able to use this code anywhere without getting circular dependencies.
## Second attemp at it.
At some point the code was really unworkable and I wanted to change that so I searched in the internet for some answers i came across [this post](https://austinmorlan.com/posts/entity_component_system/).
Now the post itself did give me a lot of ideas and my final ECS is really inspired by it.

## How does the ECS work ?
Here I will try to explain it breefly but for more details you can check  [this post](https://austinmorlan.com/posts/entity_component_system/) since my ECS is heavily based of it.
Every component have a ComponentArray class that is templated class that its responsible for managing the lifetime of all the components of that type.It have functions like Add,Remove and Get.
There is a component array manager class that manages all of our component arrays.

# Custom physic simulation

# Things that are not added and most likely wont be
* Custom shader support.
* Frame buffer customizer for cool effect.
* Sprite attlas support.
* Better collision detection.
* System dependencies.
* Text rendering.
