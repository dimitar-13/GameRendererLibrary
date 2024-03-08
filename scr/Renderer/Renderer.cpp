#include"Rendererpch.h"
#include"ECS/ECSManager.h"
#include "Renderer.h"
#include"SceneManager/SceneManager.h"
#include"Shader/ShaderProgram/ShaderProgram.h"
#include"Metric/MetricHelper.h"
SpriteRenderer::Renderer::Renderer()
{
    m_CustomShader = new ShaderProgram("../Renderer/Assets/Shaders/Color_shader.glsl");
    m_CustomShader->UseProgram();
    m_CustomShader->GetShaderUniformLocation("ModelMatrix");
    m_CustomShader->GetShaderUniformLocation("ViewProjectionMatrix");
    m_CustomShader->GetShaderUniformLocation("samplerTexture");
    m_CustomShader->GetShaderUniformLocation("uColor");

    m_CircleShader = new ShaderProgram("../Renderer/Assets/Shaders/Circle_shader.glsl");
    m_CircleShader->UseProgram();
    m_CircleShader->GetShaderUniformLocation("ModelMatrix");
    m_CircleShader->GetShaderUniformLocation("ViewProjectionMatrix");
    m_CircleShader->GetShaderUniformLocation("uColor");

    m_SquareShader = new ShaderProgram("../Renderer/Assets/Shaders/Square_shader.glsl");
    m_SquareShader->UseProgram();
    m_SquareShader->GetShaderUniformLocation("ModelMatrix");
    m_SquareShader->GetShaderUniformLocation("ViewProjectionMatrix");
    m_SquareShader->GetShaderUniformLocation("uColor");
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


SpriteRenderer::Renderer::~Renderer()
{
    delete(m_CircleShader);
    delete(m_SquareShader);
    delete(m_CustomShader);
}

void SpriteRenderer::Renderer::SubmitToDraw(Sprite* spriteToDraw, const glm::mat4& modelMatrix,
    const glm::mat4& viewProjMatrix)
{
    //Generate a vertexArray

    //Add vertex array to main array (SquareArray/CircleArray/SpriteArray)

    //Have a draw function that draws everything witha signle draw call and then clears the array


    switch (spriteToDraw->m_shapeType)
    {
    case SPRITE_SHAPE_TYPE_CUBE:
        this->DrawSquare(spriteToDraw, modelMatrix, viewProjMatrix);
        break;
    case SPRITE_SHAPE_TYPE_CIRCLE:
        this->DrawCircle(spriteToDraw, modelMatrix, viewProjMatrix);
        break;
    case SPRITE_SHAPE_TYPE_TRIANGLE:
        break;
    case SPRITE_SHAPE_TYPE_CUSTOM:
        this->DrawSprite(spriteToDraw, modelMatrix, viewProjMatrix);
        break;
    }
}

void SpriteRenderer::Renderer::DrawCircle(Sprite* spriteToDraw, const glm::mat4& modelMatrix
    ,const glm::mat4& viewProjMatrix)
{
    m_CircleShader->UseProgram();
    m_CircleShader->SetUniform4x4Matrix("ModelMatrix", modelMatrix);
    m_CircleShader->SetUniform4x4Matrix("ViewProjectionMatrix", viewProjMatrix);
    m_CircleShader->SetUniform3FloatVector("uColor", spriteToDraw->m_Color);
    ArrayDraw(*spriteToDraw->m_vertexArray);

}

void SpriteRenderer::Renderer::DrawSquare(Sprite* spriteToDraw, const glm::mat4& modelMatrix,
    const glm::mat4& viewProjMatrix)
{
    m_SquareShader->UseProgram();
    m_SquareShader->SetUniform4x4Matrix("ModelMatrix", modelMatrix);
    m_SquareShader->SetUniform4x4Matrix("ViewProjectionMatrix", viewProjMatrix);
    m_SquareShader->SetUniform3FloatVector("uColor", spriteToDraw->m_Color);
    ArrayDraw(*spriteToDraw->m_vertexArray);

}

void SpriteRenderer::Renderer::DrawSprite(Sprite* spriteToDraw, const glm::mat4& modelMatrix
, const glm::mat4& viewProjMatrix)
{
    m_CustomShader->UseProgram();
    //SetTextures
    ArrayDraw(*spriteToDraw->m_vertexArray);
}


