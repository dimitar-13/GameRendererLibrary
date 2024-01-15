#include "Renderer.h"
#include"../Shader/ShaderProgram/ShaderProgram.h"
#include"../Shader/ShadersContianer/Shaders.h"
#include<iostream>


Renderer::Renderer()
{
    this->mainShader = new ShaderProgram("../Renderer/Assets/Shaders/Color_shader.glsl");
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

