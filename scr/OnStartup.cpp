// Renderer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"Renderer/Renderer.h"
#include"../Core/Global.h"


int OnStartUp()
{
    glfwInit();

 

    Global::winContext = glfwCreateWindow(*Global::winWidth, *Global::winHeight, "My Title", NULL, NULL);
    if (!Global::winContext)
    {
        glfwTerminate();
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
    glViewport(0, 0, 1000, 1000);


    

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


