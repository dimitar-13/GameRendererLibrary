// Renderer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"SceneManager/SceneManager.h"
#include"../Core/Global.h"
#include"WindowFunctions/WindowFunctions.h"

inline SceneManager *  mainSceneManager;


int OnStartUp()
{
    glfwInit();

    Global::winContext = glfwCreateWindow(*Global::winWidth, *Global::winHeight, "My Title", NULL, NULL);
    if (!Global::winContext)
    {
        glfwTerminate();
        glfwDestroyWindow(Global::winContext);
        return -1;
    }
    glfwMakeContextCurrent(Global::winContext);
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        glfwDestroyWindow(Global::winContext);
        return -1;
    }
    glewExperimental = GL_TRUE;
    glViewport(0, 0, *Global::winWidth, *Global::winHeight);

 

    //For now object will be defined in the range from -winWidth/2 to winWidth/2 ,-winHeight/2 to winHeight/2
    //I might change it to be from 0 to winWidth and so on but for now because its ez to use the model matrix will keep it like this 
    //if it show problems with the sprites and pixels will change it to screenspace ortho matrix
    *Global::projection = glm::ortho<float>(-*Global::winWidth/2, *Global::winWidth/2, -*Global::winHeight/2, *Global::winHeight/2, -1.0, 1.0);

    glfwSetWindowSizeCallback(Global::winContext, Resize);
    mainSceneManager = new SceneManager();
   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


