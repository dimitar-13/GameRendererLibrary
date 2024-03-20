#include"Rendererpch.h"
#include"EntryPoint.h"
#include"Log/Log.h"
#include"ECS/ECSManager.h"
#include"TextureClass/TextureUnitManager.h"
#include"Window.h"
//TODO:__declspec(dllexport)
namespace SpriteRenderer {

    int Init()
    {
        MainWindow::CreateWindow(1500, 800);

        if (glewInit() != GLEW_OK)
        {
            RENDER_LOG_MESSAGE_FATAL("GLEW failed to load.");
            MainWindow::DeleteWindow();
            glfwTerminate();
            return -1;
        }
        RENDER_LOG_MESSAGE_INFO("GLEW was initialized successfully.");

        glewExperimental = GL_TRUE;
        glViewport(0, 0, MainWindow::GetWindowSize().winWidth, MainWindow::GetWindowSize().winHeight);

        GLFWwindow* mainWin = MainWindow::GetGLFWWindow();
        //For now object will be defined in the range from -winWidth/2 to winWidth/2 ,-winHeight/2 to winHeight/2
        //I might change it to be from 0 to winWidth and so on but for now because its ez to use the model matrix will keep it like this 
        //if it show problems with the sprites and pixels will change it to screenspace ortho matrix
        glfwSetWindowSizeCallback(mainWin, EventCallbackFuncs::Resize);
        glfwSetKeyCallback(mainWin, EventCallbackFuncs::KeyCallback);
        glfwSetCursorPosCallback(mainWin, EventCallbackFuncs::MousePositionCallback);
        glfwSetMouseButtonCallback(mainWin, EventCallbackFuncs::MouseButtonCallback);
        glfwSetInputMode(mainWin, GLFW_STICKY_KEYS, GLFW_TRUE);

        SceneManager::Init();
    }
    void Terminate()
    {

       MainWindow::DeleteWindow();
       SceneManager::Terminate();
       ECSManager::DestroyECSManager();
       TextureUnitManager::Destroy();
       RENDER_LOG_MESSAGE_SUCCESS("Renderer was succsessfully terminated.");
    }
}

