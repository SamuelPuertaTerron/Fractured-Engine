#include "frpch.h"
#include "SpriteRenderer.h"

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/quaternion.hpp"

#include "RenderManager.h"
#include "Fractured/Core/FEngine.h"

namespace FracturedInternal::Render
{
	SpriteRenderer::~SpriteRenderer()
	{
		glDeleteVertexArrays(1, &mVAO);
	}


	void SpriteRenderer::BuildShape()
	{
		float vertices[] = {
			// pos      // tex
			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,

			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f
		};

		glGenVertexArrays(1, &mVAO);
		glGenBuffers(1, &mVBO);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindVertexArray(mVAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void SpriteRenderer::RenderShape(Math::FVector2 position, Math::FVector3 rotation, Math::FVector2 scale, Texture texture)
	{
		//Camera

		glm::mat4 view = glm::mat4(1.0f);
		// note that we're translating the scene in the reverse direction of where we want to move
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -15.0f));
		glm::mat4 projection;
		projection = glm::perspective(glm::radians(45.0f), 1920.0f / 1080.0f, 0.1f, 100.0f);

		FEngine::GetInstance()->GetRenderer()->GetSpriteShader().SetMat4("projection", projection);
		FEngine::GetInstance()->GetRenderer()->GetSpriteShader().SetMat4("view", view);

		//--------------------------

		glm::mat4 trans = glm::translate(glm::mat4(1.0f), glm::vec3(position.x, position.y, 1.0f)) *
			glm::scale(glm::mat4(1.0f), glm::vec3(scale.x, scale.y, 0.0f));

		GLint mdelLoc = glGetUniformLocation(FEngine::GetInstance()->GetRenderer()->GetSpriteShader().GetId(), "model");
		glUniformMatrix4fv(mdelLoc, 1, GL_FALSE, glm::value_ptr(trans));

		unsigned int colourLoc = glGetUniformLocation(FEngine::GetInstance()->GetRenderer()->GetSpriteShader().GetId(), "ourColor");
		glUniform4f(colourLoc, 1.0f, 1.0f, 1.0f, 1.0f);

		texture.Bind();

		glBindVertexArray(mVAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
	}
}
