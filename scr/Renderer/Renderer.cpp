#include "Renderer.h"

#include"../Shader/ShaderProgram/ShaderProgram.h"
#include"../Shader/ShadersContianer/Shaders.h"
#include"../../Core/Global.h"
#include"../../scr/GameObject/GameObject.h"
#include<iostream>


    void Renderer::StartRenderLoop()
    {


        Sprite sprite;
        ShaderProgram shader = ShaderProgram(VertexShader, FragmentShader);

        this->scripts[0]->OnStart();
        //this->scripts[1]->OnStart();

        
        //obj.scripts[0]->OnUpdate();



        while (!glfwWindowShouldClose(Global::winContext))
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(1, 0, 0, 1);
            this->scripts[0]->OnUpdate();

            //Render Scene objs
            //for (size_t i = 0; i < scripts.size(); i++)
            //{
            //    //sprites[i]->scriptComponents[0]->OnUpdate();
            //    shader.UseProgram();
            //    float test[] = { 1,2,0 };
            //    shader.SetUniform3Float("uColor", 1, 0, 1);
            //    sprites[i]->Draw(shader);
            //}


            glfwSwapBuffers(Global::winContext);
            glfwPollEvents();
        }

        glfwTerminate();
        glfwDestroyWindow(Global::winContext);
    }

    void Renderer::RenderOject()
    {

    }

    void Renderer::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER);
    }

    void Renderer::IndexedDraw(const VertexArray& vertexArray)
    {
    }

    void Renderer::ArrayDraw(const VertexArray& vertexArray)
    {
        vertexArray.BindArray();
        glDrawArrays(GL_TRIANGLES, 0, vertexArray.GetVertexCount());
        vertexArray.UnbindArray();
    }

