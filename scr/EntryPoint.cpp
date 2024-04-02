#include"Rendererpch.h"
#include"EntryPoint.h"
#include"Log.h"
#include"ECSManager.h"
#include"TextureUnitManager.h"
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

        glfwSetWindowSizeCallback(mainWin, EventCallbackFuncs::Resize);
        glfwSetKeyCallback(mainWin, EventCallbackFuncs::KeyCallback);
        glfwSetCursorPosCallback(mainWin, EventCallbackFuncs::MousePositionCallback);
        glfwSetMouseButtonCallback(mainWin, EventCallbackFuncs::MouseButtonCallback);
        glfwSetInputMode(mainWin, GLFW_STICKY_KEYS, GLFW_TRUE);

        Scene::Init();
    }
    void Terminate()
    {
       MainWindow::DeleteWindow();
       Scene::Terminate();
       //We call destroy for now because of a resource removeval race with the textrueUnitManager
       ECSManager::Destroy();
       TextureUnitManager::Destroy();

       RENDER_LOG_MESSAGE_SUCCESS("Renderer was succsessfully terminated.");
    }
}

