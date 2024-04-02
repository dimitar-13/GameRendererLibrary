#pragma once
#include"Rendererpch.h"
#include"Components/Transoform.h"
#include"Components/Sprite.h"
#include"VertexArray.h"
namespace SpriteRenderer {
	class ShaderProgram;

#pragma region Helper structs
	static constexpr uint32_t MAX_OBJECT_CCOUNT_PER_BATCH = 100;
	//Struct representing batch renderer batch data.
	template<typename T>
	struct BatchData {
		//Vertex array used to draw the batch.
		VertexArray batchVertexArray = {};
		//Limit for the batch data.
		const uint32_t MaxObjectCount = MAX_OBJECT_CCOUNT_PER_BATCH;
		//Count of the objects in the current batch.
		uint32_t objectCount = 0;
		//Used for index drawing.
		uint32_t indexCount = 0;
		//Offset of vertex data of type 'T' in bytes.
		uint32_t dataOffsetInBytes = {};
		//Pointer to the last element of the data.
		T* dataPointer = nullptr;
		//Batch data.
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
#pragma endregion

	//Batch renderer for sprite rendering.
	class Renderer
	{
	public:
		Renderer();
		~Renderer();
		static void EnableDepthTest() { glEnable(GL_DEPTH_TEST); }
		static void DisableDepthTest() { glDisable(GL_DEPTH_TEST); }
		static void Clear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }
		//Resets the pointer to the first element and the count.
		void BeginBatch();
		//Draws all the batches.
		void DrawBatches(const glm::mat4& viewProjMatrix);
		void EndBatch();

		void SubmitToDraw(Sprite* spriteToDraw,
			const glm::mat4& modelMatrix);
	private:
		/// <summary>
		/// Obsolete function might be removed.
		/// </summary>
		/// <param name="vertexArray"></param>
		static void IndexedDraw(const VertexArray& vertexArray);
		/// <summary>
		/// Obsolete function might be removed.
		/// </summary>
		/// <param name="vertexArray"></param>
		static void ArrayDraw(const VertexArray& vertexArray);
		//Generates an index array to be used for the batch data.
		void GenIndexBatchData();
		//Sets up the vertex arrays and allocate space for the batch data.
		void SetupBatchData();
		//Draws the circle batch.
		void DrawCircleBatch(const glm::mat4& viewProjMatrix);
		//Draws the square batch.
		void DrawSquareBatch(const glm::mat4& viewProjMatrix);
		//Creates a vertex circle data and adds it to the circle batch.
		void AppendToCircleBatch(Sprite* spriteToDraw,
			const glm::mat4& modelMatrix);
		//Creates a vertex square data and adds it to the square batch.
		void AppendToSquareBatch(Sprite* spriteToDraw,
			const glm::mat4& modelMatrix);
		//Generates circle vertex data.
		std::array<CircleVertexData,4> GenCircleVertexArrayData(Sprite* spriteToDraw,
			const glm::mat4& modelMatrix);
		//Generates square vertex data.
		std::array<SquareVertexData,4> GenSquareVertexArrayData(Sprite* spriteToDraw,
			const glm::mat4& modelMatrix);
	private:
		ShaderProgram* m_SquareShader = nullptr;
		ShaderProgram* m_CircleShader = nullptr;

		BatchData<CircleVertexData> m_CircleBatchData;
		BatchData<SquareVertexData> m_SquareBatchData;
	};
}

