#include "Renderer.h"
#include"Shader/ShaderProgram/ShaderProgram.h"
#include"Shader/ShadersContianer/Shaders.h"
#include<iostream>


SpriteRenderer::Renderer::Renderer()
{
    this->mainShader = new SpriteRenderer::ShaderProgram("../Renderer/Assets/Shaders/Color_shader.glsl");
}

void SpriteRenderer::Renderer::IndexedDraw(const VertexArray& vertexArray)
{
}

void SpriteRenderer::Renderer::ArrayDraw(const VertexArray& vertexArray)
{
    vertexArray.BindArray();
    glDrawArrays(GL_TRIANGLES, 0, vertexArray.GetVertexCount());
    vertexArray.UnbindArray();
}

