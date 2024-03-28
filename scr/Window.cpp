#include "Rendererpch.h"
#include "Window.h"
#include"log/Log.h"
void SpriteRenderer::MainWindow::createWindow(int width, int height)
{
    this->m_mainWinSize.winWidth = width;
    this->m_mainWinSize.winHeight = height;
    glfwInit();
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    RENDER_LOG_MESSAGE_INFO("Renderer initializing.");
    RENDER_LOG_MESSAGE_INFO("Graphical API:'{0}'.", "OpenGL");
    RENDER_LOG_MESSAGE_INFO("Graphical API profile:'{0}'.", "Core");
    RENDER_LOG_MESSAGE_INFO("Graphical API version major:'{0}'.", 3);
    RENDER_LOG_MESSAGE_INFO("Graphical API version minor:'{0}'.", 3);

   this->m_mainWindow = glfwCreateWindow(this->m_mainWinSize.winWidth, this->m_mainWinSize.winHeight, "My Title", NULL, NULL);
    if (!this->m_mainWindow)
    {
        RENDER_LOG_MESSAGE_FATAL("GLFW failed to create window.");
        glfwDestroyWindow(this->m_mainWindow);
        glfwTerminate();
    }
    else
    {
        RENDER_LOG_MESSAGE_INFO("GLFW window was created successfully.");
        RENDER_LOG_MESSAGE_INFO("Window name:'{0}', width:'{1}', height:'{2}'.", "My Title", this->m_mainWinSize.winWidth, this->m_mainWinSize.winHeight);

        glfwMakeContextCurrent(this->m_mainWindow);
    }
}

void SpriteRenderer::MainWindow::deleteWindow()
{
    glfwDestroyWindow(this->m_mainWindow);
    glfwTerminate();
}

