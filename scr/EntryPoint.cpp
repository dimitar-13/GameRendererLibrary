#include"Rendererpch.h"
#include"EntryPoint.h"
#include"Log/Log.h"
//TODO:__declspec(dllexport)
namespace SpriteRenderer {


    int Init()
    {
        glfwInit();
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

        RENDER_LOG_MESSAGE_INFO("Renderer initilizing.");
        RENDER_LOG_MESSAGE_INFO("Graphical API:'{0}'.", "OpenGL");
        RENDER_LOG_MESSAGE_INFO("Graphical API profile:'{0}'.", "Core");
        RENDER_LOG_MESSAGE_INFO("Graphical API version major:'{0}'.", 3);
        RENDER_LOG_MESSAGE_INFO("Graphical API version minor:'{0}'.", 3);

        Global::winContext = glfwCreateWindow(*Global::winWidth, *Global::winHeight, "My Title", NULL, NULL);
        if (!Global::winContext)
        {
            RENDER_LOG_MESSAGE_FATAL("GLFW failed to load.");
            glfwDestroyWindow(Global::winContext);
            glfwTerminate();
            return -1;
        }
        RENDER_LOG_MESSAGE_INFO("GLFW window was created successfully.");
        RENDER_LOG_MESSAGE_INFO("Window name:'{0}', width:'{1}', height:'{2}'.", "My Title", *Global::winWidth, *Global::winHeight);


        glfwMakeContextCurrent(Global::winContext);
        if (glewInit() != GLEW_OK)
        {
            RENDER_LOG_MESSAGE_FATAL("GLEW failed to load.");
            glfwDestroyWindow(Global::winContext);
            glfwTerminate();
            return -1;
        }
        RENDER_LOG_MESSAGE_INFO("GLEW was initialized successfully.");

        glewExperimental = GL_TRUE;
        glViewport(0, 0, *Global::winWidth, *Global::winHeight);

        //For now object will be defined in the range from -winWidth/2 to winWidth/2 ,-winHeight/2 to winHeight/2
        //I might change it to be from 0 to winWidth and so on but for now because its ez to use the model matrix will keep it like this 
        //if it show problems with the sprites and pixels will change it to screenspace ortho matrix
        *Global::projection = glm::ortho<float>(-*Global::winWidth / 2, *Global::winWidth / 2, -*Global::winHeight / 2, *Global::winHeight / 2, -1.0, 1.0);

        glfwSetWindowSizeCallback(Global::winContext, Resize);
        glfwSetKeyCallback(Global::winContext, key_callback);
        glfwSetCursorPosCallback(Global::winContext, mouse_position_callback);
        glfwSetMouseButtonCallback(Global::winContext, MouseCallback);
        glfwSetInputMode(Global::winContext, GLFW_STICKY_KEYS, GLFW_TRUE);
        mainSceneManager = new SceneManager();
    }
    void Terminate()
    {
       glfwDestroyWindow(Global::winContext);
       glfwTerminate();
       delete(mainSceneManager);
       RENDER_LOG_MESSAGE_INFO("Renderer was succsessfully terminated.");
    }
}

