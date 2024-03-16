#pragma once
#include"Rendererpch.h"
#include"Transform/Transoform.h"
#include "Sprite/Sprite.h"
namespace SpriteRenderer {
	class ShaderProgram;
	static const uint32_t MAX_OBJECT_CCOUNT_PER_BATCH = 100;

	template<typename T>
	struct BatchData {
		VertexArray batchVertexArray;
		const uint32_t MaxObjectCount = MAX_OBJECT_CCOUNT_PER_BATCH;
		uint32_t objectCount = 0;
		uint32_t indexCount = 0;
		uint32_t dataOffsetInBytes;
		T* dataPointer = nullptr;
		T* data = nullptr;
	};
	struct CircleVertexData {
		glm::vec2 originalPosition;
		glm::vec2 worldPosition;
		glm::vec3 color;
	};

	struct SquareVertexData {
		glm::vec2 worldPosition;
		glm::vec3 color;
		glm::vec2 uvCoords;
		float textureID = 0;
	};
	class Renderer
	{
	public:
		Renderer();
		~Renderer();
		static void EnableDepthTest() { glEnable(GL_DEPTH_TEST); }
		static void DisableDepthTest() { glDisable(GL_DEPTH_TEST); }
		static void Clear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }
		void BeginBatch();
		void DrawBatch(const glm::mat4& viewProjMatrix);
		void EndBatch();

		void SubmitToDraw(Sprite* spriteToDraw,
			const glm::mat4& modelMatrix);
	private:
		static void IndexedDraw(const VertexArray& vertexArray);
		static void ArrayDraw(const VertexArray& vertexArray);
		void GenIndexBatchData();
		void SetupBatchData();
		void DrawCircleBatch(const glm::mat4& viewProjMatrix);
		void DrawSquareBatch(const glm::mat4& viewProjMatrix);
		void DrawSprite(const glm::mat4& viewProjMatrix);

		void AppendToCircleBatch(Sprite* spriteToDraw,
			const glm::mat4& modelMatrix);

		void AppendToSquareBatch(Sprite* spriteToDraw,
			const glm::mat4& modelMatrix);

		std::array<CircleVertexData,4> GenCircleVertexArrayData(Sprite* spriteToDraw,
			const glm::mat4& modelMatrix);

		std::array<SquareVertexData,4> GenSqaureVertexArrayData(Sprite* spriteToDraw,
			const glm::mat4& modelMatrix);
	private:
		ShaderProgram* m_CustomShader = nullptr;
		ShaderProgram* m_SquareShader = nullptr;
		ShaderProgram* m_CircleShader = nullptr;

		BatchData<CircleVertexData> m_CircleBatchData;
		BatchData<SquareVertexData> m_SquareBatchData;
	};
}

