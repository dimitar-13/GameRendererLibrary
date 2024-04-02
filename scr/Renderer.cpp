#include"Rendererpch.h"
#include"ECSManager.h"
#include "Renderer.h"
#include"Scene.h"
#include"/ShaderProgram.h"
#include"MetricHelper.h"
#include"../Assets/AssetPath.h"

#pragma region Static data
static constexpr const uint32_t INDEX_PER_OBJECT = 6;
static const uint32_t INDEX_ARRAYCOUNT = INDEX_PER_OBJECT * SpriteRenderer::MAX_OBJECT_CCOUNT_PER_BATCH * 2;
static std::array<uint32_t, INDEX_ARRAYCOUNT> indexData;
static uint32_t indexBufferHandle;
#pragma endregion


SpriteRenderer::Renderer::Renderer()
{
   
    m_CircleShader = new ShaderProgram(AssetPathHelper::GetAssetPath() + "/Shaders/Circle_shader.glsl");
    m_CircleShader->UseProgram();
    m_CircleShader->GetShaderUniformLocation("ViewProjectionMatrix");

    m_SquareShader = new ShaderProgram(AssetPathHelper::GetAssetPath() + "/Shaders/Square_shader.glsl");
    m_SquareShader->UseProgram();
    m_SquareShader->GetShaderUniformLocation("ViewProjectionMatrix");
    m_SquareShader->GetShaderUniformLocation("samplers");

    GenIndexBatchData();
    SetupBatchData();
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
    delete[](m_SquareBatchData.data);
    delete[](m_CircleBatchData.data);
    RENDER_LOG_MESSAGE_SUCCESS("Batch renderer was deleted successfully.");
}

void SpriteRenderer::Renderer::GenIndexBatchData()
{
    uint32_t indexSetCounter = 0;
    for (uint32_t i = 0; indexSetCounter < SpriteRenderer::MAX_OBJECT_CCOUNT_PER_BATCH*2; i+=4)
    {
        uint32_t indexStartVal = i;
        uint32_t firstVal = indexStartVal;
        indexData[indexSetCounter] = indexStartVal;
        indexData[++indexSetCounter] = ++indexStartVal;
        indexData[++indexSetCounter] = ++indexStartVal;
        indexData[++indexSetCounter] = indexStartVal;
        indexData[++indexSetCounter] = ++indexStartVal;
        indexData[++indexSetCounter] = firstVal;
        ++indexSetCounter;
    }

    glGenBuffers(1, &indexBufferHandle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferHandle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexData), indexData.data(),
        GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void SpriteRenderer::Renderer::SetupBatchData()
{
    const std::vector<AttributeData> CircleAttribLayout{
      {0,2,GL_FLOAT,sizeof(CircleVertexData),offsetof(CircleVertexData, originalPosition)},
      {1,2,GL_FLOAT,sizeof(CircleVertexData),offsetof(CircleVertexData, worldPosition)},
      {2,3,GL_FLOAT,sizeof(CircleVertexData),offsetof(CircleVertexData, color)},};

    this->m_CircleBatchData.batchVertexArray.CreateVertexArray(CircleAttribLayout);

    this->m_CircleBatchData.dataOffsetInBytes = sizeof(CircleVertexData) * 4;

    this->m_CircleBatchData.batchVertexArray.BindBufferToVertexArray(indexBufferHandle,
        GL_ELEMENT_ARRAY_BUFFER);

    this->m_CircleBatchData.batchVertexArray.GenerateAndBindBufferToVertexArray(GL_ARRAY_BUFFER,
        this->m_CircleBatchData.dataOffsetInBytes * MAX_OBJECT_CCOUNT_PER_BATCH, nullptr, GL_DYNAMIC_DRAW);

    this->m_CircleBatchData.data = new CircleVertexData[m_CircleBatchData.MaxObjectCount];


    const std::vector<AttributeData> SquareAttribLayout{
      {0,2,GL_FLOAT,sizeof(SquareVertexData),offsetof(SquareVertexData, worldPosition)},
      {1,3,GL_FLOAT,sizeof(SquareVertexData),offsetof(SquareVertexData, color)},
      {2,2,GL_FLOAT,sizeof(SquareVertexData),offsetof(SquareVertexData,uvCoords)},
      {3,1,GL_FLOAT,sizeof(SquareVertexData),offsetof(SquareVertexData,textureID)}};

    this->m_SquareBatchData.batchVertexArray.CreateVertexArray(SquareAttribLayout);

    this->m_SquareBatchData.dataOffsetInBytes = sizeof(SquareVertexData) * 4;

    this->m_SquareBatchData.batchVertexArray.BindBufferToVertexArray(indexBufferHandle,
        GL_ELEMENT_ARRAY_BUFFER);
    this->m_SquareBatchData.batchVertexArray.GenerateAndBindBufferToVertexArray(GL_ARRAY_BUFFER,
        this->m_SquareBatchData.dataOffsetInBytes * MAX_OBJECT_CCOUNT_PER_BATCH,nullptr,GL_DYNAMIC_DRAW);

    this->m_SquareBatchData.data = new SquareVertexData[m_SquareBatchData.MaxObjectCount];

}

void SpriteRenderer::Renderer::BeginBatch()
{
    this->m_SquareBatchData.dataPointer = m_SquareBatchData.data;
    this->m_SquareBatchData.objectCount = 0;
    this->m_SquareBatchData.indexCount = 0;

    this->m_CircleBatchData.dataPointer = m_CircleBatchData.data;
    this->m_CircleBatchData.objectCount = 0;
    this->m_CircleBatchData.indexCount = 0;

}

void SpriteRenderer::Renderer::SubmitToDraw(Sprite* spriteToDraw, const glm::mat4& modelMatrix)
{
    switch (spriteToDraw->m_shapeType)
    {
    case SPRITE_SHAPE_TYPE_CUBE:
        AppendToSquareBatch(spriteToDraw, modelMatrix);
        break;
    case SPRITE_SHAPE_TYPE_CIRCLE:
        AppendToCircleBatch(spriteToDraw,modelMatrix);
        break;

    }
}

void SpriteRenderer::Renderer::DrawBatches(const glm::mat4& viewProjMatrix)
{
    DrawSquareBatch(viewProjMatrix);
    DrawCircleBatch(viewProjMatrix);
}

void SpriteRenderer::Renderer::EndBatch()
{

}

void SpriteRenderer::Renderer::DrawCircleBatch(const glm::mat4& viewProjMatrix)
{
    this->m_CircleBatchData.batchVertexArray.SendBufferSubData(GL_ARRAY_BUFFER,0,
        this->m_CircleBatchData.dataOffsetInBytes * this->m_CircleBatchData.objectCount,
        &this->m_CircleBatchData.data[0]);

    this->m_CircleShader->UseProgram();
    this->m_CircleShader->SetUniform4x4Matrix("ViewProjectionMatrix", viewProjMatrix);
    this->m_CircleBatchData.batchVertexArray.BindArray();

    glDrawElements(GL_TRIANGLES, this->m_CircleBatchData.indexCount, GL_UNSIGNED_INT, nullptr);
    this->m_CircleBatchData.batchVertexArray.UnbindArray();
}

void SpriteRenderer::Renderer::DrawSquareBatch(const glm::mat4& viewProjMatrix)
{
    this->m_SquareBatchData.batchVertexArray.SendBufferSubData(GL_ARRAY_BUFFER,0,
        this->m_SquareBatchData.dataOffsetInBytes * this->m_SquareBatchData.objectCount,
        &this->m_SquareBatchData.data[0]);

    this->m_SquareShader->UseProgram();

    this->m_SquareShader->SetUniform4x4Matrix("ViewProjectionMatrix", viewProjMatrix);
   
    auto& textureSlotsData = TextureUnitManager::GetTextureSlotData();
    this->m_SquareShader->SetUniformIntArray("samplers", textureSlotsData.size, textureSlotsData.m_textureUnitIndicies.data());
    this->m_SquareBatchData.batchVertexArray.BindArray();
    TextureUnitManager::BindTextures();

    glDrawElements(GL_TRIANGLES, this->m_SquareBatchData.indexCount, GL_UNSIGNED_INT, nullptr);
    this->m_SquareBatchData.batchVertexArray.UnbindArray();
}

void SpriteRenderer::Renderer::AppendToCircleBatch(Sprite* spriteToDraw, 
    const glm::mat4& modelMatrix)
{
    auto CircleVertexData = this->GenCircleVertexArrayData(spriteToDraw, modelMatrix);

    memcpy_s(this->m_CircleBatchData.dataPointer,
        sizeof(*this->m_CircleBatchData.data) * this->m_CircleBatchData.MaxObjectCount,
        CircleVertexData.data(),
        sizeof(CircleVertexData) * CircleVertexData.size());

    this->m_CircleBatchData.dataPointer += 4;
    this->m_CircleBatchData.objectCount++;
    this->m_CircleBatchData.indexCount+=6;

}

void SpriteRenderer::Renderer::AppendToSquareBatch(Sprite* spriteToDraw,
    const glm::mat4& modelMatrix)
{
    auto SquareVertexData = this->GenSquareVertexArrayData(spriteToDraw, modelMatrix);

    memcpy_s(m_SquareBatchData.dataPointer,
        sizeof(*m_SquareBatchData.data) * this->m_SquareBatchData.MaxObjectCount,
        SquareVertexData.data(),
        sizeof(SquareVertexData) * SquareVertexData.size());

    m_SquareBatchData.dataPointer += 4;
    this->m_SquareBatchData.objectCount++;
    this->m_SquareBatchData.indexCount += 6;

}

std::array<SpriteRenderer::CircleVertexData,4> SpriteRenderer::Renderer::GenCircleVertexArrayData(Sprite* spriteToDraw, const glm::mat4& modelMatrix)
{
    std::array<SpriteRenderer::CircleVertexData, 4> verts = {};
    const float ndcOffset = 0.5f;
    const glm::vec3 color = spriteToDraw->m_Color;

    verts[0] = { glm::vec2(-ndcOffset, -ndcOffset),
        modelMatrix * glm::vec4(-ndcOffset, -ndcOffset,0,1),
        color };

    verts[1] = { glm::vec2(-ndcOffset, ndcOffset),
        modelMatrix * glm::vec4(-ndcOffset, ndcOffset ,0,1),
        color };

    verts[2] = { glm::vec2(ndcOffset, ndcOffset),
        modelMatrix * glm::vec4(ndcOffset, ndcOffset ,0,1),
        color };

    verts[3] = { glm::vec2(ndcOffset, -ndcOffset),
        modelMatrix * glm::vec4(ndcOffset, -ndcOffset ,0,1),
        color };

    return verts;
}

std::array<SpriteRenderer::SquareVertexData,4> SpriteRenderer::Renderer::GenSquareVertexArrayData(Sprite* spriteToDraw, const glm::mat4& modelMatrix)
{
    std::array<SpriteRenderer::SquareVertexData, 4> verts = {};

    const float ndcOffset = 0.5f;
    const glm::vec3 color = spriteToDraw->m_Color;
    const float textureID = static_cast<float>(TextureUnitManager::GetTextureIndex(spriteToDraw->textureIndex));
    verts[0] = {modelMatrix * glm::vec4(-ndcOffset, -ndcOffset,0,1),color,{0,0},textureID};
    verts[1] = {modelMatrix * glm::vec4(-ndcOffset, ndcOffset ,0,1),color,{0,1},textureID};
    verts[2] = {modelMatrix * glm::vec4(ndcOffset, ndcOffset ,0,1),color,{1,1},textureID};
    verts[3] = {modelMatrix * glm::vec4(ndcOffset, -ndcOffset ,0,1),color,{1,0},textureID};
    return verts;
}
